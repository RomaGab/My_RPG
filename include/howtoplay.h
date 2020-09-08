/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** howtoplay.h
*/

#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*How to play*/

struct howtoplay_s
{
    sprite_t *parallax1;
    sprite_t *parallax2;
    sprite_t *parallax3;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;
    sfTexture *back_text;
    sfSprite *back_sprite;
    clocks_t *clock;
    butt_t *button;
};

/*---------------------------------------------------------------------------*/

howtoplay_t *create_help(void);

/*---------------------------------------------------------------------------*/

game_state_t analyse_eventhowtoplay(sfRenderWindow *window, sfEvent *event,
                                    howtoplay_t *help);

/*---------------------------------------------------------------------------*/

sprite_t *fill_sprite(char *str);

/*---------------------------------------------------------------------------*/

clocks_t *fill_time(void);

/*---------------------------------------------------------------------------*/

void free_help(howtoplay_t *help);
void display_help(sfRenderWindow *window, howtoplay_t *help);
void free_sprite(sprite_t *sprite);

#endif