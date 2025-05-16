/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** sti
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "op.h"
#include "macros.h"
#include "instruction.h"

static bool check_params(args_type_t *type_array)
{
    if (type_array[0] != C_REG)
        return false;
    if (type_array[1] == C_NON)
        return false;
    if (type_array[2] != C_DIR && type_array[2] != C_REG)
        return false;
    if (type_array[3] != C_NON)
        return false;
    return true;
}

static int get_indir(uint8_t *params, champion_t *champion,
    uint8_t *map, size_t pos)
{
    size_t adress = (byte_to_indir(params[pos],
        params[pos + 1]) + (*champion->pc)) % IDX_MOD;

    return byte_to_int(map[adress], map[(adress + 1) % IDX_MOD],
    map[(adress + 2) % IDX_MOD], map[(adress + 4) % IDX_MOD]);
}

static int get_arg2(uint8_t *params, champion_t *champion,
    uint8_t *map, size_t *pos)
{
    int arg2 = 0;
    args_type_t *type_array = NULL;

    read_coding_byte(params[0], &type_array);
    if (type_array[1] == C_REG) {
        arg2 = (*champion->reg)[(*pos)];
        (*pos) += C_REG;
    }
    if (type_array[1] == C_IND) {
        arg2 = get_indir(params, champion, map, (*pos));
        (*pos) += IND_SIZE;
    }
    if (type_array[1] == C_DIR) {
        arg2 = byte_to_int(params[(*pos)], params[(*pos) + 1],
        params[(*pos) + 2], params[(*pos) + 3]);
        (*pos) += DIR_SIZE;
    }
    free(type_array);
    return arg2;
}

static int get_arg3(uint8_t *params, champion_t *champion,
    uint8_t *map, size_t *pos)
{
    int arg3 = 0;
    args_type_t *type_array = NULL;

    read_coding_byte(params[0], &type_array);
    if (type_array[2] == C_REG) {
        arg3 = (*champion->reg)[(*pos)];
        (*pos) += C_REG;
    }
    if (type_array[2] == C_IND) {
        arg3 = get_indir(params, champion, map, (*pos));
        (*pos) += IND_SIZE;
    }
    if (type_array[2] == C_DIR) {
        arg3 = byte_to_int(params[(*pos)],
        params[(*pos) + 1], params[(*pos) + 2], params[(*pos) + 3]);
        (*pos) += DIR_SIZE;
    }
    free(type_array);
    return arg3;
}

bool sti_inst(uint8_t *params, champion_t *champion,
    uint8_t *map, champion_t **)
{
    args_type_t *type_array = NULL;
    size_t pos = 1;
    int arg1 = 0;
    int arg2 = 0;
    int arg3 = 0;

    if (read_coding_byte(params[0], &type_array) == false)
        return false;
    return true;
    arg1 = (*champion->reg)[params[pos]];
    pos += C_REG;
    arg2 = get_arg2(params, champion, map, &pos);
    arg3 = get_arg3(params, champion, map, &pos);
    if (write_int_byte(map, arg1, (arg2 + arg3)) == false)
        champion->carry == false;
    return true;
}
