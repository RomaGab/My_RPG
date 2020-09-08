/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_eventcave.c
*/

#include "cave.h"
#include "game.h"

static game_state_t back_to_game(player_t *player, game_t *game,
                                sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlack);
    sfTexture_destroy(game->back_text);
    game->back_text = sfTexture_createFromFile("res/back/map.png", NULL);
    if (!game->back_text)
        return StateError;
    sfSprite_setTexture(game->back_sprite, game->back_text, sfTrue);
    game->rect_back = (sfIntRect){7680, 0, 3840, 2160};
    sfSprite_setTextureRect(game->back_sprite, game->rect_back);
    sfRenderWindow_drawSprite(window, game->back_sprite, NULL);
    player->pos = (sfVector2f){345, 122};
    player->pos_arrow = (sfVector2f){200, 44};
    sfSprite_setRotation(game->arrow->spr, (float)180);
    return StateGame;
}

static game_state_t verif_fight(sfRenderWindow *window, sfEvent *event,
                                game_t *game, player_t *player)
{
    game_state_t scene = StateCave;

    for (npc_t *tmp = game->npc; tmp; tmp = tmp->next) {
        if (tmp->nb_npc == 3 && tmp->state_quest == quest_inprogress &&
        tmp->devil == false)
            scene = gest_fight(window, event, game, player);
    }
    return scene;
}

game_state_t analyse_eventcave(sfRenderWindow *window, game_t *game,
                                sfEvent *event, player_t *player)
{
    game_state_t scene = StateCave;

    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        return StateOver;
    if (event->key.code == sfKeyP)
        scene = gest_pause(window, game, event, player);
    if (event->key.code == sfKeyI) {
        scene = gest_inventory(window, game, event, player);
    } if (game->verif_int == false && sfKeyboard_isKeyPressed(sfKeyE)) {
        game->verif_int = true;
        scene = interaction_npc(game, player, event, window);
        scene = (scene == StateGame) ? StateCave : StateError;
    } else
        game->verif_int = false;
    if (player->pos.y >= 100)
        return back_to_game(player, game, window);
    if (scene == StateCave)
        scene = verif_fight(window, event, game, player);
    return scene;
}