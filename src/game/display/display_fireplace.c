/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_fireplace.c
*/

#include "game.h"

static void draw_fireplace(fireplace_t *tmp)
{
    tmp->clock->time = sfClock_getElapsedTime(tmp->clock->clock);
    tmp->clock->seconds = sfTime_asMilliseconds(tmp->clock->time);
    if (tmp->clock->seconds >= 200 && tmp->rect_smoke.left != 0
    && tmp->verif == true) {
        tmp->rect_smoke.left -= 60;
        tmp->rect_red.left = rand() % 5 * 60;
        tmp->rect_blue.left = rand() % 5 * 60;
        sfClock_restart(tmp->clock->clock);
    } if (tmp->verif == true && tmp->rect_smoke.left == 0)
        tmp->verif = false;
    else if (tmp->rect_smoke.left != 300 && tmp->clock->seconds >= 200
    && tmp->verif == false) {
        tmp->rect_smoke.left += 60;
        tmp->rect_red.left = rand() % 5 * 60;
        tmp->rect_blue.left = rand() % 5 * 60;
        sfClock_restart(tmp->clock->clock);
    } if (tmp->rect_smoke.left == 300 && tmp->verif == false)
        tmp->verif = true;
}

void display_fireplace(game_t *game, sfRenderWindow *window)
{
    for (fireplace_t *tmp = game->fire_place; tmp; tmp = tmp->next) {
        sfSprite_setTextureRect(tmp->smoke->spr, tmp->rect_smoke);
        sfSprite_setTextureRect(tmp->red_particule->spr, tmp->rect_red);
        sfSprite_setTextureRect(tmp->blue_particule->spr, tmp->rect_blue);
        draw_fireplace(tmp);
        sfRenderWindow_drawSprite(window, tmp->smoke->spr, NULL);
        sfRenderWindow_drawSprite(window, tmp->red_particule->spr, NULL);
        sfRenderWindow_drawSprite(window, tmp->blue_particule->spr, NULL);
    }
}