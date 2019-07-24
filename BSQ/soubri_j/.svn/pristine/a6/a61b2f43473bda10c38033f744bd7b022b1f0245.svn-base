CFLAGS			= -Wall -Wextra -Werror

CC				= gcc

RM				= rm -f

LIB				= bonus/libmy.a

PROGRAM_NAME	= bsq

SRC				= main_bsq.c \
				  main_functions_bsq.c \
				  map_functions_bsq.c \
				  file_functions_bsq.c 


OBJ				= $(SRC:.c=.o)

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $(PROGRAM_NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PROGRAM_NAME)

re: fclean all

.PHONY: all $(PROGRAM_NAME) clean fclean re