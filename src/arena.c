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

void put_in_arena(char **arena, warrior_t **warriors)
{
    char new_arena[MEM_SIZE] = {0};

    for (int i = 0; warriors[i] != NULL; ++i) {
        for (int j = 0; warriors[i]->prog[j] != NULL; ++j) {
            new_arena[(warriors[i]->addres + j) % IDX_MOD] =
            warriors[i]->prog[j];
        }
    }
    *arena = new_arena;
    return;
}

void assign_adress(warrior_t **warriors, size_t warriors_nb)
{
    size_t spaces = MEM_SIZE / warriors_nb;
    size_t current = 0;

    for (int i = 0; warriors[i] != NULL; ++i) {
        if (warriors[i]->addres == 0) {
            warriors[i]->addres = (current % IDX_MOD);
        }
        current += spaces;
    }
    return;
}
