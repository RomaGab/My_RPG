/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hitbox_harbor.c
*/

#include "game.h"

void check_hitbox_harbor_left(player_t *player)
{
    if (player->pos.x <= 675 && player->pos.y >= 890) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= 1086 && player->pos.x >= 675
    && player->pos.y <= 905 && player->pos.y >= 880) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= 1086 && player->pos.y <= 905
    && player->pos.y > 785 && player->pos.x >= 1079) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 390 && player->pos.x <= 1080
    && player->pos.y > 785 && player->pos.y < 800) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_harbor_right(player_t *player)
{
    if (player->pos.x >= 1640 && player->pos.y >= 870) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1140 && player->pos.x <= 1660
    && player->pos.y <= 885 && player->pos.y >= 880) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1140 && player->pos.y <= 885
    && player->pos.y > 785 && player->pos.x <= 1145) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1140 && player->pos.x <= 2000
    && player->pos.y > 785 && player->pos.y < 800) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_harbor(player_t *player)
{
    check_hitbox_harbor_right(player);
    check_hitbox_harbor_left(player);
    if (player->pos.y >= 970) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    }
}