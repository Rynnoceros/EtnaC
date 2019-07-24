/*
** ETNA PROJECT, 12/11/2018 by soubri_j
** ftl.h
** File description: 
**      This file contains all structure definitions, and functions header
**      for my_ftl.
*/

#ifndef __FTL_H__
# define __FTL_H__
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

/* Structure definitions */
typedef struct weapon_s {
    char *system_state;
    int damage;
} weapon_t;

typedef struct ftl_drive_s {
    char *system_state;
    int energy;
} ftl_drive_t;

typedef struct navigation_tools_s {
    char *system_state;
    int sector;
    int evade;
} navigation_tools_t;

typedef struct freight_s {
    char *item;
    struct freight_s *next;
    struct freight_s *prev;
} freight_t;

typedef struct container_s {
    freight_t *first;
    freight_t *last;
    int nb_elem;
} container_t;

typedef struct ship_s {
    int hull;
    weapon_t *weapon;
    ftl_drive_t *engine;
    navigation_tools_t *nav_tools;
    container_t *container;
} ship_t;

typedef struct repair_command_s {
    char *command;
    void (*command_fct)(ship_t *);
} repair_command_t;

typedef struct damage_command_s {
    char *system;
    void (*damage_fct)(ship_t *);
} damage_command_t;

typedef struct user_action_s {
    char *action;
    void (*action_fct)(ship_t *);
} user_action_t;

typedef struct rebel_enemy_s {
    int damage;
    int life;
} rebel_enemy_t;

typedef struct audio_s {
    char *name;
    SDL_AudioSpec wav_spec;
    SDL_AudioDeviceID audio_id;
    Uint32 wav_length;
    Uint8 *wav_buffer;
} audio_t;

typedef struct play_screen_s {
    SDL_Window *window;
    SDL_Surface *screen_surface;
    SDL_Surface *ship_surface;
    SDL_Surface *enemy_surface;
    SDL_Surface *explosion_surface;
    SDL_Surface *sectors[10];
    SDL_Surface *current_sector;
    SDL_Rect enemy_rect;
    SDL_Rect ship_rect;
    Mix_Music *music;
    audio_t *sound_lib[10];
} play_screen_t;

/* Global variable */
static const char ok_color[] = "green";
static const char ko_color[] = "red";
static const char info_color[] = "yellow";
static const char input_color[] = "blue";

/* Functions headers */
void my_putchar(const char c);
void my_putstr_color(const char *color, const char *str);
void my_putnbr(int n);
char *my_readline(void);
char *my_strdup(const char *str);
int my_strcmp(const char *s1, const char *s2);
ship_t* create_ship();
int add_weapon_to_ship(ship_t *ship);
int add_ftl_drive_to_ship(ship_t *ship);
int add_navigation_tools_to_ship(ship_t *ship);
int add_container_to_ship(ship_t *ship);
void add_freight_to_container(ship_t *ship, freight_t *freight);
void del_freight_from_container(ship_t *ship, freight_t *freight);
void get_bonus(ship_t *ship);
void ftl_drive_system_check(ship_t *ship);
void navigation_tools_system_check(ship_t *ship);
void weapon_system_check(ship_t *ship);
void system_control(ship_t *ship);
void ftl_drive_system_repair(ship_t *ship);
void navigation_tools_system_repair(ship_t *ship);
void weapon_system_repair(ship_t *ship);
void system_repair(ship_t *ship);
void display_stats(ship_t *ship);
void game(play_screen_t *the_game);
void damage_ftl_drive(ship_t *ship);
void damage_navigation_tools(ship_t *ship);
void damage_weapon(ship_t *ship);
void enemy_attack(ship_t *ship, rebel_enemy_t *rebel);
void check_ship_hull(ship_t **ship);
void jump_into_hyperspace(ship_t *ship);
void detect_space_treasures(ship_t *ship);
void attack_enemy(ship_t *ship);
void reenforce_enemy_stats();
rebel_enemy_t *generate_enemy();
rebel_enemy_t *get_enemy();
void init_sdl(play_screen_t *the_game);
void load_images(play_screen_t *the_game);
void close_sdl(play_screen_t *the_game);
void refresh_display(play_screen_t *the_game, ship_t *ship, 
                    rebel_enemy_t *enemy_before, rebel_enemy_t *enemy_after);
void play_explosion(play_screen_t *the_game, SDL_Rect *rect, ship_t *ship);
audio_t *load_sound(const char *name, const char *sound_path);
void load_sound_lib(play_screen_t *the_game);
void play_sound(const char *sound_name);
void free_sounds(play_screen_t *the_game);
play_screen_t *get_game();
#endif