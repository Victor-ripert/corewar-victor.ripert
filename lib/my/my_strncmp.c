/*
** EPITECH PROJECT, 2024
** lib
** File description:
** function.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            return -1;
        }
    }
    return 0;
}
