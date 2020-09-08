/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** analyse_eventhighscore.c
*/

#include "highscore.h"

static game_state_t button_high(sfRenderWindow *window, highscore_t *high,
                            sfEvent *event)
{
    int m = 0;
    sfVector2f pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (event->type == sfEvtMouseButtonPressed)
        m = 1;
    pos = high->button->vect;
    if (mouse.x >= pos.x && mouse.x <= pos.x + 276
        && mouse.y >= pos.y && mouse.y <= pos.y + 170 && m == 1) {
        high->button->rect.top = 140;
        return (high->button->ret);
    } else if (mouse.x >= pos.x && mouse.x <= pos.x + 276
        && mouse.y >= pos.y && mouse.y <= pos.y + 70) {
        high->button->rect.top = 70;
    } else
        high->button->rect.top = 0;
    return (StateHighscore);
}

game_state_t analyse_eventhighscore(sfRenderWindow *window, sfEvent *event,
                                    highscore_t *high)
{
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape) {
        return StateOver;
    }
    return (button_high(window, high, event));
}