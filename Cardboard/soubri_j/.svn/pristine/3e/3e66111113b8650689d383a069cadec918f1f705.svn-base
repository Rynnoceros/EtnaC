CFLAGS				= -Wall -Wextra -Werror -std=c99
CC					= gcc
RM					= rm -f
PROGRAM_NAME		= main
LIBRARY_NAME		= ../libnot_rp1.a
SRC					= main.c	
OBJ					= $(SRC:.c=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBRARY_NAME) -o $(PROGRAM_NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PROGRAM_NAME)

re: fclean all

.PHONY: all $(PROGRAM_NAME) clean fclean re

