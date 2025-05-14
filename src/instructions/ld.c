/*
** EPITECH PROJECT, 2025
** CoreWar -> instructions/ld.c
** File description:
** take 2 parameters, load the value of the first in the second
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "macros.h"
#include "instruction.h"
#include "op.h"

static bool ld_handle_dir(uint8_t *params, champion_t *champion, int dir)
{
    const size_t reg_pos = 5;

    if (params[reg_pos] > REG_NUMBER)
        return false;
    (*champion->reg)[params[reg_pos]] = dir;
    return true;
}

static bool ld_handle_indir(uint8_t *params, uint8_t **map,
    champion_t *champion, int indir)
{
    const size_t reg_pos = 3;
    int adress = ((*champion->pc) + params[reg_pos]) % IDX_MOD;
    int result = 0;

    if (params[reg_pos] > REG_NUMBER)
        return false;
    result = byte_to_int((*map[adress]), (*map[adress + 1]),
        (*map[adress + 2]), (*map[adress + 3]));
    (*champion->reg)[params[reg_pos]] = result;
    return true;
}

bool ld_instr(uint8_t *params, champion_t *champion, uint8_t **map)
{
    args_type_t *type_array = NULL;
    int arg1 = 0;

    if (read_coding_byte(params[0], &type_array) == false)
        return false;
    if (type_array[0] == C_DIR) {
        arg1 = byte_to_int(params[1], params[2], params[3], params[4]);
        free(type_array);
        return ld_handle_dir(params, champion, arg1);
    }
    if (type_array[0] == C_IND) {
        arg1 = byte_to_indir(params[1], params[2]);
        free(type_array);
        return ld_handle_indir(params, map, champion, arg1);
    }
    return false;
}
