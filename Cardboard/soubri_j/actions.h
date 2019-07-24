/*
** ETNA PROJECT, 24/10/2018 by soubri_j
** interactions.h
** File description:
**      File containing headers for actions between characters and map.
*/
#ifndef __ACTIONS_H__
# define __ACTIONS_H__
#include "map.h"
void print_interaction_with_character(character_t *character, 
                                        char *action, character_t *other);
void destroy_camera(void *env, void *player, void *data);
void kill_character(void *env, void *player, void *data);
void (*actions[NB_CHARACTERS_TYPE]) = { kill_character, kill_character, 
                                        destroy_camera, kill_character };
#endif //!__ACTIONS_H__