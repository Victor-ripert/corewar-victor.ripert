/*
** EPITECH PROJECT, 2025
** Corewar -> execute_instr.c
** File description:
** Execute the instruction and move the champion's
** cursor, then find the new instr
*/

#include <stdbool.h>
#include <stddef.h>
#include "instruction.h"
#include "macros.h"

static bool find_instr(context_t *context, champion_t *champion)
{
    const op_to_instr_t instr_tab[NB_INSTR] = {
        {2, &ld_instr, 5},
        {3, &st_instr, 5},
        {0, NULL, 0}
    };

    for (size_t i = 0; i < NB_INSTR; i++) {
        if ((*context->map)[champion->pos] == instr_tab[i].opcode) {
            champion->instr = instr_tab[i].opcode;
            champion->remanent_cycle = instr_tab[i].nb_cycle;
        }
        return true;
    }
    champion->pos++;
    return true;
}

bool fill_n_byte(context_t *context, uint8_t **byte_array,
    size_t n, size_t pos)
{
    if (byte_array == NULL)
        return false;
    (*byte_array) = malloc(sizeof(uint8_t) * (n + 1));
    if ((*byte_array) == NULL)
        return false;
    for (size_t i = 0; i < n; i++) {
        (*byte_array)[i] = (*context->map)[pos + i];
    }
    (*byte_array)[n] = 0;
    return true;
}

bool case_instr(context_t *context, champion_t *champion)
{
    ssize_t nb_byte = 0;
    uint8_t *byte_array = NULL;

    if (champion->instr != C_NON) {
        nb_byte = find_instr_size(context,
            (*context->map)[champion->pos], champion->pos);
        if (nb_byte == FAIL_VALUE)
            return false;
        if (fill_n_byte(context, &byte_array,
            nb_byte, champion->pos) == false)
            return false;
        if (champion->ptr(byte_array, context) == false)
            return false;
        champion->pos = (champion->pos + nb_byte + 1) % IDX_MOD;
    }
}

bool execute_instr(context_t *context, champion_t *champion)
{
    if (champion->remanent_cycle > 0)
        return true;
    if (champion->instr != C_NON) {
        if (case_instr(context, champion) == false)
            return false;
    }
    if (champion->instr == C_NON) {
        if (find_instr(context, champion) == false)
            return false;
    }
    return true;
}
