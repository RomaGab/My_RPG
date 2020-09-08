/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hitbox_cave.c
*/

#include "cave.h"

static void check_hitbox_cave_first_room_three(player_t *player)
{
    if (player->pos.x >= -528 && player->pos.y <= 100
    && player->pos.y >= 78) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x > -530 && player->pos.x <= -454
    && player->pos.y >= 78) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    }
    check_hitbox_cave_first_room_four(player);
}

static void check_hitbox_cave_first_room_two(player_t *player)
{
    if (player->pos.x <= -596 && player->pos.y <= -64) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= -560 && player->pos.y >= 78
    && player->pos.y <= 100) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x > -470 && player->pos.x < -370
    && player->pos.y >= 41) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= -470 && player->pos.x <= -370
    && player->pos.y <= 14 && player->pos.y >= 11) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    }
    check_hitbox_cave_first_room_three(player);
}

static void check_hitbox_cave_first_room_one(player_t *player)
{
    if (player->pos.x <= -560 && player->pos.y >= 78) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= -906 && player->pos.y <= 2) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= -906 && player->pos.y >= -146
    && player->pos.y <= 2) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    }
}

static void check_hitbox_cave_third_room(player_t *player)
{
    if (player->pos.x >= -188 && player->pos.x <= 40
    && player->pos.y >= -338 && player->pos.y <= -329) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x < -206 && player->pos.x >= -460
    && player->pos.y >= -338 && player->pos.y <= -329) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= -432 && player->pos.y <= -329
    && player->pos.y >= -500) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_cave(player_t *player, game_t *game)
{
    if (player->pos.x <= -934) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 38) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.y <= -474) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    }
    check_hitbox_cave_first_room_one(player);
    check_hitbox_cave_first_room_two(player);
    check_hitbox_cave_second_room_one(player);
    check_hitbox_cave_second_room_two(player);
    check_hitbox_cave_third_room(player);
    check_hitbox_box(player, game);
}