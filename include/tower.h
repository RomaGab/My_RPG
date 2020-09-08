/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** tower.h
*/

#ifndef TOWER_H
#define TOWER_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Tower*/

game_state_t analyse_eventtower(sfRenderWindow *window, game_t *game,
                                sfEvent *event, player_t *player);
game_state_t give_gantlet(player_t *player, game_t *game);

/*---------------------------------------------------------------------------*/

void check_hitbox_tower(player_t *player);
void display_tower(sfRenderWindow *window, game_t *game, player_t *player);

#endif