/*
** EPITECH PROJECT, 2024
** oui
** File description:
** fi
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        nb = nb * 10 + (str[i] - 48);
        i++;
    }
    return nb;
}
