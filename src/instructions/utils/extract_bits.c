/*
** EPITECH PROJECT, 2025
** Corewar -> extract bits
** File description:
** extract multiples bytes from start to end
*/

#include <sys/types.h>
#include <stdint.h>

size_t extract_bits(uint8_t byte, size_t start, size_t end)
{
    uint8_t result = 0;
    uint8_t mask = 0;

    for (size_t i = start; i <= end; i++) {
        mask = mask | (1 << i);
    }
    result = (byte & mask) >> start;
    return result;
}
