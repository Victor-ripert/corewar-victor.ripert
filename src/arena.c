/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** arena
*/

#include <stdlib.h>
#include <stdbool.h>
#include "macros.h"
#include "warrior.h"
#include "my.h"
#include "args.h"
#include "op.h"

void print_map(char *arena)
{
    for (int i = 0; i < MEM_SIZE; i += 2) {
        my_putchar(arena[i]);
        my_putchar(' ');
    }
    return;
}

static void put_at_adress(char **arena, warrior_t **warriors, int index)
{
    char *tmp = *arena;

    for (int i = 0; warriors[index]->prog[i] != '\0'; ++i) {
        tmp[warriors[index]->addres + i] = warriors[index]->prog[i];
    }
    *arena = tmp;
}

static size_t get_warrior_size(warrior_t **warriors)
{
    size_t size = 0;

    for (int i = 0; warriors[i] != NULL; ++i) {
        size += strlen(warriors[i]->header.prog_size);
    }
    return size;
}

bool put_in_arena(char **arena, warrior_t **warriors)
{
    char new_arena[MEM_SIZE] = {0};

    for (int i = 0; warriors[i] != NULL; ++i) {
        put_at_adress(&new_arena, warriors, i);
    }
    *arena = new_arena;
    return true;
}

void assign_adress(warrior_t **warriors, size_t warriors_nb)
{
    size_t spaces = MEM_SIZE / warriors_nb;
    size_t current = 0;
    size_t remain = warriors_nb;
    size_t warriors_size = get_warrior_size(warriors);

    if (warriors_size > MEM_SIZE)
        return false;
    for (int i = 0; warriors[i] != NULL; ++i) {
        if (warriors[i]->addres != -1) {
            --remain;
        }
    }
    spaces = (MEM_SIZE % IDX_MOD - warriors_size) / remain;
    for (int i = 0; warriors[i] != NULL; ++i) {
        if (warriors[i] == -1) {
            warriors[i]->addres = current;
            current += current;
        }
    }
    return;
}
