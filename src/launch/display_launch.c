/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** intro_first.c
*/

#include "launch.h"

static void change_intro_logo(sfRenderWindow *window, launch_t *launch,
                                int flg)
{
    if (flg == 0) {
        if (launch->color_logo.a <= 240)
            launch->color_logo.a += 0.016 * launch->clock->seconds;
        else
            launch->color_logo.a = 250;
    } else {
        if (launch->color_logo.a >= 20)
            launch->color_logo.a -= 0.2 * launch->clock->seconds;
        else
            launch->color_logo.a = 0;
    }
    sfSprite_setColor(launch->logo->spr, launch->color_logo);
    sfSprite_setColor(launch->title->spr, launch->color_logo);
    sfSprite_setPosition(launch->logo->spr, (sfVector2f){300, 220});
    sfRenderWindow_drawSprite(window, launch->logo->spr, NULL);
    sfRenderWindow_drawSprite(window, launch->title->spr, NULL);
}

static void intro_move(sfRenderWindow *window, launch_t *launch,
                                int flg)
{
    if (flg == 0) {
        launch->vect_spr.x -= 0.15 * launch->clock->seconds;
        if (launch->vect_spr.x <= -1920)
            launch->vect_spr.x += 1920;
    } else {
        launch->vect_spr.x -= 0.15 * launch->clock->seconds;
        if (launch->vect_spr.x <= -5761)
            launch->vect_spr.x += 1920;
    }
    sfSprite_setPosition(launch->spr->spr, launch->vect_spr);
    sfRenderWindow_drawSprite(window, launch->spr->spr, NULL);
}

void display_launch(sfRenderWindow *window, launch_t *launch)
{
    sfInt64 time = sfMusic_getPlayingOffset(launch->music).microseconds;
    launch->clock->time = sfClock_getElapsedTime(launch->clock->clock);
    launch->clock->seconds = sfTime_asMicroseconds(launch->clock->time);

    sfRenderWindow_clear(window, sfBlack);
    if (time < 8000000) {
        intro_move(window, launch, 0);
        change_intro_logo(window, launch, 0);
    } else {
        intro_move(window, launch, 1);
        change_intro_logo(window, launch, 1);
    }
    sfRenderWindow_display(window);
    sfClock_restart(launch->clock->clock);
    if (time > 13000000)
        sfMusic_stop(launch->music);
}