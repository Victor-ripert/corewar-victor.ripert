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
    int len = my_strlen(arg) - 4;

    if (my_strncmp(DOT_CORE, arg + len, 4) == SUCCESS_VALUE) {
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
    if (lseek(fd, 2192, SEEK_SET) == FAIL_VALUE)
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

static void attribute_warrior_flags(sim_t *corewar)
{
    corewar->warriors[corewar->warriors_nb]->addres = corewar->load_address;
    corewar->warriors[corewar->warriors_nb]->prog_number = corewar->prog_nb;
    corewar->load_address = -1;
    corewar->prog_nb = -1;
    return;
}

bool get_warrior(char *pathname, sim_t *corewar, size_t *i)
{
    if (!is_a_cor(pathname)) {
        if (corewar->warriors != NULL) {
            free_warriors(corewar->warriors);
        }
        return false;
    }
    corewar->warriors = realloc(corewar->warriors,
    sizeof(warrior_t *) * (corewar->warriors_nb + 1));
    if (corewar->warriors == NULL) {
        return false;
    }
    if (!init_warrior(&corewar->warriors[corewar->warriors_nb], pathname)) {
        free_warriors(corewar->warriors);
        return false;
    }
    attribute_warrior_flags(corewar);
    corewar->warriors_nb += 1;
    *i = *i + 1;
    return true;
}
