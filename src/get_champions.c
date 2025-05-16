/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** get_champions
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <endian.h>

#include "my.h"
#include "macros.h"
#include "warrior.h"
#include "args.h"
#include "op.h"

static unsigned char *return_failure(int fd, unsigned char *buffer)
{
    free(buffer);
    close(fd);
    return NULL;
}

static bool is_a_cor(char *arg)
{
    int len = my_strlen(arg) - DOT_CORE_NB;

    if (my_strncmp(DOT_CORE, arg + len, DOT_CORE_NB) == SUCCESS_VALUE) {
        return true;
    }
    return false;
}

static bool get_struct(header_t *header, char *pathname)
{
    int fd = 0;

    fd = open(pathname, O_RDONLY);
    if (fd == FAIL_VALUE)
        return false;
    if (read(fd, header, sizeof(header_t)) == FAIL_VALUE
        || be32toh(header->magic) != COREWAR_EXEC_MAGIC) {
        close(fd);
        return false;
    }
    header->prog_size = swap_endian(header->prog_size);
    close(fd);
    return true;
}

static unsigned char *get_prog(int prog_size, char *pathname)
{
    int fd = open(pathname, O_RDONLY);
    unsigned char *buffer = NULL;
    ssize_t rv = 0;

    if (fd == FAIL_VALUE)
        return NULL;
    buffer = malloc(sizeof(unsigned char) * (prog_size + 1));
    if (buffer == NULL)
        return NULL;
    if (lseek(fd, OFFSET_POSITION, SEEK_SET) == FAIL_VALUE)
        return return_failure(fd, buffer);
    for (int i = 0; i < prog_size; ++i) {
        rv = read(fd, &buffer[i], sizeof(unsigned char));
        if (rv == FAIL_VALUE)
            return return_failure(fd, buffer);
    }
    close(fd);
    return buffer;
}

static bool init_warrior(warrior_t **warrior, char *pathname)
{
    warrior_t *new_warrior = malloc(sizeof(warrior_t));

    new_warrior->header = (header_t){0};
    if (new_warrior == NULL)
        return false;
    if (!get_struct(&new_warrior->header, pathname)) {
        free(new_warrior);
        return false;
    }
    new_warrior->prog = get_prog(new_warrior->header.prog_size, pathname);
    if (new_warrior->prog == NULL) {
        free(new_warrior);
        return false;
    }
    *warrior = new_warrior;
    return true;
}

static bool assigne_proc_nbr(sim_t *corewar, ssize_t prog_nbr)
{
    for (int i = 0; corewar->warriors[i] != NULL; ++i) {
        if (prog_nbr == corewar->warriors[i]->prog_number) {
            return assigne_proc_nbr(corewar, prog_nbr + 1);
        }
    }
    corewar->warriors[corewar->warriors_nb]->prog_number = prog_nbr;
    return true;
}

static void assigne_warrior_flags(sim_t *corewar)
{
    corewar->warriors[corewar->warriors_nb]->addres = corewar->load_address;
    if (corewar->prog_nb == UNINITIALIZED_PROG_NB) {
        corewar->prog_nb = corewar->warriors_nb;
    }
    assigne_proc_nbr(corewar, corewar->prog_nb);
    corewar->load_address = UNINITIALIZED_ADRESS;
    corewar->prog_nb = UNINITIALIZED_PROG_NB;
    return;
}

bool get_warrior(char *pathname, sim_t *corewar, size_t *i)
{
    if (!is_a_cor(pathname)) {
        if (corewar->warriors != NULL)
            free_warriors(corewar->warriors);
        return false;
    }
    corewar->warriors = realloc(corewar->warriors,
        sizeof(warrior_t *) * (corewar->warriors_nb + 2));
        if (corewar->warriors == NULL)
            return false;
        corewar->warriors[corewar->warriors_nb + 1] = NULL;
        if (!init_warrior(&corewar->warriors[corewar->warriors_nb],
            pathname)) {
            free_warriors(corewar->warriors);
            return false;
        }
    assigne_warrior_flags(corewar);
    corewar->warriors_nb += 1;
    *i = *i + 1;
    return true;
}
