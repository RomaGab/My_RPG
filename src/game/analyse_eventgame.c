/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** analyse_eventgame.c
*/

#include "game.h"

static game_state_t event_key(sfRenderWindow *window, game_t *game,
                                sfEvent *event, player_t *player)
{
    game_state_t scene = StateGame;

    if (event->key.code == sfKeyP)
        scene = gest_pause(window, game, event, player);
    if (event->key.code == sfKeyI)
        scene = gest_inventory(window, game, event, player);
    if (game->verif_e == false && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->verif_e = true;
        scene = interaction_npc(game, player, event, window);
    } else
        game->verif_e = false;
    return scene;
}

game_state_t analyse_eventgame(sfRenderWindow *window, game_t *game,
                                sfEvent *event, player_t *player)
{
    game_state_t scene = StateGame;

    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        return (StateOver);
    scene = event_key(window, game, event, player);
    if (player->pos.y <= 118)
        scene = gest_cave(window, game, event, player);
    if (player->pos.y <= 862 && player->pos.y >= 844 &&
    player->pos.x >= -122 && player->pos.x <= -100)
        scene = gest_tower(window, game, event, player);
    mini_map(game, window, player);
    return (scene);
}