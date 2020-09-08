/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** cave.h
*/

#ifndef CAVE_H
#define CAVE_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Cave*/

game_state_t analyse_eventcave(sfRenderWindow *window, game_t *game,
                                sfEvent *event, player_t *player);
game_state_t gest_pause(sfRenderWindow *window, game_t *game, sfEvent *event,
                        player_t *player);
game_state_t gest_inventory(sfRenderWindow *window, game_t *game,
                        sfEvent *event, player_t *player);

/*---------------------------------------------------------------------------*/

sprite_t *fill_sprite(char *);

/*---------------------------------------------------------------------------*/

void check_hitbox_cave(player_t *player, game_t *game);
void check_hitbox_box(player_t *player, game_t *game);
void handle_zoom(game_t *game, player_t *player);
void move_player(player_t *player, game_t *game);
void check_hitbox_cave_second_room_two(player_t *player);
void check_hitbox_cave_second_room_one(player_t *player);
void check_hitbox_cave_first_room_four(player_t *player);
void display_cave(sfRenderWindow *window, game_t *game, player_t *player);
game_state_t gest_fight(sfRenderWindow *window, sfEvent *event,
                        game_t *game, player_t *player);


#endif