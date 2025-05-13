/*
** EPITECH PROJECT, 2024
** lib
** File description:
** function.c
*/

#include "my.h"
#include <stddef.h>

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2)) {
        return 1;
    }
    if (s1 == NULL && s2 == NULL)
        return 0;
    for (int i = 0; s1[i] != '\0'; ++i) {
        if (s1[i] != s2[i])
            return 1;
    }
    return 0;
}
