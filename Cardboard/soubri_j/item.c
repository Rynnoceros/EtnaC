/*
** ETNA PROJECT, 19/10/2018 by soubri_j
** item.c
** File description: 
**      File containing all functions to manage items for
**      Cardboard Pulley Training.
*/
#include "item.h"
#include "position.h"
#include "libmy.h"
#include "interactions.h"

/*
    Function used to create a new item.
    Params : 
        id : Item id
        type : Item type
        coord : Item position
    Returns : 
        The created item if ok, NULL otherwise
*/
item_t *new_item(int id, item_type_t type, int coord[2]) 
{
    item_t *item = NULL;

    item = malloc(sizeof(*item));
    if (item != NULL) {
        item->id = id;
        item->type = type;
        item->interact = interactions[type];
        item->next = NULL;
        item->previous = NULL;
        item->coord[E_X] = coord[E_X];
        item->coord[E_Y] = coord[E_Y];
    }
    return item;
}

/*
    Function to display the content of an item.
    Params :
        item : The item to display
*/
void print_item(item_t *item)
{
    if (item != NULL) {
        my_putstr("Item [");
        my_putnbr(item->id);
        my_putstr("]:");
        my_putstr(ITEM_TYPES[item->type]);
        my_putchar('\n');
    }
}