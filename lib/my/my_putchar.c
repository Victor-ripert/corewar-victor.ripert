/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** write
*/
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
    return 1;
}
