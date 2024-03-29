/*
** ETNA PROJECT, 24/10/2018 by soubri_j
** interactions.c
** File description:
**      File containing all actions between characters and map.
*/
#include "map.h"

/*
    Function to display action on screen
    Params :
        character : The character doing action
        action : The action done
        item : The item concerned by the action
*/
void print_interaction_with_item(character_t *character, 
                                 char *action, item_t *item)
{
    if (character != NULL && item != NULL) {
        my_putstr("character[");
        my_putnbr(character->id);
        my_putstr("] ");
        my_putstr(action);
        my_putchar(' ');
        my_putstr(ITEM_TYPES[item->type]);
        my_putchar('\n');
    }
}

/*
    Function used to pick up an item on a map. It adds the items in player
    inventory and it removes it from map.
    Params : 
        env : The map
        player : The player picking up the item
        data : The item to pick
*/
void pick_up(void *env, void *player, void *data)
{
    map_t *map = NULL;
    item_t *item = NULL;
    character_t *character = NULL;
    item_t *to_add = NULL;

    if (env != NULL && player != NULL && data != NULL) {
        map = (map_t *) env;
        item = (item_t *) data;
        character = (character_t *) player;

        to_add = remove_from_inventory(map->items, item->id);
        add_to_inventory(character->inventory, to_add);
        print_interaction_with_item(character, "picked up a", item);
    }    
}

/*
    Function to open a door. If the player has a key, it removes the key from
    inventory and it removes door from the map.
    Params :
        env : The map
        player : The player trying to open the door
        data : The door to open
*/
void open_door(void *env, void *player, void *data)
{
    map_t *map = NULL;
    item_t *item = NULL;
    character_t *character = NULL;
    item_t *key = NULL;

    if (env != NULL && player != NULL && data != NULL) {
        map = (map_t *) env;
        item = (item_t *) data;
        character = (character_t *) player;

        if (item->type != E_DOOR) {
            my_putstr("This is not a door you can't open it!\n");
        } else {
            key = find_first_in_inventory(character->inventory, E_KEY);
            if (key != NULL) {
                remove_from_inventory(character->inventory, key->id);
                remove_from_inventory(map->items, item->id);
                print_interaction_with_item(character, "open a", item);
            } else if (character->type == E_PLAYER) {
                my_putstr("You don't have a key! You can't open the door\n");
            }
        }
    }
}