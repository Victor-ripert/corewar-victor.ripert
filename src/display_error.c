/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** display_error
*/

#include <unistd.h>
#include "my.h"
#include "macros.h"

void display_error(char *error)
{
    write(ERROR_FD, error, my_strlen(error));
}