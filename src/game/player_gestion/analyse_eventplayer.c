/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_eventplayer.c
*/

#include "player.h"

game_state_t analyse_eventplayer(sfRenderWindow *window, sfEvent *event,
                                    player_t *player, skin_t *skin)
{
    game_state_t scene = StatePlayer;

    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape) {
        player->over = true;
        return StateOver;
    }
    if (event->type == sfEvtMouseButtonPressed) {
        player->character = NO_PLAYER;
        scene = chose_skin(event->mouseButton.x, event->mouseButton.y,
                            player, skin);
        if (scene == StateError)
            return StateError;
        if (player->character != NO_PLAYER)
            scene = StateGame;
    }
    return scene;
}