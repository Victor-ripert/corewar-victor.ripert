/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** champions
*/

#include "op.h"
#include <sys/types.h>

#ifndef WARRIOR
    #define WARRIOR
    typedef struct warrior_s {
        ssize_t addres;
        ssize_t prog_number;
        char *pathname;
        char *champ_name;
        header_t header[sizeof(header_t)];
        unsigned char *prog;
    }warrior_t;

#endif /* WARRIOR */
