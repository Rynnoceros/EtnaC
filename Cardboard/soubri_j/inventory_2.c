/*
** ETNA PROJECT, 19/10/2018 by soubri_j
** inventory_2.c
** File description: 
**      File containing all functions to manage an inventory for
**      Cardboard Pulley Training.
*/
#include "inventory.h"
#include "position.h"

/*
    Function that returns the first item of type type, NULL otherwise.
    Params :
        inv : Inventory where to find the item
        type : Item's seeked type
    Returns :
        The first item found, NULL otherwise.
*/
item_t *find_first_in_inventory(inventory_t *inv, item_type_t type)
{
    item_t *ptr = NULL;
    item_t *item_to_return = NULL;

    if (inv != NULL) {
        ptr = malloc(sizeof(ptr));
        if (ptr != NULL) {
            ptr = inv->items;
            for (int i = 0; i < inv->nb_items && item_to_return == NULL; ++i) {
                if (ptr->type == type) {
                    item_to_return = malloc(sizeof(item_to_return));
                    if (item_to_return != NULL)
                        item_to_return = ptr;
                } else {
                    ptr = ptr->next;
                }
            }
        }
    }
    return item_to_return;
}

/*
    Function to display the content of an inventory
    Params : 
        inv : Inventory to display
        print_reverse : Display in reverse order
*/
void print_inventory(inventory_t *inv)
{
    item_t *ptr = NULL;

    if (inv != NULL) {
        ptr = malloc(sizeof(ptr));
        if (ptr != NULL) {
            ptr = inv->items;
            for (int i = 0; i < inv->nb_items; ++i) {
                print_item(ptr);
                ptr = ptr->next;
            }
        }
    }
}