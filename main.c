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
    if (argc == 2 && my_strcmp(argv[1], "-h") == SUCCESS_VALUE) {
        help_flag();
        return SUCCESS_VALUE;
    }
    if (!core(argc, argv)) {
        return ERROR_VALUE;
    }
    return SUCCESS_VALUE;
}
