/*
** ETNA PROJECT, 14/11/2018 by soubri_j
** enemy.c
** File description: 
**      This file contains all methods to manage enemy creation
*/

#include "ftl.h"
static const int percent_enemy_appears = 30;
static const int percent_enemy_breaks = 20;
static int enemy_damage = 10;
static int enemy_life = 20;

static const damage_command_t damage_commands[] =
{
    {"ftl_drive", damage_ftl_drive},
    {"navigation_tools", damage_navigation_tools},
    {"weapon", damage_weapon},
    {NULL, NULL}
};

/*
    Function used to generate an enemy. 30% chance to appear
    Returns :
        An enemy if appears, NULL otherwise
*/
rebel_enemy_t *generate_enemy()
{
    int percent = 0;
    rebel_enemy_t *rebel = NULL;

    percent = (random() % 100);
    if (percent <= percent_enemy_appears) {
        rebel = malloc(sizeof(*rebel));
        if (rebel != NULL) {
            rebel->damage = enemy_damage;
            rebel->life = enemy_life;
            my_putstr_color(ko_color, "Enemy appears in this sector\n");
        }
    }
    return rebel;
}

/*
    Function used to simulate an enemy attack. When an enemy attack
    a ship, we take account of its evade value. If the enemy hits the ship,
    it has 20% chance to damage a random system.
    Params : 
        ship : The attacked ship
        rebel : The rebel enemy attacking
*/
void enemy_attack(ship_t *ship, rebel_enemy_t *rebel)
{
    int percent_hit = 0;
    int percent_break = 0;
    int system_broke = 0;

    if (ship != NULL && rebel != NULL) {
        my_putstr_color(info_color, "ennemy attacking\n");
        percent_hit = (random() % 100);
        play_sound("attack");
        if (percent_hit > ship->nav_tools->evade) {
            percent_break = (random() % 100);
            ship->hull -= rebel->damage;
            my_putstr_color(ko_color, "Enemy damages your ship!!!\n");
            if (percent_break <= percent_enemy_breaks) {
                system_broke = (random() % 3);
                damage_commands[system_broke].damage_fct(ship);
            }
        } else {
            my_putstr_color(ok_color, "Your ship evades enemy shoots\n");
        }
    }
}

/*
    Function used to increase enemy statistics after death
*/
void reenforce_enemy_stats()
{
    enemy_damage += enemy_damage * 0.5;
    enemy_life += enemy_life * 0.5;
}