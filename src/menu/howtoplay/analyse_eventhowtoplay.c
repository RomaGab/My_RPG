/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** analyse_eventhighscore.c
*/

#include "howtoplay.h"

static game_state_t button_howtoplay(sfRenderWindow *window, howtoplay_t *help,
                            sfEvent *event)
{
    int m = 0;
    sfVector2f pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (event->type == sfEvtMouseButtonPressed)
        m = 1;
    pos = help->button->vect;
    if (mouse.x >= pos.x && mouse.x <= pos.x + 276
        && mouse.y >= pos.y && mouse.y <= pos.y + 170 && m == 1) {
        help->button->rect.top = 140;
        return (help->button->ret);
    } else if (mouse.x >= pos.x && mouse.x <= pos.x + 276
        && mouse.y >= pos.y && mouse.y <= pos.y + 70) {
        help->button->rect.top = 70;
    } else
        help->button->rect.top = 0;
    return (StateHowtoplay);
}

game_state_t analyse_eventhowtoplay(sfRenderWindow *window, sfEvent *event,
                                    howtoplay_t *help)
{
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape) {
        return StateOver;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == 1)
        sfSprite_setTextureRect(help->back_sprite,
        (sfIntRect){0, 0, 1046, 544});
    if (sfKeyboard_isKeyPressed(sfKeyRight) == 1)
        sfSprite_setTextureRect(help->back_sprite,
        (sfIntRect){1046, 0, 1046, 544});
    return (button_howtoplay(window, help, event));
}