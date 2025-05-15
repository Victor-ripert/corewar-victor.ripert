/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** handle_offset.c
*/

#include "offset.h"
#include <stdbool.h>
#include <stdio.h>

bool handle_offset(champion_t *offset)
{
    void *ptr = NULL;
    size_t size = 0;
    size_t n = 0;

    if (fread(ptr, &size, &n, offset->stream) == -1)
        return false;
}
