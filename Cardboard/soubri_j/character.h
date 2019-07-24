/*
** ETNA PROJECT, 18/10/2018 by soubri_j
** character.h
** File description:
**      Header containing all functions and typedef to manage a character in
**      Cardboard Pulley Training.
*/
#ifndef __CHARACTER_H__
# define __CHARACTER_H__
#include "libmy.h"
#include "inventory.h"
#include "position.h"

/**** Variables ****/
#define MOVEMENT_SPEED 1;
#define MOVEMENT_DIRECTION ((char *[]) { "up", "down", "left", "right" })
#define ORIENTATION ((char *[]) { "north", "east", "south", "west" })
#define CHARACTER_DISPLAY ((char []) { 'P', 'G', 'C', 'D' })
#define CHARACTER_TYPES ((char *[]) { "player", "guard", "camera", "dog" })
#define NB_CHARACTERS_TYPE 4
#define NB_DIRECTIONS 4

/**** Structures and enumerations ****/
typedef enum character_type_e {
    E_PLAYER,
    E_GUARD,
    E_CAMERA,
    E_DOG
} character_type_t;

typedef struct character_s {
    int id;
    character_type_t type;
    cardinal_point_t azimut;
    int coord[2];
    inventory_t *inventory;
    void (*interact)();
} character_t;

/**** Functions declarations ****/
int character_move(character_t *target, direction_t dir);
int character_look(character_t *target, cardinal_point_t cardinal_point);
void print_move(int id, direction_t dir);
void print_character_orientation(int id, cardinal_point_t cardinal_point);
character_t *new_character(int id, character_type_t type, 
                           cardinal_point_t looks, int coord[2]);
#endif // !__CHARACTER_H__