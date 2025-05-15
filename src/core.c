/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** core
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/stat.h>

#include "my.h"
#include "args.h"
#include "args.h"
#include "macros.h"
#include "warrior.h"
#include "instruction.h"

static bool return_status(sim_t *corewar, bool status)
{
    free_warriors(corewar->warriors);
    free(corewar);
    return status;
}

static bool launch_sim(sim_t *corewar)
{
    u_int8_t arena[MEM_SIZE] = {0};

    sort_warriors(corewar->warriors, corewar->warriors_nb);
    if (!assign_adress(corewar->warriors, corewar->warriors_nb)) {
        return false;
    }
    put_in_arena(arena, corewar->warriors);
    if (init_champion_map(corewar, (uint8_t *)&arena) == false)
        return false;
    return true;
}

bool core(int argc, char **argv)
{
    sim_t *corewar = NULL;

    if (argc < 2) {
        display_error("INIT: Too few warrior\n");
        return false;
    }
    if (!pars_args(argv, &corewar))
        return false;
    if (corewar->warriors_nb < 2) {
        display_error("INIT: Too few warrior\n");
        return return_status(corewar, false);
    }
    if (!launch_sim(corewar))
        return return_status(corewar, false);
    return return_status(corewar, true);
}
