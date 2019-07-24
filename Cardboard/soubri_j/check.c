/*
** ETNA PROJECT, 24/10/2018 by soubri_j
** check.c
** File description:
**      File containing check functions.
*/
#include "check.h"

/*
    Function to check if there is interactions between characters
    and items on a map.
    Params : 
        map : The map to check
*/
void checking_interactions(map_t *map)
{   
    int x = 0;
    int y = 0;
    if (map != NULL && map->characters != NULL && map->items != NULL) {
        for (int i = 0; i < map->nb_characters; ++i) {
            for (int j = 0; j < map->items->nb_items; ++j) {
                x = map->characters[i]->coord[E_X];
                y = map->characters[i]->coord[E_Y];
                if (x == map->items->items->coord[E_X] && 
                    y == map->items->items->coord[E_Y]) {
                    map->items->items->interact(map, 
                        map->characters[i], map->items->items);
                }
                if (map->items->items != NULL && 
                    map->items->items->next != NULL)
                    map->items->items = map->items->items->next;
            }
        }
    }
}

/*
    Function to check if there is actions between characters
    on a map.
    Params : 
        map : The map to check
*/
void checking_actions(map_t *map)
{   
    int x = 0;
    int y = 0;
    if (map != NULL && map->characters != NULL && map->nb_characters > 1) {
        for (int i = 0; i < map->nb_characters; ++i) {
            for (int j = i + 1; j < map->nb_characters; ++j) {
                x = map->characters[i]->coord[E_X];
                y = map->characters[i]->coord[E_Y];
                if (x == map->characters[j]->coord[E_X] && 
                    y == map->characters[j]->coord[E_Y]) {
                    if (map->characters[i]->type == E_PLAYER) {
                        map->characters[j]->interact(map, 
                            map->characters[i], map->characters[j]);
                    } else {
                        map->characters[i]->interact(map, 
                            map->characters[j], map->characters[i]);
                    }
                }
            }
        }
    }
}