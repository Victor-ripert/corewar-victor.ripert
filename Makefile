##
## EPITECH PROJECT, 2025
## Makefile for corewar
## File description:
## Makefile for corewar
##


SRC = 	main.c					\
		src/core.c				\
		src/free_warriors.c		\
		src/get_champions.c		\
		src/help.c				\
		src/op.c				\
		src/pars_args.c			\
		src/swap_endian.c		\
		src/sort_warriors.c		\
		src/arena.c				\
		src/display_error.c		\
		src/instructions/utils/byte_to_indir.c	\
		src/instructions/utils/byte_to_int.c	\
		src/instructions/utils/extract_bits_int.c	\
		src/instructions/utils/extract_bits.c	\
		src/instructions/utils/read_coding_byte.c	\
		src/instructions/utils/write_int_byte.c	\
		src/instructions/add.c	\
		src/instructions/ld.c	\
		src/instructions/st.c	\
		src/mechanic/execute_instr.c	\
		src/mechanic/find_instr_size.c	\
		src/mechanic/init_champion_map.c	\
		src/mechanic/main_loop.c	\
		src/mechanic/warrior_to_champion.c	\
		src/mechanic/check_living_champions.c	\


OBJ	=	$(SRC:.c=.o)

CC = gcc

CPPFLAGS = -I./include

CFLAGS = -Wall -Wextra

LDFLAGS = -L./lib -lmy

NAME = corewar

DEBUG_CFLAGS = -ggdb3

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my/
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC)-o $(NAME) $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(OBJ)
	make clean -C lib/my

fclean: clean
	rm -f $(NAME)
	make fclean -C lib/my

re: fclean all clean

debug: CFLAGS += $(DEBUG_CFLAGS)
debug: re

coding-style: fclean
	~/coding-style.sh .
	@cat coding-style-reports.log
	@$(RM) coding-style-reports.log

.PHONY: all re clean fclean debug
