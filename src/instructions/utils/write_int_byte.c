/*
** EPITECH PROJECT, 2025
** Corewar -> write_int_byte.c
** File description:
** Rewrite an integer on 4bytes starting at `adress`
*/

#include <stdbool.h>
#include <sys/types.h>
#include "op.h"
#include "instruction.h"

bool write_int_byte(context_t *context, int num, size_t adress)
{
    uint8_t byte1 = 0;
    uint8_t byte2 = 0;
    uint8_t byte3 = 0;
    uint8_t byte4 = 0;

    if (adress > MEM_SIZE)
        return false;
    byte1 = extract_bits_int(num, 24, 31);
    byte2 = extract_bits_int(num, 16, 23);
    byte3 = extract_bits_int(num, 8, 15);
    byte4 = extract_bits_int(num, 0, 7);
    (*context->map)[adress] = byte1;
    (*context->map)[(adress + 1) % IDX_MOD] = byte2;
    (*context->map)[(adress + 2) % IDX_MOD] = byte3;
    (*context->map)[(adress + 3) % IDX_MOD] = byte4;
    return true;
}
