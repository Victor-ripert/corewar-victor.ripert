/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** pars_args
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "my.h"
#include "macros.h"
#include "args.h"
#include "warrior.h"

bool get_prog_nbr(char *arg, sim_t *corewar, size_t *i)
{
    int nbr_cycle = my_getnbr(arg);

    if (nbr_cycle <= 0) {
        return false;
    }
    corewar->prog_nb = (size_t)nbr_cycle;
    *i = *i + 2;
    return true;
}

bool get_load_address(char *arg, sim_t *corewar, size_t *i)
{
    int load_address = my_getnbr(arg);

    if (load_address <= 0) {
        return false;
    }
    corewar->load_address = (size_t)load_address;
    *i = *i + 2;
    return true;
}

bool init_dump(char *arg, sim_t *corewar, size_t *i)
{
    int nb_cycle = my_getnbr(arg);

    if (nb_cycle <= 0) {
        return false;
    }
    corewar->dump = (size_t)nb_cycle;
    *i = *i + 2;
    return true;
}

static bool check_arg(char **argv, sim_t *corewar, size_t *i)
{
    for (int j = 0; args_tab[j].flag != NULL; ++j) {
        if (strcmp(args_tab[j].flag ,argv[*i]) == SUCCESS_VALUE) {
            return args_tab[j].func(argv[*i + 1], corewar, i);
        }
    }
    return get_warrior(argv[*i], corewar, i);
}

bool init_sim(sim_t **sim)
{
    sim_t *new_sim = malloc(sizeof(sim_t));

    if (new_sim == NULL) {
        return false;
    }
    new_sim->dump = 0;
    new_sim->load_address = 0;
    new_sim->prog_nb = 0;
    new_sim->warriors = NULL;
    new_sim->warriors_nb = 0;
    *sim = new_sim;
    return true;
}

bool pars_args(char **argv, sim_t *corewar)
{
    size_t i = 1;

    if (!init_sim(&corewar)) {
        return false;
    }
    while (argv[i] != NULL) {
        if (!check_arg(argv, corewar, &i)) {
            return false;
        }
    }
    return true;
}
