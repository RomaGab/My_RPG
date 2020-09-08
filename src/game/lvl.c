/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** lvl.c
*/

#include "game.h"

void handle_lvl(player_t *player)
{
    int last_lvl = player->lvl;
    int diff = 0;

    player->lvl = player->xp / 25;
    player->lvl += 1;
    diff = player->lvl - last_lvl;
    if (diff != 0) {
        player->hp += 100 * diff;
        player->hp_max = player->hp;
        player->strength += 75 * diff;
    }
}