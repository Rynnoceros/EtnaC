##
## ETNA PROJECT, 22/10/2018 by soubri_j
## Makeflile
## File description: 
##      Makefile for Libmy library.
##

CFLAGS			= -Wall -Wextra -Werror -std=c99
CC				= gcc
AR_RC			= ar rc
RM				= rm -f
LIB_NAME		= libmy.a
SRC				= my_putchar.c \
				  my_is_odd.c \
				  my_putstr.c \
				  my_strlen.c \
				  my_is_neg.c \
				  my_is_even.c \
				  my_swap.c \
				  my_strstr.c \
				  my_strcpy.c \
				  my_strncpy.c \
				  my_strcmp.c \
				  my_strncmp.c \
				  my_strcat.c \
				  my_strncat.c \
				  my_getnbr.c \
				  my_putnbr.c \
				  my_putnbr_base.c \
				  my_strupcase.c \
				  my_strlowcase.c \
				  my_nbrlen.c \
				  my_nbrlen_base.c \
				  my_getnbr_base.c \
				  my_strdup.c \
				  my_str_to_wordtab.c \
				  my_compare_strings.c \
				  my_getnbr_func.c \
				  my_putnbr_func.c \
				  my_pow.c			  
OBJ				= $(SRC:.c=.o)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	$(AR_RC) $(LIB_NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(LIB_NAME)

re: fclean all

.PHONY: all $(LIB_NAME) clean fclean re