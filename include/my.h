/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** my
*/

#include <stdbool.h>
#include "warrior.h"
#include "args.h"

#ifndef MY_H
    #include "../lib/my/my.h"
    #define MY_H

bool core(char **argv);
bool pars_args(char **argv, sim_t **corewar);
void free_warriors(warrior_t **warriors);
void help_flag(void);
bool get_warrior(char *pathname, sim_t *corewar, size_t *i);
int swap_endian(int nb);
void sort_warriors(warrior_t **warriors, int warriors_nb);
void assign_adress(warrior_t **warriors, size_t warriors_nb);
bool put_in_arena(char **arena, warrior_t **warriors);
void assign_adress(warrior_t **warriors, size_t warriors_nb);

#endif /* MY_H */
