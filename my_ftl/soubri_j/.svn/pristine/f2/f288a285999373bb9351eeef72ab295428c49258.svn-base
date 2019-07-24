/*
** ETNA PROJECT, 15/11/2018 by soubri_j
** other_actions.c
** File description: 
**      This file contains user actions
*/

#include "ftl.h"
static rebel_enemy_t *enemy = NULL;
static int detection_done = 0;

/*
    Function used to jump into hyperspace. It is not possible
    to jump in this case : 
        * There is an enemy in sector
        * The ship's ftl_drive is broker
        * The ship's ftl_drive does not have enough energy.
    Params : 
        ship : The ship that tries to jump into hyperspace
*/
void jump_into_hyperspace(ship_t *ship)
{
    if (ship != NULL) {
        if (enemy != NULL) {
            my_putstr_color(ko_color, 
                "There is an enemy in the sector. You can't jump\n");
        } else {
            if (my_strcmp(ship->engine->system_state, "online") != 0) {
                my_putstr_color(ko_color, 
                    "Your ftl_drive is broken you can't jump!\n");
            } else if (ship->engine->energy <= 0) {
                my_putstr_color(ko_color, 
                    "Your ftl_drive does not have enough energy.\n");
            } else {
                play_sound("jump");
                my_putstr_color(ok_color, "To infiny and beyond !!!\n");
                ship->engine->energy--;
                ship->nav_tools->sector++;
                detection_done = 0;
                enemy = generate_enemy();
            }
        }
    }
}

/*
    Function used to generate random freight.
    For each freight_t structure generated, you will have a 70% chance of
    finding scrap and a 30% chance of finding 1 bonus among the three
    available (energy, attackbonus, evadebonus).
    Params : 
        ship : the ship harvesting freight
*/
void generate_random_freight(ship_t *ship)
{
    int item = 0;
    freight_t *freight = NULL;
    
    freight = malloc(sizeof(*freight));
    if (freight != NULL) {
        freight->item = my_strdup("scrap");
        item = (random() % 100);
        if (item <= 70) {
            my_putstr_color(info_color, "You found scrap\n");
        } else {
            item = (random() % 100);
            if (item < 33) {
                freight->item = my_strdup("energy");
            } else if (item < 66) {
                freight->item = my_strdup("attackbonus");
            } else if (item < 99) {
                freight->item = my_strdup("evadebonus");
            }
            my_putstr_color(ok_color, "You found ");
            my_putstr_color(ok_color,  freight->item);
            my_putchar('\n');
        }
        add_freight_to_container(ship, freight);
    }
}

/*
    Function used to detect treasures in space sector.
    It is not possible to detect in this case :
        * detection already been done
        * navigation_tools are broken
    Params : 
        ship : The ship detecting treasures
*/
void detect_space_treasures(ship_t *ship)
{
    if (ship != NULL) {
        if (detection_done > 0) {
            my_putstr_color(ko_color, 
                "You didn't detect anything else in this sector\n");
        } else if (my_strcmp(ship->nav_tools->system_state, "online") != 0) {
            my_putstr_color(ko_color, "Your navigation tools are broken! \n");
        } else {
            play_sound("sonar");
            for (int i = 0; i < 10; ++i) {
                generate_random_freight(ship);
            }
            detection_done = 1;
        }
    }
}

/*
    Function used to attack an enemy in a sector.
    Of course it is impossible to attack if there is no enemy and if
    weapon is broken.
    Params :
        ship : The ship attacking the enemy
*/
void attack_enemy(ship_t *ship)
{
    if (ship != NULL) {
        if (enemy == NULL) {
            my_putstr_color(ko_color, 
                "There is no enemy in this sector. You can't attack!\n");
        } else {
            if (my_strcmp(ship->weapon->system_state, "online") != 0) {
                my_putstr_color(ko_color, "Your weapon is broken!!!\n");
            } else {
                play_sound("attack");
                enemy->life -= ship->weapon->damage;
                my_putstr_color(ok_color, "You attack the enemy dealing ");
                my_putnbr(ship->weapon->damage);
                my_putstr_color(ok_color, " damages (");
                my_putnbr(enemy->life);
                my_putstr_color(ok_color, " life points left)\n");
                if (enemy->life <= 0) {
                    free(enemy);
                    enemy = NULL;
                    reenforce_enemy_stats();
                }
            }
        }
    }
}

/*
    Function used to get enemy
    Returns : 
        enemy if there is one, NULL otherwise
*/
rebel_enemy_t *get_enemy()
{
    return enemy;
}