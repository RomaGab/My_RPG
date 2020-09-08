/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hitbox_builds.c
*/

#include "game.h"

void check_hitbox_tavern(player_t *player)
{
    if (player->pos.x >= 1120 && player->pos.x <= 1635
    && player->pos.y <= 750 && player->pos.y >= 745) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1120 && player->pos.y <= 750
    && player->pos.y >= 140 && player->pos.x <= 1222) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1500 && player->pos.y <= 750
    && player->pos.y >= 140 && player->pos.x <= 1635) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 347 && player->pos.y <= 205
    && player->pos.x <= 352 && player->pos.y >= 0) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_church(player_t *player)
{
    if (player->pos.x <= 1032 && player->pos.x >= 517
    && player->pos.y <= 320 && player->pos.y >= 315) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 517 && player->pos.x <= 522
    && player->pos.y <= 320 && player->pos.y >= 115) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1027 && player->pos.x <= 1032
    && player->pos.y <= 320 && player->pos.y >= 115) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 347 && player->pos.y <= 205
    && player->pos.x <= 540 && player->pos.y >= 200) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_shop_two(player_t *player)
{
    if (player->pos.x >= 1102 && player->pos.y <= 745
    && player->pos.x <= 1107 && player->pos.y >= 200) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= 1107 && player->pos.x >= 1052
    && player->pos.y <= 745 && player->pos.y >= 195) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1052 && player->pos.y <= 700
    && player->pos.x <= 1057 && player->pos.y >= 195) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_shop(player_t *player)
{
    if (player->pos.x >= 750 && player->pos.x <= 1030 && player->pos.y >= 655
    && player->pos.y <= 730) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1027 && player->pos.y <= 745
    && player->pos.x <= 1032 && player->pos.y >= 585) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1027 && player->pos.y <= 745
    && player->pos.x <= 1107 && player->pos.y >= 740) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    }
    check_hitbox_shop_two(player);
}

void check_hitbox_houses(player_t *player)
{
    if (player->pos.x >= 1648 && player->pos.x <= 2000
    && player->pos.y <= 755 && player->pos.y >= 750) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1927) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1648 && player->pos.x <= 1657
    && player->pos.y <= 755 && player->pos.y >= 120) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    }
}