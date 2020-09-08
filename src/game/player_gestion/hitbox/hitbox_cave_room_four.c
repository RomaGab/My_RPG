/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hitbox_cave_room_four.c
*/

#include "cave.h"

void check_hitbox_cave_first_room_four(player_t *player)
{
    if (player->pos.x >= -470 && player->pos.x <= -465
    && player->pos.y > 41 && player->pos.y <= 100) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    }
    if (player->pos.x >= -596 && player->pos.x <= -590
    && player->pos.y <= -2) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= -596 && player->pos.x < -372
    && player->pos.y <= 2 && player->pos.y >= -20) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= -470 && player->pos.x <= -467
    && player->pos.y <= 10 && player->pos.y >= -10) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    }
}