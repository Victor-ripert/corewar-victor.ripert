/*
** EPITECH PROJECT, 2025
** Corewar -> add_champion.c
** File description:
** Add a champion (offset) in the champ_array
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "op.h"
#include "macros.h"
#include "instruction.h"

static ssize_t champ_array_size(champion_t **champ_array)
{
    ssize_t count = 0;

    if (champ_array == NULL)
        return FAIL_VALUE;
    for (size_t i = 0; champ_array[i] != NULL; i++) {
        count++;
    }
    return count;
}

static int *init_reg(int r1)
{
    int *reg = malloc(sizeof(int) * REG_NUMBER);

    if (reg == NULL)
        return NULL;
    reg[0] = r1;
    for (size_t i = 1; i < REG_NUMBER; i++) {
        reg[i] = 0;
    }
}

static champion_t *init_new_champ(size_t pos, int id)
{
    champion_t *new = malloc(sizeof(champion_t));
    int *reg = init_reg(id);

    if (new == NULL || reg == NULL)
        return NULL;
    new->alive = true;
    new->dead = false;
    new->carry = false;
    new->instr = 0;
    new->name = NULL;
    new->pc = pos;
    new->pos = pos;
    new->ptr = NULL;
    new->reg = &reg;
    new->remanent_cycle = 0;
    return new;
}

bool add_champion(champion_t ***champ_array, size_t pos, int id)
{
    ssize_t array_size = 0;
    champion_t *new = NULL;

    if (champ_array == NULL)
        return false;
    array_size = champ_array_size((*champ_array));
    if (array_size == FAIL_VALUE)
        return false;
    (*champ_array) = realloc((*champ_array),
        sizeof(champion_t) * (array_size + 2));
    if ((*champ_array) == NULL)
        return false;
    new = init_new_champ(pos, id);
    if (new == NULL)
        return NULL;
    (*champ_array)[array_size] = new;
    (*champ_array)[array_size + 1] = NULL;
    return true;
}
