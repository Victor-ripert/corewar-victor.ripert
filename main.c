/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** main
*/

#include <stdlib.h>
#include "macros.h"
#include "my.h"

int main(int argc, char **argv)
{
    if (!core(argc, argv)) {
        return ERROR_VALUE;
    }
    return SUCCESS_VALUE;
}