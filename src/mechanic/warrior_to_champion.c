/*
** EPITECH PROJECT, 2025
** Corewar : Warrior -> Champion
** File description:
** Only the greatest warrior may become the Champion
*/

#include <stdbool.h>
#include <stdlib.h>
#include <sys/types.h>

#include "warrior.h"
#include "instruction.h"
#include "macros.h"

ssize_t find_warriors_len(warrior_t **warriors)
{
    ssize_t count = 0;

    if (warriors == NULL)
        return FAIL_VALUE;
    for (size_t i = 0; warriors[i] != NULL; i++) {
        count++;
    }
    return count;
}

bool warrior_transition(warrior_t *warrior, champion_t *champion)
{
    int *reg = NULL;

    reg = malloc(sizeof(int) * REG_NUMBER);
    if (reg == NULL)
        return false;
    reg[0] = warrior->prog_number;
    champion->instr = C_NON;
    champion->name = warrior->champ_name;
    champion->pc = &warrior->addres;
    champion->pos = warrior->addres;
    champion->ptr = NULL;
    champion->reg = &reg;
    champion->remanent_cycle = 0;
    champion->dead = false;
    return true;
}

bool champion_loop(warrior_t **warriors, champion_t ***champ_array)
{
    for (size_t i = 0; warriors[i] != NULL; i++) {
        (*champ_array)[i] = malloc(sizeof(champion_t));
        if (warrior_transition(warriors[i], (*champ_array)[i]) == false)
            return false;
    }
    return true;
}

bool warrior_to_champion(warrior_t **warriors, champion_t ***champ_array)
{
    ssize_t nb_warriors = 0;

    if (warriors == NULL || champ_array == NULL)
        return false;
    nb_warriors = find_warriors_len(warriors);
    if (nb_warriors == FAIL_VALUE)
        return false;
    (*champ_array) = malloc(sizeof(champion_t *) * (nb_warriors + 1));
    if ((*champ_array) == NULL)
        return false;
    return champion_loop(warriors, champ_array);
}
