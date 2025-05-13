/*
** EPITECH PROJECT, 2025
** B-PSU-200-PAR-2-1-minishell1-antonin.meynadier
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

int my_getnbr(char const *str);
int my_putchar(char c);
int my_putstr(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
char **my_str_to_word_array(const char *str, const char *delims);
void free_array(void **array);

#endif /* MY_H_ */
