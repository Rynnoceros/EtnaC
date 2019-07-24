/*
** ETNA PROJECT, 19/10/2018 by soubri_j
** map_2.c
** File description: 
**      File containing all functions to manage a map for
**      Cardboard Pulley Training.
*/
#include "map.h"
#include "position.h"

/*
    Function to display map on screen.
    Params :
        map : The map to display.
*/
void display_map(map_t *map)
{
    if (map != NULL) {
        if (map->map != NULL) {
            for (int i = 0; i < map->width;  ++i) {
                for (int j = 0; j < map->width; ++j) {
                    my_putchar(*map->map[j][i].ground);
                }
                my_putchar('\n');
            }
        }
    }
}

/*
    Function to add a new character on map
    Params :
        map : The map where to add the character
        to_add : The character to add
*/
void add_character_to_map(map_t *map, character_t *to_add)
{
    character_t **new = NULL;

    if (map != NULL && to_add != NULL) {
        if (map->characters == NULL)
            map->characters = malloc(sizeof(*map->characters));
        if (map->characters != NULL) {
            new = malloc(sizeof(*new) * (map->nb_characters + 1));
            if (new != NULL) {
                for (int i = 0; i < map->nb_characters ; ++i) {
                    new[i] = map->characters[i];
                }
                new[map->nb_characters] = to_add;
                map->nb_characters += 1;
                map->characters = new;
            }
        }
    }
}

/*
    Function to remove a character from a map.
    Params :
        map : The map where to remove the character
        id : Id of the character to remove
    Returns :
        The removed character if found, NULL otherwise
*/
character_t *remove_character_from_map(map_t *map, int id)
{
    character_t *to_remove = NULL;

    if (map != NULL && map->characters != NULL) {
        for (int i = 0; i < map->nb_characters; ++i) {
            if (map->characters[i]->id == id) {
                to_remove = map->characters[i];
            } else if (to_remove != NULL) {
                if (i > 0) {
                    map->characters[i-1] = map->characters[i];
                }
            }
        }
    }
    if (to_remove != NULL) {
        map->nb_characters -= 1;
    }
    return to_remove;
}

/*
    Function to add an item on a map
    Params :
        map : The map where to add the item
        type : The type of item to add
        id : Id of the item to add
        coord : Coordinates of the item to add
*/
void add_item_on_map(map_t *map, item_type_t type, int id, int coord[2])
{
    if (map != NULL) {
        if (map->items == NULL) {
            map->items = new_inventory();
        }
        if (map->items != NULL) {
            add_to_inventory(map->items, new_item(id, type, coord));
        }
    }
}