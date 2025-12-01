##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile of project
##

CC = 	epiclang

CFLAGS	= -Wall -Wextra

PATH_LIBMY	= lib/my/

PATH_SRC	=	src/

SRC	=	$(PATH_LIBMY)my_compute_power_rec.c	\
		$(PATH_LIBMY)my_getnbr.c	\
		$(PATH_LIBMY)my_isinf.c	\
		$(PATH_LIBMY)my_isnan.c	\
		$(PATH_LIBMY)my_isneg.c	\
		$(PATH_LIBMY)my_printf.c	\
		$(PATH_LIBMY)my_put_bin.c	\
		$(PATH_LIBMY)my_put_float_sci.c	\
		$(PATH_LIBMY)my_put_float.c	\
		$(PATH_LIBMY)my_put_hex.c	\
		$(PATH_LIBMY)my_put_ieee.c	\
		$(PATH_LIBMY)my_put_nbr_uint.c	\
		$(PATH_LIBMY)my_put_nbr.c	\
		$(PATH_LIBMY)my_put_oct.c	\
		$(PATH_LIBMY)my_put_pointer.c	\
		$(PATH_LIBMY)my_putchar.c	\
		$(PATH_LIBMY)my_putstr.c	\
		$(PATH_LIBMY)my_revstr.c	\
		$(PATH_LIBMY)my_str_isalpha.c	\
		$(PATH_LIBMY)my_str_to_word_array.c	\
		$(PATH_LIBMY)my_strcat.c	\
		$(PATH_LIBMY)my_strcmp.c	\
		$(PATH_LIBMY)my_strcpy.c	\
		$(PATH_LIBMY)my_strdup.c	\
		$(PATH_LIBMY)my_strlen.c	\
		$(PATH_LIBMY)my_strncat.c	\
		$(PATH_LIBMY)my_strncpy.c	\
		$(PATH_LIBMY)my_swap.c	\
		$(PATH_SRC)temp.c	\
		$(PATH_SRC)main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	organized

all:	$(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME) -L. -lshell
	@echo "Everything is compiled"

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@echo "Everything is cleaned"

re:	clean all