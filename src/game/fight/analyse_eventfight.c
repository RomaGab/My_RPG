/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_eventfight.c
*/

#include "fight.h"

game_state_t analyse_eventfight(sfRenderWindow *window, game_t *game,
                                sfEvent *event, player_t *player)
{
    game_state_t scene = StateFight;

    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        return StateOver;
    if (event->key.code == sfKeyP) {
        scene = gest_pause(window, game, event, player);
        scene = (scene == StateCave) ? StateFight : scene;
    }
    return scene;
}