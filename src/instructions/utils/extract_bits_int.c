/*
** EPITECH PROJECT, 2025
** Corewar -> extract bits
** File description:
** extract multiple bits from start to end in a integer
*/

#include <sys/types.h>
#include <stdint.h>

uint8_t extract_bits_int(int num, size_t start, size_t end)
{
    uint8_t result = 0;
    uint8_t mask = 0;

    for (size_t i = start; i <= end; i++) {
        mask = mask | (1 << i);
    }
    result = (num & mask) >> start;
    return result;
}
