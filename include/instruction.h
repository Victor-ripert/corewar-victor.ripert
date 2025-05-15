/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-victor.ripert
** File description:
** instruction.h
*/

#ifndef INSTRUCTION_H
    #define INSTRUCTION_H
    #include <stdbool.h>
    #include <stdint.h>
    #include <sys/types.h>
    #include "op.h"
    #define C_REG 1 /* Value of the register in the coding byte*/
    #define C_DIR 2 /* Value of the direct in the coding byte*/
    #define C_IND 3 /* Value of the indirect in the coding byte*/
    #define C_NON 0 /* Value of nothing in the coding byte*/
    #define NB_INSTR 16 /* Number of instructions in Corewar */
    #define NB_INSTR_WITH_INDEX 4

typedef struct warrior_s warrior_t;
typedef struct sim_s sim_t;

typedef struct champion_s {
    size_t remanent_cycle;
    size_t pos;
    uint8_t instr;
    char *name;
    bool (*ptr)(uint8_t *, struct champion_s *, uint8_t *);
    int **reg;
    ssize_t *pc;
} champion_t;

typedef struct op_to_instr_s {
    uint8_t opcode;
    bool (*ptr)(uint8_t *, champion_t *, uint8_t *);
    size_t nb_cycle;
} op_to_instr_t;

size_t extract_bits(uint8_t byte, size_t start, size_t end);
uint8_t extract_bits_int(int num, size_t start, size_t end);
bool read_coding_byte(uint8_t coding_byte, args_type_t **type_array);
int byte_to_int(uint8_t byte1, uint8_t byte2, uint8_t byte3, uint8_t byte4);
int byte_to_indir(uint8_t byte1, uint8_t byte2);
bool write_int_byte(uint8_t *map, int num, size_t adress);
ssize_t find_instr_size(uint8_t *map, uint8_t opcode, size_t pos);
bool execute_instr(uint8_t *map, champion_t *champion);

bool main_loop(champion_t **champ_array, uint8_t *map,
    size_t nb_robot, ssize_t dump);
bool warrior_to_champion(warrior_t **warriors, champion_t ***champ_array);
bool init_champion_map(sim_t *corewar, uint8_t *map);

/* Instructions */
bool ld_instr(uint8_t *params, champion_t *champion, uint8_t *map);
bool st_instr(uint8_t *params, champion_t *champion, uint8_t *map);
bool add_instr(uint8_t *params, champion_t *champion, uint8_t **);

#endif /* INSTRUCTION_H */
