/*
** ETNA PROJECT, 12/11/2018 by soubri_j
** main.c
** File description: 
**      This file contains my_ftl program loop.
*/

#include "ftl.h"
#include <time.h>

play_screen_t the_game;

play_screen_t *get_game()
{
   return &the_game;
}

int main(void) {
   init_sdl(&the_game);
   load_images(&the_game);
   srandom(time(NULL));
   game(&the_game);
   close_sdl(&the_game);

   return (0);
}