CFLAGS			= -Wall -Wextra -Werror

CC				= gcc

RM				= rm -f

PROGRAM_NAME	= my_str_next_token

SRC				= main.c \
				  my_str_next_token.c \
				  my_putstr.c \
				  my_putchar.c

OBJ				= $(SRC:.c=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(PROGRAM_NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ)

re: fclean all

.PHONY: all $(PROGRAM_NAME) clean fclean re