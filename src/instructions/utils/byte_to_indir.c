/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** byte to int
*/

#include <stdint.h>

int byte_to_indir(uint8_t byte1, uint8_t byte2)
{
    int first = byte1;
    int second = byte2;
    int result = 0;

    first = first << 8;
    result = result | first;
    result = result | second;
    return result;
}
