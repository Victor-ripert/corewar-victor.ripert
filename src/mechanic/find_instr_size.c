/*
** EPITECH PROJECT, 2025
** Corewar -> find_instr_size.c
** File description:
** return the ssize_t size of the instruction (from the coding byte
** to the last byte of the last parameter).
*/

#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include "instruction.h"
#include "op.h"
#include "macros.h"

bool is_index(uint8_t opcode)
{
    uint8_t index_tab[NB_INSTR_WITH_INDEX] = {
        9,
        10,
        11,
        14
    };

    for (size_t i = 0; i < NB_INSTR_WITH_INDEX; i++) {
        if (index_tab[i] == opcode)
            return true;
    }
    return false;
}

ssize_t find_instr_size(uint8_t *map, uint8_t opcode, size_t pos)
{
    ssize_t instr_size = 0;
    args_type_t *type_array = NULL;
    size_t dir_size = DIR_SIZE;

    if (read_coding_byte(map[(pos + 1) % IDX_MOD], &type_array) == false)
        return FAIL_VALUE;
    if (is_index(opcode) == true)
        dir_size = 2;
    for (size_t i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (type_array[i] == C_DIR)
            instr_size += dir_size;
        if (type_array[i] == C_IND)
            instr_size += IND_SIZE;
        if (type_array[i] == C_REG)
            instr_size += T_REG;
    }
    return instr_size;
}
