/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** champion_parsing.c
*/

#include <stdbool.h>
#include <stddef.h>
#include "op.h"
#include "instruction.h"

bool play_champion(context_t *context, champion_t *champion)
{
    if (execute_instr(context, champion) == false)
        return false;
    return true;
}

bool select_champions(context_t *context, champion_t **champ_array)
{
    for (size_t i = 0; champ_array[i] != NULL; i++) {
        if (play_champion(context, champ_array[i]) == false)
            return false;
    }
    return true;
}

bool main_loop(context_t *context, champion_t **champ_array, uint8_t *map)
{
    size_t cycle = 0;

    context->map = &map;
    while (true) {
        if (play_champion(context, champ_array) == false)
            return false;
        cycle++;
    }
    return true;
}
