/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** free_warriors
*/

#include <stdlib.h>
#include "warrior.h"

void free_warriors(warrior_t **warriors)
{
    for (int i = 0; warriors[i] != NULL; ++i) {
        if (warriors[i]->prog != NULL) {
            free(warriors[i]->prog);
        }
        free(warriors[i]);
    }
    free(warriors);
}
