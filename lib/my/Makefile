##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC = 	free_arr.c					\
		my_getnbr.c					\
		my_putchar.c				\
		my_putstr.c					\
		my_str_to_word_array.c		\
		my_strcat.c					\
		my_strcmp.c					\
		my_strdup.c					\
		my_strlen.c					\
		my_strncmp.c				\

NAME =	libmy.a

OBJ =	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

clean:
	$(RM) $(OBJ)

fclean:     clean
	$(RM) $(NAME)
	$(RM) ../libmy.a
	$(RM) ../../libmy.a

re:     fclean all
