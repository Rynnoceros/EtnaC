CFLAGS					= -Wall -Wextra -Werror

CC						= gcc

RM						= rm -f

PROGRAM_NAME			= my_rev_list

SRC						= main.c \
						  my_rev_list.c \
						  ../my_params_in_list/my_params_in_list.c

OBJ						= $(SRC:.c=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(PROGRAM_NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PROGRAM_NAME)

re: fclean all

.PHONY: all $(PROGRAM_NAME) clean fclean re