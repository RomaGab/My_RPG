/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_win.c
*/

#include "game.h"
#include "fight.h"

void display_win(fight_t *fight, sfInt64 time, sfRenderWindow *window)
{
    if (fight->hp_boss <= 0) {
        fight->win_pos.y -= 0.0003 * time;
        sfSprite_setPosition(fight->win->spr, fight->win_pos);
        sfRenderWindow_drawSprite(window, fight->win->spr, NULL);
    }
}