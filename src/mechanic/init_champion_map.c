/*
** EPITECH PROJECT, 2025
** Corewar -> Init_champion_map.c
** File description:
** Transform warrior to champion, get the map ready
** with the champion in start the fight in the arena
*/

#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>

#include "warrior.h"
#include "instruction.h"
#include "macros.h"
#include "args.h"

bool init_champion_map(sim_t *corewar, uint8_t *map)
{
    champion_t **champ_array = NULL;

    if (warrior_to_champion(corewar->warriors, &champ_array) == false)
        return false;
    return main_loop(champ_array, map, corewar->warriors_nb, corewar->dump);
}
