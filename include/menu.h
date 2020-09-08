/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** menu.h
*/

#ifndef MENU_H
#define MENU_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Menu*/

struct menu_s
{
    sprite_t *parallax1;
    sprite_t *parallax2;
    sprite_t *parallax3;
    sprite_t *fps_button;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;
    sfTexture *back_text;
    sfSprite *back_sprite;
    sfMusic *music;
    clocks_t *clock;
    butt_t *button;
    int fps;
};

/*---------------------------------------------------------------------------*/

game_state_t gest_highscore(sfRenderWindow *window, sfEvent *event);
game_state_t gest_howtoplay(sfRenderWindow *window, sfEvent *event);
game_state_t analyse_eventmenu(sfRenderWindow *window, menu_t *menu,
                                sfEvent *event);

/*---------------------------------------------------------------------------*/

menu_t *create_menu(void);

/*---------------------------------------------------------------------------*/

sprite_t *fill_sprite(char *str);

/*---------------------------------------------------------------------------*/

clocks_t *fill_time(void);

/*---------------------------------------------------------------------------*/

void free_menu(menu_t *menu);
void display_menu(sfRenderWindow *window, menu_t *menu);
void free_sprite(sprite_t *sprite);

#endif