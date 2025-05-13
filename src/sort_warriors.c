/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** sort_warriors
*/

#include <stdlib.h>
#include "my.h"
#include "warrior.h"

static void swap_warriors(warrior_t *warrior1, warrior_t *warrior2)
{
    warrior_t *tmp = warrior1;

    warrior1 = warrior2;
    warrior2 = tmp;
}

static void bubble_sort(warrior_t **warriors)
{
    for (int i = 0; warriors[i + 1] != NULL; ++i) {
        if (warriors[i]->prog_number > warriors[i + 1]->prog_number) {
            swap_warriors(warriors[i], warriors[i + 1]);
        }
    }
}

void sort_warriors(warrior_t **warriors, int warriors_nb)
{
    for (int i = 0; i < warriors_nb; ++i) {
        bubble_sort(warriors);
    }
}
