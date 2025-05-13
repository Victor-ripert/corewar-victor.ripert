/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** count the nb of char in a string
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int nb = 0;

    if (str == NULL) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; ++i)
        ++nb;
    return nb;
}
