CFLAGS				= -Wall -Wextra -Werror -std=c99

CC					= gcc

RM					= rm -f

PROGRAM_NAME		= do-op

SRC					= main.c \
					  my_chrpos.c \
					  my_getnbr.c \
					  my_math_op.c \
					  my_pow.c \
					  my_putstr.c \
					  my_putnbr.c \
					  my_putchar.c

OBJ					= $(SRC:.c=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(PROGRAM_NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PROGRAM_NAME)

re: fclean all

.PHONY: all $(PROGRAM_NAME) clean fclean re