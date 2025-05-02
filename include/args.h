/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** args
*/

#include <stdbool.h>
#include <stdlib.h>

#ifndef ARGS
    #define ARGS

typedef enum flags_s {
    DUMP,
    PROG_NB,
    LOAD_ADD,
    NA
} flags_t;

typedef struct args_s {
    char *flag_str;
    flags_t flag;
    void *(*func)(char *);
}args_t;

const args_t args_tab[] = {
    {"-dump", DUMP, NULL},
    {"-n", PROG_NB, NULL},
    {"-a", LOAD_ADD, NULL},
    {NULL, NA, NULL}
};

typedef struct param_s {
    flags_t flag;
    args_t arg;
    void *(*func)(char *);
} param_t;

#endif /* ARGS */