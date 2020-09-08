/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** player.h
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Player*/

sprite_t *fill_sprite(char *str);

/*---------------------------------------------------------------------------*/

game_state_t chose_skin(float click_x, float click_y, player_t *player,
                        skin_t *skin);
game_state_t analyse_eventplayer(sfRenderWindow *window, sfEvent *event,
                                    player_t *player, skin_t *skin);
game_state_t display_player_back(sfRenderWindow *window, skin_t *skin,
                                game_state_t scene);
game_state_t rm_draw_laser(sfRenderWindow *window, game_state_t scene,
                            skin_t *skin);

game_state_t gest_class(player_t *player, sfRenderWindow *window,
                        sfEvent *event);

/*---------------------------------------------------------------------------*/

clocks_t *fill_time(void);

/*---------------------------------------------------------------------------*/

void free_skin(skin_t *skin);
void free_class(class_t *class);
void free_sprite(sprite_t *sprite);
void move_parallax_skin(skin_t *skin, sfRenderWindow *window);
void display_back_class(sfRenderWindow *window, class_t *class);
void display_transition(sfRenderWindow *window, class_t *class);
void move_parallax_class(class_t *class, sfRenderWindow *window);

#endif
