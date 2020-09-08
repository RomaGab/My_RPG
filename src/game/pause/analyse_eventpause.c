/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** analyse_eventpause.c
*/

#include "pause.h"

static game_state_t button_pause(sfRenderWindow *window, pause_t *pause,
                            sfEvent *event)
{
    int i = 0;
    int m = 0;
    sfVector2f pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (event->type == sfEvtMouseButtonPressed)
        m = 1;
    for (i = 0; i <= 2; i += 1) {
        pos = pause->button[i].vect;
        if (mouse.x >= pos.x && mouse.x <= pos.x + 276
            && mouse.y >= pos.y && mouse.y <= pos.y + 70 && m == 1) {
            pause->button[i].rect.top = 140;
            return (pause->button[i].ret);
        } else if (mouse.x >= pos.x && mouse.x <= pos.x + 276
            && mouse.y >= pos.y && mouse.y <= pos.y + 70) {
            pause->button[i].rect.top = 70;
        } else
            pause->button[i].rect.top = 0;
    }
    return (StatePause);
}

game_state_t analyse_eventpause(sfRenderWindow *window, pause_t *pause,
                                sfEvent *event, player_t *player)
{
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape) {
        return (StateOver);
    }
    if (event->type == sfEvtMouseButtonPressed) {
        if ((event->mouseButton.x >= 70 && event->mouseButton.x <= 170) &&
        (event->mouseButton.y >= 20 && event->mouseButton.y <= 125))
            return (StateGame);
    }
    if (event->key.code == sfKeyR) {
        if (player->pos.y <= -365 && player->pos.x <= -710)
            return StateTower;
        else if (player->pos.y <= 99)
            return StateCave;
        else
            return StateGame;
    }
    return (button_pause(window, pause, event));
}