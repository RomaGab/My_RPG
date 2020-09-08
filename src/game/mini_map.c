/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** mini_map.c
*/

#include "typedef.h"
#include "game.h"

static void move_mini_map(player_t *player, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == 1) {
        sfSprite_setRotation(game->arrow->spr, (float)0);
    } if (sfKeyboard_isKeyPressed(sfKeyDown) == 1) {
        sfSprite_setRotation(game->arrow->spr, (float)180);
    } if (sfKeyboard_isKeyPressed(sfKeyRight) == 1) {
        sfSprite_setRotation(game->arrow->spr, (float)90);
    } if (sfKeyboard_isKeyPressed(sfKeyLeft) == 1) {
        sfSprite_setRotation(game->arrow->spr, (float)270);
    }
    sfSprite_setPosition(game->mini_map->spr, player->pos);
    sfSprite_setPosition(game->arrow->spr, player->pos_arrow);
}

void mini_map(game_t *game, sfRenderWindow *window, player_t *player)
{
    sfSprite_setOrigin(game->mini_map->spr, (sfVector2f){401, 178});
    sfSprite_setOrigin(game->arrow->spr, (sfVector2f){10, 11});
    move_mini_map(player, game);
}