/*
** ETNA PROJECT, 19/10/2018 by soubri_j
** inventory.c
** File description: 
**      File containing all functions to manage an inventory for
**      Cardboard Pulley Training.
*/
#include "inventory.h"
#include "position.h"

/*
    Function used to create an inventory
*/
inventory_t *new_inventory(){
    inventory_t *inventory = NULL;

    inventory = malloc(sizeof(*inventory));
    if (inventory != NULL) {
        inventory->items = NULL;
        inventory->nb_items = 0;
    }
    return inventory;   
}

/*
    Function that clear and free an inventory
    Params :
        inventory : Inventory to clear
*/
void clear_inventory(inventory_t *inventory)
{
    if (inventory != NULL) {
        inventory->items = NULL;
        free(inventory);
    }
    my_putstr("Inventory cleared\n");
}

/*
    Function that add an item to the inventory.
    Params : 
        inv : Inventory where to add the item
        item : The item to add in the inventory
*/
void add_to_inventory(inventory_t *inv, item_t *item)
{
    if (inv != NULL && item != NULL) {
        if (inv->items == NULL) {
            inv->items = malloc(sizeof(*inv->items));
            if (inv->items != NULL)
                inv->items = item;
        } else {
            if (item->previous == NULL)
                item->previous = malloc(sizeof(item->previous));
            if (item->previous != NULL) {
                if (inv->items->previous != NULL) {
                    item->previous = inv->items->previous;
                    inv->items->previous->next = item;
                } else {
                    inv->items->previous = item;
                    inv->items->next = item;
                    item->previous = inv->items;
                }
            }
            if (item->next == NULL) {
                item->next = malloc(sizeof(item->next));
            }
            if (item != NULL){
                item->next = inv->items;
            }
            if (inv->items->previous != NULL)
                inv->items->previous = item;
            inv->items = item;
        }
        inv->nb_items += 1;
    }
}

/*
    Function that removes from the inventory based on the id
    of the item and returns the removed item if found, NULL otherwise.
    Params : 
        inv : Inventory where to remove the item
        id : Id of the item to remove
    Returns :
        The item removed or NULL if not found
*/
item_t *remove_from_inventory(inventory_t *inv, int id)
{
    item_t *item_to_return = NULL;
    item_t *ptr = NULL;

    if (inv != NULL) {
        ptr = malloc(sizeof(ptr));
        if (ptr != NULL) {
            ptr = inv->items;
            for (int i = 0; i < inv->nb_items && item_to_return == NULL; ++i) {
                if (ptr->id == id) {
                    item_to_return = malloc(sizeof(item_to_return));
                    if (item_to_return != NULL) {
                        item_to_return = ptr;
                        if (inv->nb_items <= 1) {
                            inv->items = NULL;
                        } else if (inv->nb_items == 2) {
                            inv->items = ptr->next;
                            inv->items->next = NULL;
                            inv->items->previous = NULL;
                        } else {
                            inv->items = ptr->next;
                            ptr->next->previous = ptr->previous;
                            ptr->previous->next = ptr->next;
                        }
                        item_to_return->next = NULL;
                        item_to_return->previous = NULL;
                        inv->nb_items -= 1;
                    }
                } else {
                    ptr = ptr->next;
                }
            }
        }
    }
    return item_to_return;
}

/*
    Function that returns the item if found based on the id, NULL otherwise.
    Params : 
        inv : The inventory where to find the item
        id : The id of item to find
    Returns :
        The item found or NULL otherwise
*/
item_t *find_in_inventory(inventory_t *inv, int id)
{
    item_t *ptr = NULL;
    item_t *item_to_return = NULL;

    if (inv != NULL) {
        ptr = malloc(sizeof(ptr));
        if (ptr != NULL) {
            ptr = inv->items;
            for (int i = 0; i < inv->nb_items && item_to_return == NULL; ++i) {
                if (ptr->id == id) {
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
