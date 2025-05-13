/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** core
*/

#include <stdlib.h>
#include <stdbool.h>

#include "my.h"
#include "args.h"
#include "args.h"
#include "macros.h"
#include "warrior.h"

bool core(char **argv)
{
    sim_t *corewar = NULL;

    if (!pars_args(argv, corewar)) {
        return false;
    }
    return true;
}
