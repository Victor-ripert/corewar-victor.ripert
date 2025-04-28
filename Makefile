##
## EPITECH PROJECT, 2025
## Makefile for corewar
## File description:
## Makefile for corewar
##


SRC = 	main.c					\
		src/help.c				\
		src/core.c				\


OBJ	=	$(SRC:.c=.o)

CC = gcc

CPPFLAGS = -I./include

CFLAGS = -Wall -Wextra

LDFLAGS = -L./lib -lmy

NAME = corewar

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SRC)-o $(NAME) $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all clean

.PHONY: all re clean fclean
