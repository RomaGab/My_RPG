/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** launch.h
*/

#ifndef LAUNCH_H
#define LAUNCH_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Launcher*/

struct launch_s
{
    sprite_t *spr;
    sfVector2f vect_spr;
    sprite_t *logo;
    sprite_t *title;
    sfColor color_logo;
    clocks_t *clock;
    sfMusic *music;
};

/*---------------------------------------------------------------------------*/

game_state_t analyse_eventlaunch(sfEvent *event);

/*---------------------------------------------------------------------------*/

sprite_t *fill_sprite(char *str);

/*---------------------------------------------------------------------------*/

clocks_t *fill_time(void);

/*---------------------------------------------------------------------------*/

void free_launch(launch_t *launch);
void free_sprite(sprite_t *sprite);
void display_launch(sfRenderWindow *window, launch_t *launch);

#endif