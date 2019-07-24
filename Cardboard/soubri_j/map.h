/*
** ETNA PROJECT, 19/10/2018 by soubri_j
** map.h
** File description: 
**      Header containing all functions and typedef declarations to manage
**      a map for Cardboard Pulley Training.
*/
#ifndef __MAP_H__
# define __MAP_H__
#include "libmy.h"
#include "inventory.h"
#include "character.h"

#define EMPTY_SPACE '.'

typedef struct {
    char *ground;
} tile_t;

typedef struct {
    int width;
    int nb_characters;
    inventory_t *items;
    character_t **characters;
    tile_t **map;
} map_t;

map_t *generate_random_map(int nb_tiles, int nb_items, int nb_characters);
void adding_random_items_on_map(map_t *map, int nb_items);
void adding_random_characters_on_map(map_t *map, int nb_characters);
void add_item_on_map(map_t *map, item_type_t type, int id, int coord[2]);
void add_character_to_map(map_t *map, character_t *to_add);
character_t *remove_character_from_map(map_t *map, int id);
void loading_map(map_t *map);
void display_map(map_t *map);
#endif //!__MAP_H__