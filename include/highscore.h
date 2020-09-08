/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** highscore.h
*/

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*High Score*/

struct highscore_s
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
    sfFont *font;
    sfText *text_lastscore;
    sfText *text_highscore;
    butt_t *button;
};

/*---------------------------------------------------------------------------*/

highscore_t *create_highscore(void);

/*---------------------------------------------------------------------------*/

game_state_t analyse_eventhighscore(sfRenderWindow *window, sfEvent *event,
                                    highscore_t *high);

/*---------------------------------------------------------------------------*/

sprite_t *fill_sprite(char *str);

/*---------------------------------------------------------------------------*/

clocks_t *fill_time(void);

/*---------------------------------------------------------------------------*/

void free_highscore(highscore_t *high);
void display_highscore(sfRenderWindow *window, highscore_t *high);
void free_sprite(sprite_t *sprite);

#endif