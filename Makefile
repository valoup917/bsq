##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## .
##

SRC	=	lib/my_getnbr.c	\
		lib/my_putchar.c	\
		lib/my_putstr.c	\
		lib/my_str_to_word_array.c		\
		lib/my_strlen.c		\
		src/algorithme_functions.c		\
		src/conversion.c	\
		src/main.c		\

NAME	=	bsq

all:
	gcc -o $(NAME) $(SRC) -I./includes

clean:
	rm -f *~
	rm -f \#*\#

fclean:	clean
	rm -f $(NAME)

re:	fclean all
