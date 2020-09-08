/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hitbox_tower_out.c
*/

#include "game.h"

void check_hitbox_tower_out_two(player_t *player)
{
    if (player->pos.x >= -240 && player->pos.x <= 4
    && player->pos.y <= 850 && player->pos.y >= 828) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= -200 && player->pos.x <= -198
    && player->pos.y >= 850 && player->pos.y <= 860) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= -30 && player->pos.x >= -32
    && player->pos.y >= 850 && player->pos.y <= 860) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_tower_out(player_t *player)
{
    if (player->pos.x <= 32 && player->pos.x >= -264
    && player->pos.y >= 868) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.y <= 860 && player->pos.x > -200
    && player->pos.x < -30) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 4 && player->pos.x <= 8
    && player->pos.y <= 900 && player->pos.y >= 826) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= -232 && player->pos.y <= 900
    && player->pos.y >= 826) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    }
    check_hitbox_tower_out_two(player);
}