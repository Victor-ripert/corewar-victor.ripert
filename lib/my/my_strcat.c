/*
** EPITECH PROJECT, 2024
** lib
** File description:
** function.c
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int index = 0;

    if (src == NULL) {
        return dest;
    }
    while (dest[index] != '\0') {
        index++;
    }
    for (int i = 0; src[i] != '\0'; ++i) {
        dest[index] = src[i];
        index++;
    }
    dest[index] = '\0';
    return dest;
}
