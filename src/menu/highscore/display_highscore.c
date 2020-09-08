/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** display_help.c
*/

#include "highscore.h"

static void display_highbutt(sfRenderWindow *window, butt_t *button)
{
    sfSprite_setTexture(button->sprite, button->texture, sfTrue);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfSprite_setPosition(button->sprite, button->vect);
    sfRenderWindow_drawSprite(window, button->sprite, NULL);
}

static void move_parallax_high(highscore_t *high)
{
    high->clock->time = sfClock_getElapsedTime(high->clock->clock);
    high->clock->seconds = sfTime_asMilliseconds(high->clock->time);
    if (high->pos1.x >= -1920)
        high->pos1.x -= 0.125 * high->clock->seconds;
    else
        high->pos1.x = 0;
    if (high->pos2.x >= -1920)
        high->pos2.x -= 0.184375 * high->clock->seconds;
    else
        high->pos2.x = 0;
    if (high->pos3.x >= -1920)
        high->pos3.x -= 0.140625 * high->clock->seconds;
    else
        high->pos3.x = 0;
    sfSprite_setPosition(high->parallax1->spr, high->pos1);
    sfSprite_setPosition(high->parallax2->spr, high->pos2);
    sfSprite_setPosition(high->parallax3->spr, high->pos3);
    sfClock_restart(high->clock->clock);
}

void display_highscore(sfRenderWindow *window, highscore_t *high)
{
    sfRenderWindow_clear(window, sfBlack);
    move_parallax_high(high);
    sfRenderWindow_drawSprite(window, high->parallax1->spr, NULL);
    sfRenderWindow_drawSprite(window, high->parallax3->spr, NULL);
    sfRenderWindow_drawSprite(window, high->parallax2->spr, NULL);
    sfRenderWindow_drawSprite(window, high->back_sprite, NULL);
    sfRenderWindow_drawText(window, high->text_highscore, NULL);
    sfRenderWindow_drawText(window, high->text_lastscore, NULL);
    display_highbutt(window, high->button);
    sfRenderWindow_display(window);
}
