CFLAGS					= -Wall -Wextra -Werror

CC						= gcc

RM						= rm -f

PROGRAM_NAME			= my_rm_all_eq_from_list

SRC						= main.c \
						  my_rm_all_eq_from_list.c \
						  my_put_elem_in_sort_list.c

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