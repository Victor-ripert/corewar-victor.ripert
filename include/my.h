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

bool core(int argc, char **argv);
bool pars_args(char **argv, sim_t **corewar);
void free_warriors(warrior_t **warriors);
void help_flag(void);
bool get_warrior(char *pathname, sim_t *corewar, size_t *i);
int swap_endian(int nb);
void sort_warriors(warrior_t **warriors, int warriors_nb);
void put_in_arena(u_int8_t *arena, warrior_t **warriors);
bool assign_adress(warrior_t **warriors, size_t warriors_nb);
void print_map(u_int8_t *map);
void display_error(char *error);
int my_put_nbr(int nb);

#endif /* MY_H */
