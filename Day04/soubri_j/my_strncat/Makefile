CFLAGS			= -Wall -Wextra -Werror

CC				= gcc

RM				= rm -f

PROGRAM_NAME	= my_strncat

SRC 			= main.c \
				  my_strncat.c 

OBJ				= $(SRC:.c=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(PROGRAM_NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PROGRAM_NAME)

re: fclean all

.PHONY: all $(PROGRAM_NAME) clean fclean re