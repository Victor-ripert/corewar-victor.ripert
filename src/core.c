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
#include "flags.h"
#include "args.h"
#include "macros.h"

bool core(int argc, char **argv)
{
    param_t **params = NULL;

    if (!get_args(argc, argv, &params)) {
        return false;
    }
}
