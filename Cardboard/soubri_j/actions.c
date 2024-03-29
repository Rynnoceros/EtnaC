/*
** ETNA PROJECT, 24/10/2018 by soubri_j
** actions.c
** File description:
**      File containing all actions between characters and map.
*/
#include "map.h"

/*
    Function to display action on screen
    Params :
        character : The character doing action
        action : The action done
        other : The character concerned by the action
*/
void print_interaction_with_character(character_t *character, 
                                        char *action, character_t *other)
{
    if (character != NULL && other != NULL) {
        my_putstr("character[");
        my_putnbr(character->id);
        my_putstr("] ");
        my_putstr(action);
        my_putchar(' ');
        my_putstr(CHARACTER_TYPES[other->type]);
        my_putchar('\n');
    }
}

/*
    Function to destroy a camera. If the player has a gun, it removes the gun
    from the inventory and it removes camera from the map.
    Params :
        env : The map
        player : The player trying to destroy the camara
        data : The camera to destroy
*/
void destroy_camera(void *env, void *player, void *data) 
{
    map_t *map = NULL;
    character_t *other_character = NULL;
    character_t *character = NULL;
    character_t *to_remove = NULL;
    item_t *gun = NULL;

    if (env != NULL && player != NULL && data != NULL) {
        map = (map_t *) env;
        other_character = (character_t *) data;
        character = (character_t *) player;

        gun = find_first_in_inventory(character->inventory, E_GUN);
        if (gun != NULL) {
            remove_from_inventory(character->inventory, gun->id);
            to_remove = remove_character_from_map(map, other_character->id);
            if (to_remove != NULL) {
                print_interaction_with_character(character, "destroy a", to_remove);
            }
        } else {
            print_interaction_with_character(character, "smile at", other_character);
        }
    }
}

/*
    Function to kill a character. If the player has a knife. It removes
    the knife from his inventory and remove the killed character from the map.
    Params :
        env : The map
        player : The killer
        data : The killed character
*/
void kill_character(void *env, void *player, void *data)
{
    map_t *map = NULL;
    character_t *other_character = NULL;
    character_t *character = NULL;
    character_t *to_remove = NULL;
    item_t *knife = NULL;
    
    if (env != NULL && player != NULL && data != NULL) {
        map = (map_t *) env;
        other_character = (character_t *) data;
        character = (character_t *) player;

        knife = find_first_in_inventory(character->inventory, E_KNIFE);
        if (knife != NULL) {
            remove_from_inventory(character->inventory, knife->id);
            to_remove = remove_character_from_map(map, other_character->id);
            if (to_remove != NULL) {
                print_interaction_with_character(character, "kill a", to_remove);
            }
        } else {
            print_interaction_with_character(character, "talk with a", other_character);
        }
    }
}