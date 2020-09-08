/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hitbox_cave_second_room.c
*/

#include "cave.h"

void check_hitbox_cave_second_room_one(player_t *player)
{
    if (player->pos.x <= -366 && player->pos.x >= -369 && player->pos.y <= 78
    && player->pos.y >= 41) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= -364 && player->pos.y >= 72) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= -32 && player->pos.y <= 74
    && player->pos.y >= -180) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= -188 && player->pos.x <= -20 && player->pos.y <= -62
    && player->pos.y >= -66) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= -371 && player->pos.x <= -368 && player->pos.y <= 16
    && player->pos.y >= -168) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_cave_second_room_two(player_t *player)
{
    if (player->pos.x < -206 && player->pos.y <= -62 && player->pos.y >= -66
    && player->pos.x >= -368) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x < -206 && player->pos.x >= -214
    && player->pos.y >= -338 && player->pos.y <= -66) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= -188 && player->pos.x <= -180
    && player->pos.y >= -338 && player->pos.y <= -66) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    }
}