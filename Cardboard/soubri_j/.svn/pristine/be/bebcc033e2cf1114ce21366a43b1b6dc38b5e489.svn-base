/*
** ETNA PROJECT, 19/10/2018 by soubri_j
** inventory.h
** File description: 
**      Header containing all functions and typedef declarations to manage
**      an inventory for Cardboard Pulley Training.
*/
#ifndef __INVENTORY_H__
# define __INVENTORY_H__
#include "libmy.h"
#include "item.h"

/**** Structures and enumerations ****/
typedef struct {
    int nb_items;
    item_t *items;
} inventory_t;

/**** Functions declarations ****/
inventory_t *new_inventory();
void clear_inventory(inventory_t *inventory);
void add_to_inventory(inventory_t *inv, item_t *item);
item_t *remove_from_inventory(inventory_t *inv, int id);
item_t *find_in_inventory(inventory_t *inv, int id);
item_t *find_first_in_inventory(inventory_t *inv, item_type_t type);
void print_inventory(inventory_t *inv);
#endif // !__INVENTORY_H__