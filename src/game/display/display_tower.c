/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_tower.c
*/

#include "tower.h"
#include "game.h"

void display_tower(sfRenderWindow *window, game_t *game,
                            player_t *player)
{
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setView(window, game->view);
    sfRenderWindow_drawSprite(window, game->back_sprite, NULL);
    sfSprite_setPosition(player->player_spr->spr, player->pos);
    sfSprite_setTextureRect(player->player_spr->spr, player->rect);
    display_logo(window, player, game);
    sfRenderWindow_drawSprite(window, player->player_spr->spr, NULL);
    sfRenderWindow_display(window);
}