/*
** ETNA PROJECT, 19/10/2018 by soubri_j
** item.h
** File description: 
**      File containing headers of items functions management for
**      Cardboard Pulley Training.
*/
#ifndef __ITEM_H__
# define __ITEM_H__
#include <stdlib.h>

/**** Variable ****/
#define ITEM_TYPES ((char *[]) { "key", "door", "gun", "knife" })
#define ITEM_DISPLAY ((char []) { 'K', 'H', 'b', 'J' })
#define NB_ITEM_TYPE 4

/* Structure and enumerations */
typedef enum item_type_e {
    E_KEY,
    E_DOOR,
    E_GUN,
    E_KNIFE
} item_type_t;

typedef struct item_s {
    int id;
    item_type_t type;
    int coord[2];
    struct item_s *next;
    struct item_s *previous;
    void (*interact)();
} item_t;

/* Functions declaration */
void print_item(item_t *item);
item_t *new_item(int id, item_type_t type, int coord[2]);
#endif //!__ITEM_H__