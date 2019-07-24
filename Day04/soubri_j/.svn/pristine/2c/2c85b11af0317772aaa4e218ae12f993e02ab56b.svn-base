CFLAGS 			= -Wall -Wextra -Werror
CC 				= gcc
PROGRAM_NAME 	= my_strcmp

RM 				= rm -f

SRC 			= 	main.c \
					my_strcmp.c

OBJ 			= $(SRC:.c=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(PROGRAM_NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PROGRAM_NAME)

.PHONY: all $(PROGRAM_NAME) clean fclean