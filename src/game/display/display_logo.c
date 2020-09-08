/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_logo.c
*/

#include "game.h"

void display_chat_logo(sfRenderWindow *window, npc_t *tmp, player_t *player)
{
    if (player->pos.x > tmp->pos.x - 60 && player->pos.x < tmp->pos.x + 60
    && player->pos.y > tmp->pos.y - 60 && player->pos.y < tmp->pos.y + 60
    && tmp->nb_npc != 2)
        sfRenderWindow_drawSprite(window, tmp->sprite_chat->spr, NULL);
}

void display_logo(sfRenderWindow *window, player_t *player, game_t *game)
{
    if (game->zoom_x == 1920) {
        sfSprite_setPosition(player->char_logo->spr, (sfVector2f){50, 50});
        sfSprite_setPosition(player->class_logo->spr, (sfVector2f){41, 100});
    } else if (game->zoom_x == 1200) {
        sfSprite_setPosition(player->char_logo->spr, (sfVector2f)
        {player->pos.x - 530, player->pos.y - 285});
        sfSprite_setPosition(player->class_logo->spr, (sfVector2f)
        {player->pos.x - 536, player->pos.y - 238});
    } else
        return;
    sfSprite_setTextureRect(player->char_logo->spr, player->rect_char);
    sfRenderWindow_drawSprite(window, player->char_logo->spr, NULL);
    sfSprite_setTextureRect(player->class_logo->spr, player->rect_class);
    sfRenderWindow_drawSprite(window, player->class_logo->spr, NULL);
}