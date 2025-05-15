/*
** EPITECH PROJECT, 2025
** Corewar -> Check_living_champions.c
** File description:
** check if a champion die
*/

#include <stdbool.h>
#include <stddef.h>

#include "op.h"
#include "instruction.h"
#include "my.h"
#include "macros.h"

bool check_living_champions(champion_t **champ_array)
{
    if (champ_array == NULL)
        return false;
    for (size_t i = 0; champ_array[i] != NULL; i++) {
        if (champ_array[i]->alive == false)
            champ_array[i]->dead = true;
    }
    return true;
}