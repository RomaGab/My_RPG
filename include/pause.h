/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pause.h
*/

#ifndef PAUSE_H
#define PAUSE_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Pause*/

struct pause_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sprite_t *back_sprite;
    butt_t *button;
};

/*---------------------------------------------------------------------------*/

pause_t *create_pause(player_t *player);

/*---------------------------------------------------------------------------*/

game_state_t analyse_eventpause(sfRenderWindow *window, pause_t *pause,
                                sfEvent *event, player_t *player);

/*---------------------------------------------------------------------------*/

sprite_t *fill_sprite(char *str);

/*---------------------------------------------------------------------------*/

void free_sprite(sprite_t *sprite);

/*---------------------------------------------------------------------------*/

void free_pause(pause_t *pause);
void display_pause(sfRenderWindow *window, game_t *game, pause_t *pause,
                    player_t *player);
void display_logo(sfRenderWindow *window, player_t *player, game_t *game);

#endif