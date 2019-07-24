/*
** ETNA PROJECT, 13/11/2018 by soubri_j
** system_repair.c
** File description: 
**      This file contains all the methods used to repair ship systems.
*/

#include "ftl.h"

static const repair_command_t repair_commands[] = 
{
    {"ftl_drive", ftl_drive_system_repair},
    {"navigation_tools", navigation_tools_system_repair},
    {"weapon", weapon_system_repair},
    {NULL, NULL}
};

/*
    Function used to repair ship's engine
    Params : 
        ship : The ship to repair
*/
void ftl_drive_system_repair(ship_t *ship)
{
    int ret = 0;

    my_putstr_color(info_color, "repair of the reactor in progress...\n");
    if (ship != NULL) {
        if (ship->engine != NULL) {
            if (ship->engine->system_state != NULL) {
                free(ship->engine->system_state);
            }
            ship->engine->system_state = my_strdup("online");
            if (ship->engine->system_state != NULL) {
                ret = 1;
            }
        }
    }
    if (ret == 0) {
        my_putstr_color(ko_color, "the reactor repairs failed\n");
    } else if (ret == 1) {
        my_putstr_color(ok_color, "repair complete! reactor system OK!\n");
    }
}

/*
    Function used to repair ship's navigation tools
    Params : 
        ship : The ship to repair
*/
void navigation_tools_system_repair(ship_t *ship)
{
    int ret = 0;

    my_putstr_color(info_color, "repair of the navigation tools system in progress...\n");
    if (ship != NULL) {
        if (ship->nav_tools != NULL) {
            if (ship->nav_tools->system_state != NULL) {
                free(ship->nav_tools->system_state);
            }
            ship->nav_tools->system_state = my_strdup("online");
            if (ship->nav_tools->system_state != NULL) {
                ret = 1;
            }
        }
    }
    if (ret == 0) {
        my_putstr_color(ko_color, "the navigation tools repairs failed\n");
    } else if (ret == 1) {
        my_putstr_color(ok_color, "repair complete! navigation tools system OK!\n");
    }
}

/*
    Function used to repair ship's weapon
    Params : 
        ship : The shp to repair
*/
void weapon_system_repair(ship_t *ship)
{
    int ret = 0;

    my_putstr_color(info_color, "repair of the weapon system in progress...\n");
    if (ship != NULL) {
        if (ship->weapon != NULL) {
            if (ship->weapon->system_state != NULL) {
                free(ship->weapon->system_state);
            }
            ship->weapon->system_state = my_strdup("online");
            if (ship->weapon->system_state != NULL) {
                ret = 1;
            }
        }
    }
    if (ret == 0) {
        my_putstr_color(ko_color, "the weapon system repairs failed\n");
    } else if (ret == 1) {
        my_putstr_color(ok_color, "repair complete! weapon system OK!\n");
    }
}

/*
    Function used to ask the user which part of the ship to repair
    and call the good method.
    Params : 
        ship :  The ship to repair
*/
void system_repair(ship_t *ship)
{
    char *command = NULL;
    int cpt = 0;

    if (ship != NULL) {
        my_putstr_color(input_color, "repair_system->");
        command = my_readline();
        if (command != NULL) {
            while (repair_commands[cpt].command != NULL) {
                if (my_strcmp(repair_commands[cpt].command, command) == 0) {
                    play_sound("repair");
                    repair_commands[cpt].command_fct(ship);
                    break;
                }
                ++cpt;
            }
            if (repair_commands[cpt].command == NULL) {
                my_putstr_color(ko_color, "[SYSTEM FAILURE]: unknown command\n");
            }
        } else {
            my_putstr_color(ko_color, 
                "[SYSTEM FAILURE]: the control reader is blocked\n");
        }
    }
}