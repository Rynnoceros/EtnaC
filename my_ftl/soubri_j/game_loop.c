/*
** ETNA PROJECT, 13/11/2018 by soubri_j
** game_loop.c
** File description: 
**      This file contains all methods to manage game loop.
*/

#include "ftl.h"

static const user_action_t user_actions[] = {
    {"attack", attack_enemy},
    {"detect", detect_space_treasures},
    {"jump", jump_into_hyperspace},
    {"getbonus", get_bonus},
    {"repair_system", system_repair},
    {"control_system", system_control},
    {"stat" , display_stats },
    {NULL, NULL}
};

/*
    Function used to ask user's next action and then execute it
    Params :
        ship : The ship tha will execute actions
*/
void actions(ship_t *ship)
{
    char *user_input = NULL;
    int cpt = 0;

    my_putstr_color(input_color, "What's your next action : ");
    user_input = my_readline();
    while (user_actions[cpt].action != NULL) {
        if (my_strcmp(user_input, user_actions[cpt].action) == 0) {
            user_actions[cpt].action_fct(ship);
            break;
        }
        ++cpt;
    }
    if (user_actions[cpt].action == NULL) {
        my_putstr_color(ko_color, 
            "Incorrect action! Please select one of these(");
        cpt = 0;
        while (user_actions[cpt].action != NULL) {
            my_putstr_color(ko_color, user_actions[cpt].action);
            my_putstr_color(ko_color, ", ");
            cpt++;
        }
        my_putstr_color(ko_color, ")\n");
    }
}

/*
    Function used to create a ship and initialize all its
    system controls
    Returns : 
        The ship created if ok, NULL otherwise
*/
ship_t* initialize_ship()
{
    ship_t *ship = NULL;

    ship = create_ship();
    if (add_container_to_ship(ship) == 0) {
        ship = NULL;
    } else if (add_ftl_drive_to_ship(ship) == 0) {
        ship = NULL;
    } else if (add_navigation_tools_to_ship(ship) == 0) {
        ship = NULL;
    } else if (add_weapon_to_ship(ship) == 0) {
        ship = NULL;
    }
    return (ship);
}

/*
    Game loop. Create the ship and the game environnement and let
    the user play until game over.
*/
void game(play_screen_t *the_game) 
{
    ship_t *player = NULL;
    rebel_enemy_t *enemy_before = NULL;
    rebel_enemy_t *enemy_after = NULL;

    player = initialize_ship();
    while (player != NULL && player->engine->energy > 0 && 
        player->nav_tools->sector < 10) {
        enemy_before = get_enemy();
        actions(player);
        if (player->nav_tools->sector >= 10) {
            refresh_display(the_game, player, enemy_before, enemy_after);
            SDL_Delay(2000);
            my_putstr_color(ok_color, "YOU WIN!!!!\n");
            break;
        }
        enemy_after = get_enemy();
        enemy_attack(player, enemy_after);
        check_ship_hull(&player);
        refresh_display(the_game, player, enemy_before, enemy_after);
    }
    if (player == NULL || (player != NULL && player->engine->energy <= 0 
        && player->nav_tools->sector < 10)) {
        my_putstr_color(ko_color, "YOU LOOSE! TRY AGAIN!\n");
    }
}