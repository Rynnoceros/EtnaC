/*
** ETNA PROJECT, 13/11/2018 by soubri_j
** system_control.c
** File description: 
**      This file contains all the methods used to check ship systems.
*/

#include "ftl.h"

/*
    Function used to check if reactor is online.
    Params : 
        ship : The ship to check
*/
void ftl_drive_system_check(ship_t *ship)
{
    int ret = 0;

    my_putstr_color(info_color, "checking the reactor in progress...\n");
    if (ship != NULL) {
        if (ship->engine != NULL) {
            if (my_strcmp(ship->engine->system_state, "online") == 0) {
                ret = 1;
            }
        }
    }
    if (ret == 0) {
        my_putstr_color(ko_color, "reactor out of order!\n");
    } else if (ret == 1) {
        my_putstr_color(ok_color, "reactor OK!\n");
    }
}

/*
    Function used to check if navigation tools are operational
    Params : 
        ship : The ship to check
*/
void navigation_tools_system_check(ship_t *ship)
{
    int ret = 0;

    my_putstr_color(info_color, 
        "checking the navigation tools in progress...\n");
    if (ship != NULL) {
        if (ship->nav_tools != NULL) {
            if (my_strcmp(ship->nav_tools->system_state, "online") == 0) {
                ret = 1;
            }
        }
    }
    if (ret == 0) {
        my_putstr_color(ko_color, "navigation tools out of order!\n");
    } else if (ret == 1) {
        my_putstr_color(ok_color, "navigation tools OK!\n");
    }
}

/*
    Function used to check if weapon is operational
    Params : 
        ship : The ship to check
*/
void weapon_system_check(ship_t *ship)
{
    int ret = 0;

    my_putstr_color(info_color, "checking weapon system in progress...\n");
    if (ship != NULL) {
        if (ship->weapon != NULL) {
            if (my_strcmp(ship->weapon->system_state, "online") == 0) {
                ret = 1;
            }
        }
    }
    if (ret == 0) {
        my_putstr_color(ko_color, "weapon system out of order!\n");
    } else if (ret == 1) {
        my_putstr_color(ok_color, "weapon system OK!\n");
    }
}

/*
    Function used to check ship system control
    Params : 
        ship : The ship to check
*/
void system_control(ship_t *ship)
{
    play_sound("control");
    ftl_drive_system_check(ship);
    navigation_tools_system_check(ship);
    weapon_system_check(ship);
}