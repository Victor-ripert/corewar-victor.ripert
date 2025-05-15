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

bool play_champion(uint8_t **map, champion_t *champion)
{
    if (execute_instr(map, champion) == false)
        return false;
    return true;
}

bool select_champions(uint8_t **map, champion_t **champ_array)
{
    for (size_t i = 0; champ_array[i] != NULL; i++) {
        if (play_champion(map, champ_array[i]) == false)
            return false;
    }
    return true;
}

bool main_loop(champion_t **champ_array, uint8_t **map)
{
    size_t cycle = 0;

    while (true) {
        if (select_champions(map, champ_array) == false)
            return false;
        cycle++;
        if (cycle > 100)
            return true;
    }
    return true;
}
