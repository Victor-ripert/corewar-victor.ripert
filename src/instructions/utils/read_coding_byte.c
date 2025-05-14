/*
** EPITECH PROJECT, 2025
** Corewar -> read_coding_byte.c
** File description:
** Read the coding byte and fill a args_type_t * passed as argument
*/

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>
#include "op.h"

#include <stdio.h>

bool read_coding_byte(uint8_t coding_byte, args_type_t **type_array)
{
    size_t result = 0;
    size_t index = 0;

    (*type_array) = malloc(sizeof(args_type_t) * 4);
    if ((*type_array) == NULL)
        return false;
    for (int i = 7; i >= 1; i -= 2) {
        result = extract_bits(coding_byte, i - 1, i);
        printf("result %d, %d = %ld\n", i - 1, i, result);
        (*type_array)[index] = result;
        index++;
    }
    return true;
}
