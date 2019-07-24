/*
** ETNA PROJECT, 12/11/2018 by soubri_j
** air_shed.c
** File description: 
**      This file contains all the methods used to manage a ship.
*/

#include "ftl.h"

/*
    Function used ti create a ship
    Returns :
        The created ship if ok, NULL otherwise
*/
ship_t* create_ship() 
{
    ship_t* ship = NULL;

    my_putstr_color(info_color, "building of the ship in progress...\n");
    ship = malloc(sizeof(*ship));
    if (ship != NULL) {
        ship->hull = 50;
        ship->weapon = NULL;
        ship->engine = NULL;
        ship->nav_tools = NULL;
        ship->container = NULL;
        my_putstr_color(ok_color, "ship improvement is finished!\n");
    } else {
        my_putstr_color(ko_color, 
            "the ship could not be built due to lack of materials\n");
    }
    return (ship);
}

/*
    Function used to add a weapon to a ship
    Params : 
        ship : The ship to add the weapon to
    Returns : 
        1 if ok, 0 otherwise
*/
int add_weapon_to_ship(ship_t *ship) 
{
    int ret = 0;

    my_putstr_color(info_color, "adding weapon in progress...\n");
    if (ship != NULL) {
        ship->weapon = malloc(sizeof(*ship->weapon));
        if (ship->weapon != NULL) {
            ship->weapon->damage = 10;
            ship->weapon->system_state = my_strdup("online");
            if (ship->weapon->system_state != NULL) {
                ret = 1;
            }
        }
    }
    if (ret == 0) {
        my_putstr_color(ko_color, 
            "your ship exploded when you tried to add the weapons\n");
    } else if (ret == 1) {
        my_putstr_color(ok_color, 
            "weapons were successfully added!\n");
    }
    return (ret);
}

/*
    Function used to add an engine to a ship
    Params : 
        ship : The ship to add the engine to
    Returns : 
        1 if ok, 0 otherwise
*/
int add_ftl_drive_to_ship(ship_t *ship)
{
    int ret = 0;

    my_putstr_color(info_color, "adding the reactor in progress...\n");
    if (ship != NULL) {
        ship->engine = malloc(sizeof(*ship->engine));
        if (ship->engine != NULL) {
            ship->engine->energy = 10;
            ship->engine->system_state = my_strdup("online");
            if (ship->engine->system_state != NULL) {
                ret = 1;
            }
        }
    }
    if (ret == 0) {
        my_putstr_color(ko_color, 
            "your ship exploded when you put the reactor in\n");
    } else if (ret == 1) {
        my_putstr_color(ok_color, "the reactor was successfully added!\n");
    }
    return (ret);
}

/*
    Function used to add navigation tools to a ship
    Params : 
        ship : The ship to add navigation tools to
    Returns : 
        1 if ok, 0 otherwise
*/
int add_navigation_tools_to_ship(ship_t *ship)
{
    int ret = 0;

    my_putstr_color(info_color, "adding navigation tools...\n");
    if (ship != NULL) {
        ship->nav_tools = malloc(sizeof(*ship->nav_tools));
        if (ship->nav_tools != NULL) {
            ship->nav_tools->sector = 0;
            ship->nav_tools->evade = 25;
            ship->nav_tools->system_state = my_strdup("online");
            if (ship->nav_tools->system_state != NULL) {
                ret = 1;
            }
        }
    }
    if (ret == 0) {
        my_putstr_color(ko_color, 
            "your ship exploded when you put in the navigation tools\n");
    } else if (ret == 1) {
        my_putstr_color(ok_color, "navigation tools were successfully added\n");
    }
    return (ret);
}

/*
    Function used to check if ship has exploded or not.
    If ship has exploded. It free the memory and return NULL in ship variable.
    Params :
        ship : The ship to check
*/
void check_ship_hull(ship_t **ship)
{
    if (ship != NULL && *ship != NULL) {
        if ((*ship)->hull <= 0) {
            while ((*ship)->container->first != NULL) {
                del_freight_from_container(*ship, (*ship)->container->first);
            }
            free((*ship)->container);
            free((*ship)->engine->system_state);
            free((*ship)->engine);
            free((*ship)->nav_tools->system_state);
            free((*ship)->nav_tools);
            free((*ship)->weapon->system_state);
            free((*ship)->weapon);
            free((*ship));
            *ship = NULL;
            my_putstr_color(ko_color, "BOOM!!! Your ship explode in space!\n");
        }
    }
}