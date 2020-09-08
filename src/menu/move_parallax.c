/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_parallax.c
*/

#include "player.h"

static void draw_parallax_class(class_t *class, sfRenderWindow *window)
{
    sfSprite_setPosition(class->parallax1->spr, class->pos1);
    sfSprite_setPosition(class->parallax2->spr, class->pos2);
    sfSprite_setPosition(class->parallax3->spr, class->pos3);
    sfRenderWindow_drawSprite(window, class->parallax1->spr, NULL);
    sfRenderWindow_drawSprite(window, class->parallax3->spr, NULL);
    sfRenderWindow_drawSprite(window, class->parallax2->spr, NULL);
    sfRenderWindow_drawSprite(window, class->back->spr, NULL);
}

void move_parallax_class(class_t *class, sfRenderWindow *window)
{
    class->clock_par->time = sfClock_getElapsedTime(class->clock_par->clock);
    class->clock_par->seconds = sfTime_asMilliseconds(class->clock_par->time);
    if (class->pos1.x >= -1920)
        class->pos1.x -= 0.125 * class->clock_par->seconds;
    else
        class->pos1.x = 0;
    if (class->pos2.x >= -1920)
        class->pos2.x -= 0.184375 * class->clock_par->seconds;
    else
        class->pos2.x = 0;
    if (class->pos3.x >= -1920)
        class->pos3.x -= 0.140625 * class->clock_par->seconds;
    else
        class->pos3.x = 0;
    sfClock_restart(class->clock_par->clock);
    draw_parallax_class(class, window);
}

static void draw_parallax_skin(skin_t *skin, sfRenderWindow *window)
{
    sfSprite_setPosition(skin->parallax1->spr, skin->pos1);
    sfSprite_setPosition(skin->parallax2->spr, skin->pos2);
    sfSprite_setPosition(skin->parallax3->spr, skin->pos3);
    sfRenderWindow_drawSprite(window, skin->parallax1->spr, NULL);
    sfRenderWindow_drawSprite(window, skin->parallax3->spr, NULL);
    sfRenderWindow_drawSprite(window, skin->parallax2->spr, NULL);
    sfRenderWindow_drawSprite(window, skin->back->spr, NULL);
}

void move_parallax_skin(skin_t *skin, sfRenderWindow *window)
{
    skin->clock_par->time = sfClock_getElapsedTime(skin->clock_par->clock);
    skin->clock_par->seconds = sfTime_asMilliseconds(skin->clock_par->time);
    if (skin->pos1.x >= -1920)
        skin->pos1.x -= 0.125 * skin->clock_par->seconds;
    else
        skin->pos1.x = 0;
    if (skin->pos2.x >= -1920)
        skin->pos2.x -= 0.184375 * skin->clock_par->seconds;
    else
        skin->pos2.x = 0;
    if (skin->pos3.x >= -1920)
        skin->pos3.x -= 0.140625 * skin->clock_par->seconds;
    else
        skin->pos3.x = 0;
    sfClock_restart(skin->clock_par->clock);
    draw_parallax_skin(skin, window);
}