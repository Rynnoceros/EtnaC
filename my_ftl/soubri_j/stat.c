/*
** ETNA PROJECT, 13/11/2018 by soubri_j
** stat.c
** File description: 
**      This file contains all methods to display ship stats.
*/

#include "ftl.h"

/*
    Function to select the good color to display messages
    Params :
        ok : The bool to check
    Returns :
        The color to display
*/
char *color_to_display(int ok)
{
    if (ok) {
        return my_strdup(ok_color);
    } else {
        return my_strdup(ko_color);
    }
}

/*
    Function used to display ship's engine stats
    Params : 
        ship : The ship to check
*/
void display_engine_stats(ship_t *ship)
{
    int engine_ok = 0;
    char *color = NULL;

    engine_ok = (my_strcmp(ship->engine->system_state, "online") == 0) ? 1 : 0;
    color = color_to_display(engine_ok);
    my_putstr_color(info_color, "engine : ");
    my_putstr_color(color, ship->engine->system_state);
    my_putstr_color(info_color, " (");
    my_putnbr(ship->engine->energy);
    my_putstr_color(info_color, " energies left)\n");
}

/*
    Function used to display navigation tools statistics
    Params : 
        ship : The ship to check
*/
void display_navigation_tools_stats(ship_t *ship)
{
    int nav_ok = 0;
    char *color = NULL;

    nav_ok = (my_strcmp(ship->nav_tools->system_state, "online") == 0) ? 1 : 0;
    color = color_to_display(nav_ok);
    my_putstr_color(info_color, "navigation tools : ");
    my_putstr_color(color, ship->nav_tools->system_state);
    my_putstr_color(info_color, " (");
    my_putnbr(ship->nav_tools->evade);
    my_putstr_color(info_color, "% chance to evade)\n");
}

/*
    Function used to display weapon statistics
    Params : 
        ship : The ship to check
*/
void display_weapon_stats(ship_t *ship)
{
    int weapon_ok = 0;
    char *color = NULL;

    weapon_ok = (my_strcmp(ship->weapon->system_state, "online") == 0) ? 1 : 0;
    color = color_to_display(weapon_ok);
    my_putstr_color(info_color, "weapon : ");
    my_putstr_color(color, ship->weapon->system_state);
    my_putstr_color(info_color, " (");
    my_putnbr(ship->weapon->damage);
    my_putstr_color(info_color, " damages)\n");
}

/*
    Function used to display ship's stats
    Params : 
        ship : The ship to check
*/
void display_stats(ship_t *ship)
{
    my_putstr_color("yellow", "checking ship stats...\n");
    if (ship != NULL) {
        if (ship->engine != NULL) {
            display_engine_stats(ship);
        }
        if (ship->nav_tools != NULL) {
            display_navigation_tools_stats(ship);
        }
        if (ship->weapon != NULL) {
            display_weapon_stats(ship);
        }
        my_putstr_color(info_color, "hull : ");
        my_putnbr(ship->hull);
        my_putstr_color(info_color, " life points\n");
    }
}