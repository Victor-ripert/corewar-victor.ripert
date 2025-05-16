/*
** EPITECH PROJECT, 2025
** Corewar -> count_live_champions.c
** File description:
** Count and return the number of living champions
*/

#include <stdbool.h>
#include <stddef.h>

#include "op.h"
#include "instruction.h"
#include "my.h"
#include "macros.h"

#include <stdio.h>

bool count_live_champions(champion_t **champ_array, size_t *nb_champ)
{
    size_t count = 0;

    if (champ_array == NULL || nb_champ == NULL)
        return false;
    for (size_t i = 0; champ_array[i] != NULL; i++) {
        if (champ_array[i]->dead == false)
            count++;
    }
    (*nb_champ) = count;
    return true;
}
