/*
** ETNA PROJECT, 12/11/2018 by soubri_j
** container.c
** File description: 
**      This file contains all the methods used to manage a container.
*/

#include "ftl.h"

/*
    Function used to add a container to a ship
    Params : 
        ship : The ship to add container to
    Returns :
        1 if ok, 0 otherwise
*/
int add_container_to_ship(ship_t *ship)
{
    int ret = 0;

    my_putstr_color(info_color, "adding the current container...\n");
    if (ship != NULL) {
        ship->container = malloc(sizeof(*ship->container));
        if (ship->container != NULL) {
            ship->container->first = NULL;
            ship->container->last = NULL;
            ship->container->nb_elem = 0;
            ret = 1;
        }
    }
    if (ret == 0) {
        my_putstr_color(ko_color, 
            "your ship exploded when you put the container down\n");
    } else if (ret == 1) {
        my_putstr_color(ok_color, "the container was successfully added\n");
    }
    return (ret);
}

/*
    Function used to add freight to a container in a ship.
    Params :
        ship : The ship that contains the container to add the freight to
        freight : The freight to add to ship's container
*/
void add_freight_to_container(ship_t *ship, freight_t *freight)
{
    if (ship != NULL && ship->container != NULL && freight != NULL) {
        if (ship->container != NULL) {
            if (ship->container->nb_elem == 0) {
                freight->next = freight;
                freight->prev = freight;
                ship->container->first = freight;
                ship->container->last = freight;
            } else {
                freight->next = ship->container->first;
                freight->prev = ship->container->last;
                ship->container->last->next = freight;
                ship->container->first->prev = freight;
                ship->container->first = freight;
            }
            ship->container->nb_elem++;
        }
    }
}

/*
    Function used to remove a freight from a container in a ship
    Params :
        ship : The ship containing the container to remove freight from
*/
void del_freight_from_container(ship_t *ship, freight_t *freight)
{
    if (ship != NULL && ship->container != NULL && freight != NULL) {
        freight->next->prev = freight->prev;
        freight->prev->next = freight->next;
        if (freight == ship->container->first) {
            ship->container->first = freight->next;
        } else if (freight == ship->container->last) {
            ship->container->last = freight->prev;
        }
        freight->next = NULL;
        freight->prev = NULL;
        free(freight->item);
        free(freight);
        ship->container->nb_elem--;
        if (ship->container->nb_elem <= 0) {
            ship->container->first = NULL;
            ship->container->last = NULL;
        }
    }
}

/*
    Function use to apply a bonus to the ship.
    If freight contains attackbonus then add 5 to damage.
    If freight contains evadebonus then add 3 to evade.
    If freight contains energy then add 1 to energy.
    If a bonus is applied, then remove the freight from
    the container.
    Params : 
        ship : The ship to apply bonus to
        freight : The freight to check
    Returns : 
        A pointer to the next freight
*/
freight_t* apply_bonus(ship_t *ship, freight_t *freight) 
{
    freight_t *ptr = freight;

    if (ship != NULL && freight != NULL) {
        ptr = freight->next;
        if (my_strcmp(freight->item, "attackbonus") == 0) {
            ship->weapon->damage += 5;
        } else if (my_strcmp(freight->item, "evadebonus") == 0) {
            ship->nav_tools->evade += 3;
        } else if (my_strcmp(freight->item, "energy") == 0) {
            ship->engine->energy += 1;
        }
        del_freight_from_container(ship, freight);
    }
    return (ptr);
}

/*
    Function used to apply bonus of all items in a container of a ship
    Params : 
        ship : The ship to apply bonus to
*/
void get_bonus(ship_t *ship)
{
    freight_t *ptr = NULL;
    int nb_elem = 0;

    if (ship != NULL && ship->container != NULL) {
        ptr = ship->container->first;
        nb_elem = ship->container->nb_elem;
        if (nb_elem > 0)
            play_sound("getbonus");
        for (int i = 0; i < nb_elem; ++i) {
            ptr = apply_bonus(ship, ptr);
        }    
    }
}