/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_transition.c
*/

#include "player.h"

void display_transition(sfRenderWindow *window, class_t *class)
{
    while (class->rect_transition.left != 9600) {
        class->clock->time = sfClock_getElapsedTime(class->clock->clock);
        class->clock->seconds = sfTime_asMilliseconds(class->clock->time);
        sfRenderWindow_clear(window, sfBlack);
        move_parallax_class(class, window);
        sfRenderWindow_drawSprite(window, class->back->spr, NULL);
        sfSprite_setTextureRect(class->transition->spr,
                                class->rect_transition);
        sfRenderWindow_drawSprite(window, class->transition->spr, NULL);
        sfRenderWindow_display(window);
        if (class->rect_transition.left != 9600 &&
        class->clock->seconds >= 50) {
            class->rect_transition.left += 1920;
            sfClock_restart(class->clock->clock);
        }
    }
}

game_state_t rm_draw_laser(sfRenderWindow *window, game_state_t scene,
                            skin_t *skin)
{
    sfRenderWindow_clear(window, sfBlack);
    move_parallax_skin(skin, window);
    sfRenderWindow_display(window);
    return scene;
}