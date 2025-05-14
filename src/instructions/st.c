/*
** EPITECH PROJECT, 2025
** Corewar -> instructions
** File description:
** st instruction
*/


#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "op.h"
#include "macros.h"
#include "instruction.h"

bool st_check_params(args_type_t *type_array)
{
    if (type_array[0] != C_REG)
        return false;
    if (type_array[1] != C_IND && type_array[1] != C_REG)
        return false;
    if (type_array[2] != C_NON || type_array[3] != C_NON)
        return false;
    return true;
}

bool st_handle_reg(uint8_t *params, context_t *context)
{
    const uint8_t reg1_num = params[1];
    const uint8_t reg2_num = params[2];

    if (params[1] > REG_NUMBER || params[2] > REG_NUMBER)
        return false;
    (*context->reg)[reg2_num] = (*context->reg)[reg1_num];
    return true;
}

bool st_hanlde_indir(uint8_t *params, context_t *context)
{
    const uint8_t reg_num = params[1];
    const int indir = byte_to_indir(params[2], params[3]);
    const size_t adress = ((*context->pc) + indir) % IDX_MOD;

    if (reg_num > REG_NUMBER || adress > MEM_SIZE)
        return false;
    return write_int_byte(context, (*context->reg)[reg_num], adress);
}

bool st_instr(uint8_t *params, context_t *context)
{
    args_type_t *type_array = NULL;

    if (read_coding_byte(params[0], &type_array) == false)
        return false;
    if (st_check_params(type_array) == false)
        return false;
    if (type_array[1] == C_REG) {
        free(type_array);
        return st_handle_reg;
    }
    if (type_array[1] == C_IND) {
        free(type_array);
        return st_hanlde_indir(params, context);
    }
}
