/*
** ETNA PROJECT, 19/10/2018 by soubri_j
** map.c
** File description: 
**      File containing all functions to manage a map for
**      Cardboard Pulley Training.
*/
#include "map.h"
#include "position.h"

/*
    Function that generate a random map for a game
    Params :
        nb_tiles : The width of the map in tiles
        nb_items : The number of items to place on the map
        nb_characters : The number of characters to place on the map
    Returns :
        The generated map if there was no problem, NULL otherwise.
*/
map_t *generate_random_map(int nb_tiles, int nb_items, int nb_characters)
{
    map_t *map_to_generate = NULL;
    int tiles_number = 0;
    int total_to_place = 0;

    if (nb_tiles > 0) {
        tiles_number = nb_tiles * nb_tiles;
        total_to_place = nb_items + nb_characters;
        if (total_to_place < tiles_number && total_to_place >= 0) {
            map_to_generate = malloc(sizeof(*map_to_generate));
            if (map_to_generate != NULL) {
                map_to_generate->map = 
                    malloc(sizeof(*map_to_generate->map) * nb_tiles);
                if (map_to_generate->map != NULL) {
                    map_to_generate->width = nb_tiles;
                    for (int i = 0; i < nb_tiles; ++i) {
                        map_to_generate->map[i] = 
                            malloc(sizeof(*map_to_generate->map) * nb_tiles);
                    }
                    adding_random_items_on_map(map_to_generate, nb_items);
                    adding_random_characters_on_map(map_to_generate, nb_characters);
                }
            }
        }
    }
    return map_to_generate;
}

/*
    Function to add items on a map
    Params :
        map : The map where to add items
        nb_items : Number of items to add on the map
*/
void adding_random_items_on_map(map_t *map, int nb_items)
{
    int x = 0;
    int y = 0;
    if (map != NULL) {
        map->items = new_inventory();
        for (int i = 0; i < nb_items; ++i) {
            x = (random() % map->width);
            y = (random() % map->width);
            add_to_inventory(map->items, new_item(i, random() % NB_ITEM_TYPE,
                             ((int []) { x, y })));
        }
    }
}

/*
    Function to add characters on a map
    Params :
        map : The map where to add characters
        nb_characters : Number of characters to add on the map
*/
void adding_random_characters_on_map(map_t *map, int nb_characters)
{
    int x = 0;
    int y = 0;
    if (map != NULL) {
        map->characters = malloc(sizeof(*map->characters) * nb_characters);
        if (map->characters != NULL) {
            for (int i = 0; i < nb_characters; ++i) {
                x = (random() % map->width);
                y = (random() % map->width);
                map->characters[i] = new_character(i, 
                    (random() % (NB_CHARACTERS_TYPE - 1)) + 1, 
                    random() % NB_DIRECTIONS, ((int []){x, y}));
            }
            map->nb_characters = nb_characters;
        }
    }
}

/*
    Function to load characters on the map
    Params :
        map : The map where to load characters
*/
void loading_characters(map_t *map)
{
    int x = 0;
    int y = 0;

    if (map->characters != NULL) {
        for (int i = 0; i < map->nb_characters; ++i) {
            x = map->characters[i]->coord[E_X];
            y = map->characters[i]->coord[E_Y];
            if (x < 0) {
                x = map->width - 1;
            } else if (x >= map->width) {
                x = 0;
            }
            if (y < 0) {
                y = map->width - 1;
            } else if (y >= map->width) {
                y = 0;
            }
            map->characters[i]->coord[E_X] = x;
            map->characters[i]->coord[E_Y] = y;
            *map->map[x][y].ground = 
                CHARACTER_DISPLAY[map->characters[i]->type];
        }
    }
}

/*
    Function to load map with items and characters. First fill the ground with
    empty spaces, then placing items and characters.
    Params :
        map : The map to display
*/
void loading_map(map_t *map)
{
    int x = 0;
    int y = 0;

    if (map != NULL) {
        if (map->map != NULL) {
            for (int i = 0; i < map->width; ++i) {
                for (int j = 0; j < map->width; ++j) {
                    map->map[i][j].ground = 
                        malloc(sizeof(*map->map[i][j].ground));
                    *map->map[i][j].ground = EMPTY_SPACE;
                }
            }
            if (map->items != NULL) {
                for (int i = 0; i < map->items->nb_items; ++i) {
                    x = map->items->items->coord[E_X];
                    y = map->items->items->coord[E_Y];
                    *map->map[x][y].ground = 
                        ITEM_DISPLAY[map->items->items->type];
                    if (map->items->items->next != NULL)
                        map->items->items = map->items->items->next;
                }
            }
            loading_characters(map);
        }
    }
}