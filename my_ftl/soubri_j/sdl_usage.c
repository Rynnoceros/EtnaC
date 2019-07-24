/*
** ETNA PROJECT, 12/11/2018 by soubri_j
** sdl_usage.c
** File description: 
**      This file contains all sdl usage.
*/

#include "ftl.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h> 
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

SDL_Rect enemy_rect = 
{
    600, 0, 0, 0
};
SDL_Rect ship_rect = 
{
    600, 423, 0, 0
};

/*
    Function to init sdl
    Params : 
        the_game : Game parameters
*/
void init_sdl(play_screen_t *the_game)
{
    the_game->enemy_rect = enemy_rect;
    the_game->ship_rect = ship_rect;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        my_putstr_color(ko_color, "Impossible to run SDL\n");
    } else {
        the_game->window = SDL_CreateWindow("MY FTL", SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 
            SDL_WINDOW_SHOWN);
        if (the_game->window == NULL) {
            my_putstr_color(ko_color, "Error creating window's game\n");
        } else {
            the_game->screen_surface = SDL_GetWindowSurface(the_game->window);
            SDL_PumpEvents();
        }
    }
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    the_game->music = Mix_LoadMUS("sounds/corneria.mp3");
    if (the_game->music == NULL) {
        my_putstr_color(ko_color, "Can't load music\n");
    }
    Mix_PlayMusic(the_game->music, -1);
    load_sound_lib(the_game);
}

/*
    Function used to load every sector's background
    Params : 
        the_game : Game parameters
*/
void load_sectors(play_screen_t *the_game)
{
    the_game->sectors[0] = IMG_Load("images/sector0.jpg");
    the_game->sectors[1] = IMG_Load("images/sector1.jpg");
    the_game->sectors[2] = IMG_Load("images/sector2.jpg");
    the_game->sectors[3] = IMG_Load("images/sector3.jpg");
    the_game->sectors[4] = IMG_Load("images/sector4.jpg");
    the_game->sectors[5] = IMG_Load("images/sector5.jpg");
    the_game->sectors[6] = IMG_Load("images/sector6.jpg");
    the_game->sectors[7] = IMG_Load("images/sector7.jpg");
    the_game->sectors[8] = IMG_Load("images/sector8.jpg");
    the_game->sectors[9] = IMG_Load("images/sector9.jpg");
    the_game->current_sector = the_game->sectors[0];
}

/*
    Function used to load game's images
    Params : 
        the_game : Game parameters
*/
void load_images(play_screen_t *the_game)
{
    load_sectors(the_game);
    the_game->ship_surface = IMG_Load("images/Titan.png");
    the_game->enemy_surface = IMG_Load("images/enemy.png");
    the_game->explosion_surface = IMG_Load("images/explosion.png");
    if (the_game->ship_surface == NULL) {
        my_putstr_color(ko_color, "Can't load ship image\n");
    } else if (the_game->enemy_surface == NULL) {
        my_putstr_color(ko_color, "Can't load enemy image\n");
    } else if (the_game->explosion_surface == NULL) {
        my_putstr_color(ko_color, "Can't load explosion image\n");
    }
    SDL_BlitSurface(the_game->current_sector, NULL, the_game->screen_surface, NULL);
    SDL_BlitSurface(the_game->ship_surface, NULL, the_game->screen_surface, 
        &ship_rect);
    SDL_UpdateWindowSurface(the_game->window);
}

/*
    Function used to refresh elements on screen
    Params : 
        the_game : Game parameters
        ship : Player's ship
        enemy_before : Enemy before user action
        enemy_after : Enemy after user action
*/
void refresh_display(play_screen_t *the_game, ship_t *ship, 
                    rebel_enemy_t *enemy_before, rebel_enemy_t *enemy_after)
{
    if (ship != NULL) {
        if (ship->nav_tools->sector < 10) {
            the_game->current_sector = the_game->sectors[ship->nav_tools->sector];
            SDL_BlitSurface(the_game->sectors[ship->nav_tools->sector], 
                NULL, the_game->screen_surface, NULL);
        }
    }
    SDL_BlitSurface(the_game->ship_surface, NULL, the_game->screen_surface, 
        &ship_rect);
    if (enemy_after != NULL) {
        SDL_BlitSurface(the_game->enemy_surface, NULL, the_game->screen_surface, 
            &enemy_rect);
    } else if (enemy_before != NULL) {
        play_explosion(the_game, &enemy_rect, ship);
    }
    if (ship == NULL) {
        play_explosion(the_game, &ship_rect, ship);
    }
    SDL_UpdateWindowSurface(the_game->window);
}

/*
    Function used to terminate SDL
    Params : 
        the_game : Game's parameters
*/
void close_sdl(play_screen_t *the_game)
{
    for (int i = 0; i < 10; ++i) {
        SDL_FreeSurface(the_game->sectors[i]);
        the_game->sectors[i] = NULL;
    }
    Mix_FreeMusic(the_game->music);
    free_sounds(the_game);
    SDL_FreeSurface(the_game->ship_surface);
    SDL_FreeSurface(the_game->enemy_surface);
    SDL_FreeSurface(the_game->explosion_surface);
    SDL_FreeSurface(the_game->screen_surface);
    SDL_DestroyWindow(the_game->window);
    the_game->ship_surface = NULL;
    the_game->enemy_surface = NULL;
    the_game->explosion_surface = NULL;
    the_game->screen_surface = NULL;
    the_game->window = NULL;
    SDL_Quit();
}