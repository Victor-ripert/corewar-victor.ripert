/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** byte to int
*/

#include <stdint.h>

int byte_to_int(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4)
{
    int first = byte1;
    int second = byte2;
    int third = byte3;
    int forth = byte4;
    int result = 0;

    first = first << 24;
    second = second << 16;
    third = third << 8;
    result = result | first;
    result = result | second;
    result = result | third;
    result = result | forth;
    return result;
}
