/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** arena
*/

#include <stdlib.h>
#include <stdbool.h>

#include "macros.h"
#include "warrior.h"
#include "my.h"
#include "args.h"
#include "op.h"

void my_put_base(int nb, int base, char *charbase, bool is_a_digit)
{
    int temp_nb = 0;
    int count = 0;

    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
        count++;
    }
    if (nb >= base) {
        temp_nb = nb % base;
        my_put_base(nb / base, base, charbase, false);
        my_putchar(charbase[temp_nb]);
        count++;
    }
    if (nb < base) {
        if (is_a_digit)
            my_putchar('0');
        my_putchar(charbase[nb]);
        count++;
    }
}

void print_map(u_int8_t *arena)
{
    for (int i = 0; i < MEM_SIZE; i += 1) {
        if (i % 60 == 0 && i > 0) {
            my_putchar('\n');
        }
        my_put_base(arena[i], EXA, EXA_BASE, true);
        my_putchar(' ');
    }
    my_putchar('\n');
    return;
}

static void put_at_adress(u_int8_t *arena, warrior_t **warriors, int index)
{
    for (int i = 0; i < warriors[index]->header.prog_size; ++i) {
        arena[warriors[index]->addres + i] = warriors[index]->prog[i];
    }
}

static size_t get_warrior_size(warrior_t **warriors)
{
    size_t size = 0;

    for (int i = 0; warriors[i] != NULL; ++i) {
        size += warriors[i]->header.prog_size;
    }
    return size;
}

void put_in_arena(u_int8_t *arena, warrior_t **warriors)
{
    for (int i = 0; warriors[i] != NULL; ++i) {
        put_at_adress(arena, warriors, i);
    }
    return;
}

bool assign_adress(warrior_t **warriors, size_t warriors_nb)
{
    size_t spaces = 0;
    size_t current = 0;
    size_t warriors_size = get_warrior_size(warriors);

    if (warriors_size > MEM_SIZE)
        return false;
    spaces = MEM_SIZE / warriors_nb;
    for (int i = 0; warriors[i] != NULL; ++i) {
        if (warriors[i]->addres == UNINITIALIZED) {
            current += spaces % MAP_MOD;
            warriors[i]->addres = current;
        }
    }
    return true;
}
