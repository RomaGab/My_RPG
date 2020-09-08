/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** analyse_eventtower.c
*/

#include "tower.h"
#include "game.h"

game_state_t back_to_tower(sfRenderWindow *window, game_t *game,
                    sfEvent *event, player_t *player)
{
    sfRenderWindow_clear(window, sfBlack);
    sfTexture_destroy(game->back_text);
    game->back_text = sfTexture_createFromFile("res/back/map.png", NULL);
    if (!game->back_text)
        return StateError;
    sfSprite_setTexture(game->back_sprite, game->back_text, sfTrue);
    game->rect_back = (sfIntRect){7680, 0, 3840, 2160};
    sfSprite_setTextureRect(game->back_sprite, game->rect_back);
    player->pos = (sfVector2f){-112, 866};
    sfSprite_setPosition(player->player_spr->spr, player->pos);
    return StateGame;
}

game_state_t analyse_eventtower(sfRenderWindow *window, game_t *game,
                        sfEvent *event, player_t *player)
{
    game_state_t scene = StateTower;

    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
        return StateOver;
    if (event->key.code == sfKeyP)
        scene = gest_pause(window, game, event, player);
    if (event->key.code == sfKeyI) {
        scene = gest_inventory(window, game, event, player);
        if (scene == StateTower) {
            game->rect_back = (sfIntRect){0, 0, 304, 237};
            sfSprite_setTextureRect(game->back_sprite, game->rect_back);
        }
    }
    if (player->pos.y >= -400 && player->pos.x >= -742
    && player->pos.x <= -698)
        scene = back_to_tower(window, game, event, player);
    return scene;
}