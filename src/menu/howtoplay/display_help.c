/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** display_help.c
*/

#include "howtoplay.h"

static void display_helpbutt(sfRenderWindow *window, butt_t *button)
{
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setPosition(button->sprite, button->vect);
    sfRenderWindow_drawSprite(window, button->sprite, NULL);
}

static void move_parallax_h2p(howtoplay_t *help)
{
    help->clock->time = sfClock_getElapsedTime(help->clock->clock);
    help->clock->seconds = sfTime_asMilliseconds(help->clock->time);
    if (help->pos1.x >= -1920)
        help->pos1.x -= 0.125 * help->clock->seconds;
    else
        help->pos1.x = 0;
    if (help->pos2.x >= -1920)
        help->pos2.x -= 0.184375 * help->clock->seconds;
    else
        help->pos2.x = 0;
    if (help->pos3.x >= -1920)
        help->pos3.x -= 0.140625 * help->clock->seconds;
    else
        help->pos3.x = 0;
    sfSprite_setPosition(help->parallax1->spr, help->pos1);
    sfSprite_setPosition(help->parallax2->spr, help->pos2);
    sfSprite_setPosition(help->parallax3->spr, help->pos3);
    sfClock_restart(help->clock->clock);
}

void display_help(sfRenderWindow *window, howtoplay_t *help)
{
    sfRenderWindow_clear(window, sfBlack);
    move_parallax_h2p(help);
    sfRenderWindow_drawSprite(window, help->parallax1->spr, NULL);
    sfRenderWindow_drawSprite(window, help->parallax3->spr, NULL);
    sfRenderWindow_drawSprite(window, help->parallax2->spr, NULL);
    sfRenderWindow_drawSprite(window, help->back_sprite, NULL);
    display_helpbutt(window, help->button);
    sfRenderWindow_display(window);
}
