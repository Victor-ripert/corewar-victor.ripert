/*
** EPITECH PROJECT, 2025
** Corewar -> fork.c
** File description:
** instruction fork, create another champion (offset)
** at the positon passed as parameter.
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "op.h"
#include "macros.h"
#include "instruction.h"

bool fork_instr(uint8_t *params, champion_t *champion,
    uint8_t *, champion_t **champ_array)
{
    int arg = byte_to_indir(params[0], params[1]);

    if (add_champion(&champ_array, (((*champion->pc) + arg) % IDX_MOD),
    (*champion->reg)[0]) == false)
        return false;
}
