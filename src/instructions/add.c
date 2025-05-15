/*
** EPITECH PROJECT, 2025
** Corewar -> instruction
** File description:
** ADD instruction, take 3 register, and the 2 first and store it in the third.
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "op.h"
#include "macros.h"
#include "instruction.h"

bool add_instr(uint8_t *params, champion_t *champion, uint8_t **)
{
    args_type_t *type_array = NULL;
    int reg1_num = 0;
    int reg2_num = 0;
    int reg3_num = 0;

    if (read_coding_byte(params[0], &type_array) == false)
        return false;
    if (type_array[0] != C_REG || type_array[1] != C_REG
        || type_array[2] != C_REG)
        return false;
    reg1_num = params[1];
    reg2_num = params[2];
    reg3_num = params[3];
    if (reg1_num > REG_NUMBER || reg2_num > REG_NUMBER
        || reg3_num > REG_NUMBER)
        return false;
    (*champion->reg)[reg3_num] = (*champion->reg)[reg1_num] +
        (*champion->reg)[reg2_num];
    return true;
}
