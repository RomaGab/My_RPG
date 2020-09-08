/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** text.c
*/

#include "game.h"

static void set_text(player_t *player, game_t *game)
{
    sfText_setFont(player->text_gold, game->font);
    sfText_setCharacterSize(player->text_gold, 30);
    sfText_setFillColor(player->text_gold, sfWhite);
    sfText_setFont(player->text_hp, game->font);
    sfText_setCharacterSize(player->text_hp, 30);
    sfText_setFillColor(player->text_hp, sfWhite);
    sfText_setFont(player->text_strength, game->font);
    sfText_setCharacterSize(player->text_strength, 30);
    sfText_setFillColor(player->text_strength, sfWhite);
    sfText_setFont(player->text_lvl, game->font);
    sfText_setCharacterSize(player->text_lvl, 30);
    sfText_setFillColor(player->text_lvl, sfWhite);
    sfText_setPosition(player->text_gold, (sfVector2f){1364, 327});
    sfText_setPosition(player->text_hp, (sfVector2f){520, 285});
    sfText_setPosition(player->text_strength, (sfVector2f){600, 285});
    sfText_setPosition(player->text_lvl, (sfVector2f){690, 285});
}

int init_text_player(player_t *player, game_t *game)
{
    player->text_gold = sfText_create();
    player->text_hp = sfText_create();
    player->text_strength = sfText_create();
    player->text_lvl = sfText_create();
    if (!player->text_gold || !player->text_hp || !player->text_strength ||
    !player->text_lvl)
        return 84;
    set_text(player, game);
    return 0;
}