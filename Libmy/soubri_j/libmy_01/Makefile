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
				  my_putnbr.c 
				  

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