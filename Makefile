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


OBJ	=	$(SRC:.c=.o)

CC = gcc

CPPFLAGS = -I./include

CFLAGS = -Wall -Wextra -ggdb3

LDFLAGS = -L./lib -lmy

NAME = corewar

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

coding-style: fclean
	~/coding-style.sh .
	@cat coding-style-reports.log
	@$(RM) coding-style-reports.log

.PHONY: all re clean fclean
