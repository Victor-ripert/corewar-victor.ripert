/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** args
*/

#include <stdbool.h>
#include <stdlib.h>
#include "warrior.h"

#ifndef ARGS
    #define ARGS

typedef struct warrior_s warrior_t;

typedef struct sim_s {
    size_t dump;
    size_t warriors_nb;
    size_t prog_nb;
    size_t load_address;
    warrior_t **warriors;
}sim_t;

bool init_dump(char *arg, sim_t *corewar, size_t *i);
bool get_load_address(char *arg, sim_t *corewar, size_t *i);
bool get_prog_nbr(char *arg, sim_t *corewar, size_t *i);

typedef struct args_s {
    char *flag;
    bool (*func)(char *, sim_t *, size_t *);
}args_t;

static const args_t args_tab[] = {
    {"-dump", init_dump},
    {"-n", get_prog_nbr},
    {"-a", get_load_address},
    {NULL, NULL}
};

#endif /* ARGS */
