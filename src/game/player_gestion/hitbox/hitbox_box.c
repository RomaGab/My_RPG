/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hitbox_box.c
*/

#include "cave.h"

void check_hitbox_box(player_t *player, game_t *game)
{
    if (game->pos_box.y >= -338 && game->pos_box.y <= -329) {
        game->pos_box.y -= 0.1333 * player->clock_move->seconds;
        player->pos.y -= 0.1333 * player->clock_move->seconds;
    }
    if (game->pos_box.x <= -422 && game->pos_box.y <= -329
    && game->pos_box.y >= -500) {
        game->pos_box.x += 0.1333 * player->clock_move->seconds;
        player->pos.x += 0.1333 * player->clock_move->seconds;
    }
    if (game->pos_box.x >= 8) {
        game->pos_box.x -= 0.1333 * player->clock_move->seconds;
        player->pos.x -= 0.1333 * player->clock_move->seconds;
    }
    if (game->pos_box.y <= -444) {
        game->pos_box.y += 0.1333 * player->clock_move->seconds;
        player->pos.y += 0.1333 * player->clock_move->seconds;
    }
}