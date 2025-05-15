/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** zjump
*/

#include <stdbool.h>

#include "instruction.h"

bool zjmp_inst(uint8_t *params, champion_t *champion, uint8_t *)
{
    signed short arg = 0;
    if (champion->carry) {
        arg = (signed short)byte_to_indir(params[0], params[1]);
        champion->pos += arg;
    }
    return true;
}
