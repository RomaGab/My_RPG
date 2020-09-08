/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_cave.c
*/

#include "cave.h"
#include "game.h"

void display_cave(sfRenderWindow *window, game_t *game, player_t *player)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setView(window, game->view);
    sfSprite_setPosition(player->player_spr->spr, player->pos);
    sfSprite_setTextureRect(game->back_sprite, game->rect_back);
    sfRenderWindow_drawSprite(window, game->back_sprite, NULL);
    display_npc(window, game, player);
    sfSprite_setPosition(game->box->spr, game->pos_box);
    sfRenderWindow_drawSprite(window, game->box->spr, NULL);
    sfSprite_setTextureRect(player->player_spr->spr, player->rect);
    sfRenderWindow_drawSprite(window, player->player_spr->spr, NULL);
    display_text(window, game, player);
    display_logo(window, player, game);
    sfRenderWindow_display(window);
}