/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hitbox.c
*/

#include "game.h"

void check_hitbox_mountains(player_t *player)
{
    if (player->pos.x >= 967 && player->pos.x <= 1500
    && player->pos.y <= 160) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.y <= 112 && player->pos.y >= 100) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= 417 && player->pos.y >= 640
    && player->pos.y <= 785) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 1600 && player->pos.x <= 1700
    && player->pos.y <= 220) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_tree(player_t *player)
{
    if (player->pos.x >= 400 && player->pos.x <= 772
    && player->pos.y <= 760 && player->pos.y >= 640) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= 772 && player->pos.x >= 767
    && player->pos.y <= 760 && player->pos.y >= 640) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= 1055 && player->pos.y >= 360
    && player->pos.x >= 450 && player->pos.y <= 365) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_graveyard(player_t *player)
{
    if (player->pos.x >= 192 && player->pos.y <= 400
    && player->pos.x <= 497 && player->pos.y >= 240) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= 192 && player->pos.y >= 240
    && player->pos.x <= 497 && player->pos.y <= 245) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    }
    if (player->pos.x <= 327 && player->pos.x >= 322
    && player->pos.y <= 245 && player->pos.y >= 0) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox(player_t *player)
{
    check_hitbox_harbor(player);
    check_hitbox_tavern(player);
    check_hitbox_mountains(player);
    check_hitbox_church(player);
    check_hitbox_tree(player);
    check_hitbox_shop(player);
    check_hitbox_graveyard(player);
    check_hitbox_houses(player);
    check_hitbox_tower_out(player);
}