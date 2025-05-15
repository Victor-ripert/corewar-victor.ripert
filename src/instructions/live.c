/*
** EPITECH PROJECT, 2025
** CoreWar -> instructions/live.c
** File description:
** take 1 paremeter -> champions identifient (cham_nb)
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "macros.h"
#include "instruction.h"
#include "op.h"

static bool check_params(args_type_t *type_array)
{
    if (type_array[0] == C_REG)
        return false;
    if (type_array[1] != C_REG)
        return false;
    if (type_array[2] != C_NON || type_array[3] != C_NON)
        return false;
    return true;
}

bool live_instr(uint8_t *params, champion_t *champion, uint8_t *map, champion_t **champ_array)
{
    int arg1 = 0;


    return false;
}
