/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** swap_endian
*/

int swap_endian(int nb)
{
    int res = 0;

    res = ((nb >> 24) & 0x000000ff) |
    ((nb << 8) & 0xff0000) |
    ((nb >> 8) & 0xff00) |
    ((nb << 24) & 0xff000000);
    return res;
}
