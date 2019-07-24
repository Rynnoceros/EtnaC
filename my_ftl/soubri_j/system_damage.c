/*
** ETNA PROJECT, 14/11/2018 by soubri_j
** system_damage.c
** File description: 
**      This file contains all the methods used to damage ship systems.
*/

#include "ftl.h"

/*
    Function used to damage ftl drive.
    Params :
        ship : The ship to damage
*/
void damage_ftl_drive(ship_t *ship)
{
    if (ship != NULL) {
        free(ship->engine->system_state);
        ship->engine->system_state = my_strdup("breaked down");
        my_putstr_color(ko_color, "Ftl drive broke down\n");
    }
}

/*
    Function used to damage navigation tools.
    Params :
        ship : The ship to damage
*/
void damage_navigation_tools(ship_t *ship)
{
    if (ship != NULL) {
        free(ship->nav_tools->system_state);
        ship->nav_tools->system_state = my_strdup("breaked down");
        my_putstr_color(ko_color, "Navigation tools broke down\n");
    }
}

/*
    Function used to damage weapon.
    Params :
        ship : The ship to damage
*/
void damage_weapon(ship_t *ship)
{
    if (ship != NULL) {
        free(ship->weapon->system_state);
        ship->weapon->system_state = my_strdup("breaked down");
        my_putstr_color(ko_color, "Weapon broke down\n");
    }
}