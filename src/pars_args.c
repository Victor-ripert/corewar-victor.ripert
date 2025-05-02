/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** pars_args
*/

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "my.h"
#include "macros.h"
#include "args.h"
#include "warrior.h"

static param_t *get_arg(char *arg, char *param)
{
    param_t *parametter = malloc(sizeof(param_t));


    if (parametter == NULL)
        return NULL;
    for (int i = 0; args_tab[i].flag_str != NULL; ++i) {
        if (strcmp(args_tab[i].flag_str, arg) == SUCCESS_VALUE) {
            parametter->arg = args_tab[i];
            parametter->flag = args_tab[i].flag;
            parametter->func = args_tab[i].func;
        }
    }
    return parametter;
}

static bool pars_args(int argc, char **argv, param_t ***cmds)
{
    param_t **tmp = malloc(sizeof(param_t *));
    int index = 0;

    if (tmp == NULL)
        return false;
    for (int i = 1; argv[i] != NULL; i += 2) {
        tmp = realloc(tmp, sizeof(param_t *) * (index + 1));
        if (tmp == NULL)
            return false;
        tmp[index] = get_arg(argv[i], argv[i + 1]);
        if (tmp[index] == NULL) {
            free(tmp);
            return false;
        }
        index++;
    }
    *cmds = tmp;
    return true;
}

bool get_args(int argc, char **argv, param_t ***cmds)
{
    if (argc = 2 && strcmp(argv[1], "-h") == SUCCESS_VALUE) {
        return help_flag();
    }
    return pars_args(argc, argv, cmds);
}
