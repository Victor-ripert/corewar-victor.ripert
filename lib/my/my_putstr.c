/*
** EPITECH PROJECT, 2024
** put_str
** File description:
** display a string
*/

#include <stdlib.h>
#include "my.h"

int my_putstr(char const *str)
{
    int count = 0;

    if (str == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
        count++;
        }
    return count;
}
