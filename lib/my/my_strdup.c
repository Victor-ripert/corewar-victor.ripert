/*
** EPITECH PROJECT, 2024
** task01
** File description:
** str dup
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest;
    int len = my_strlen(src);

    if (src == NULL)
        return NULL;
    dest = malloc(sizeof(char) * (len + 1));
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}
