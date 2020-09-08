/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** use_item.c
*/

#include "fight.h"

const item_usage_t fptr[] = {
    &use_potion,
    &use_poison,
    &use_shroom,
    &use_doume
};

static void use_potion(fight_t *fight, player_t *player)
{
    int idx = fight->item_index;

    player->hp += 200;
    if (player->hp >= player->hp_max)
        player->hp = player->hp_max;
    player->inventory->item[idx] = remove_item(player->inventory->item[idx]);
}

static void use_poison(fight_t *fight, player_t *player)
{
    int idx = fight->item_index;

    fight->poison_sword = true;
    player->inventory->item[idx] = remove_item(player->inventory->item[idx]);
}

static void use_shroom(fight_t *fight, player_t *player)
{
    int idx = fight->item_index;

    fight->poison_player = true;
    player->inventory->item[idx] = remove_item(player->inventory->item[idx]);
}

static void use_doume(fight_t *fight, player_t *player)
{
    int idx = fight->item_index;

    fight->boost = 2;
    player->inventory->item[idx] = remove_item(player->inventory->item[idx]);
}

void redirect_item(fight_t *fight, player_t *player)
{
    int id = player->inventory->item[fight->item_index].id;

    if (id > 0 && id < 5)
        fptr[id - 1](fight, player);
}