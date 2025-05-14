/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** core
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "my.h"
#include "args.h"
#include "args.h"
#include "macros.h"
#include "warrior.h"

static bool launch_sim(sim_t *corewar)
{
    char arena[] = {0};

    sort_warriors(corewar->warriors, corewar->warriors_nb);
    assign_adress(corewar->warriors, corewar->warriors_nb);
    put_in_arena(&arena, corewar->warriors, corewar->warriors_nb);
    return true;
}

bool core(char **argv)
{
    sim_t *corewar = NULL;

    if (!pars_args(argv, &corewar)) {
        return false;
    }
    if (!launch_sim(corewar)) {
        return false;
    }
    free_warriors(corewar->warriors);
    free(corewar);
    return true;
}
