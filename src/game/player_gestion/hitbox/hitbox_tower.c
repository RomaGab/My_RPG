/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hitbox_tower.c
*/

#include "game.h"
#include "tower.h"

void check_hitbox_tower_walls(player_t *player)
{
    if (player->pos.y <= -500) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    } if (player->pos.y >= -368) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x >= -716) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= -958) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_tower_table(player_t *player)
{
    if (player->pos.x <= -910 && player->pos.x > -930
    && player->pos.y >= -436) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= -910 && player->pos.y >= -436
    && player->pos.y <= -418) {
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_tower_bed(player_t *player)
{
    if (player->pos.x <= -886 && player->pos.y <= -468) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
    } if (player->pos.x <= -886 && player->pos.x >= -970
    && player->pos.y <= -468) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_tower_chest(player_t *player)
{
    if (player->pos.y <= -444 && player->pos.x >= -950
    && player->pos.x < -895) {
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
    }
    if (player->pos.x >= -950 && player->pos.x <= -948
    && player->pos.y < -450) {
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    }
    if (player->pos.x <= -895 && player->pos.x >= -902
    && player->pos.y < -450) {
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
    }
}

void check_hitbox_tower(player_t *player)
{
    check_hitbox_tower_walls(player);
    check_hitbox_tower_table(player);
    check_hitbox_tower_bed(player);
    check_hitbox_tower_chest(player);
}