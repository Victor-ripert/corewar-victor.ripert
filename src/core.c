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
    sort_warriors(corewar->warriors, corewar->warriors_nb);
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
