##
## ETNA PROJECT, 12/11/2018 by soubri_j
## Makeflile
## File description: 
##      Makefile for my_ftl.
##

CFLAGS				= -Wall -Wextra -Werror

CC					= gcc

##LINKER_FLAGS		= $(shell sdl-config --libs sdl2 sdl2_image sdl2_mixer)

CC_LIB_PATH			= -I/Library/Frameworks/SDL2.framework/Headers

CC_SDL				= -F/Library/Frameworks -framework SDL2

CC_SDL_IMAGE		= -F/Library/Frameworks/SDL2_image.framework/Headers -framework SDL2_image

CC_SDL_MIXER		= -F/Library/Frameworks/SDL2_mixer.framework/Headers -framework SDL2_mixer

RM					= rm -f

PROGRAM_NAME		= my_ftl

SRC					= main.c \
					  my_readline.c \
					  my_string.c \
					  air_shed.c \
					  container.c \
					  system_control.c \
					  system_repair.c \
					  stat.c \
					  enemy.c \
					  system_damage.c \
					  other_actions.c \
					  game_loop.c \
					  sdl_usage.c \
					  sdl_effects.c

OBJ					= $(SRC:.c=.o)

all: $(PROGRAM_NAME)
	

$(PROGRAM_NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(PROGRAM_NAME) $(CC_LIB_PATH) $(CC_SDL) $(CC_SDL_IMAGE) $(CC_SDL_MIXER)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(PROGRAM_NAME)

re: fclean all

.PHONY: all $(PROGRAM_NAME) clean fclean re