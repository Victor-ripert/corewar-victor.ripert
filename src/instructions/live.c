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

bool live_instr(uint8_t *params, champion_t *, uint8_t *, champion_t **champ_array)
{
    int arg1 = 0;

    arg1 = byte_to_int(params[0], params[1], params[2], params[3]);
    for (size_t i = 0; champ_array[i] != NULL; i++) {
        if ((*champ_array[i]->reg)[0] == arg1) {
            champ_array[i]->alive = true;
        }
    }
    return true;
}
