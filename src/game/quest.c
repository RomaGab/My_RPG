/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** quest.c
*/

#include "game.h"

static void change_quest(game_t *game, player_t *player)
{
    for (npc_t *tmp = game->npc; tmp; tmp = tmp->next) {
        if (tmp->nb_npc == 1) {
            tmp->nb_quest += 1;
            player->xp += 40;
            player->gold += 10;
            tmp->state_quest = quest_never;
        }
    }
}

static void check_back_teleportation(game_t *game, player_t *player)
{
    item_t *item = player->inventory->item;

    for (int i = 0; i < 8; i++) {
        if (item[i].id == Gantlet && player->pos.y >= 845 &&
        player->pos.x <= -30 && player->pos.x >= -120 &&
        game->verif_back_tel == false) {
            sfSound_play(game->music->sound_teleportation);
            change_quest(game, player);
            player->pos_arrow = (sfVector2f){1200, 1084};
            player->pos = (sfVector2f) {1112, 920};
            game->verif_back_tel = true;
            break;
        }
    }
}

static void check_devil(game_t *game)
{
    for (npc_t *tmp = game->npc; tmp; tmp = tmp->next) {
        if (tmp->nb_npc == 1 && tmp->nb_quest == tmp->max_quest &&
        tmp->state_quest == quest_inprogress) {
            for (npc_t *tmp = game->npc; tmp; tmp = tmp->next)
                tmp->devil = false;
        }
    }
}

void quest(game_t *game, player_t *player)
{
    for (npc_t *tmp = game->npc; tmp; tmp = tmp->next) {
        if (player->inventory->item[0].id == 1 && tmp->nb_npc == 1 &&
        tmp->state_quest == quest_inprogress && tmp->nb_quest == 1) {
            tmp->state_quest = quest_never;
            player->xp += 20;
            tmp->nb_quest += 1;
        }
        if (tmp->state_quest == quest_inprogress && tmp->nb_npc == 1
        && tmp->nb_quest == 2 && game->verif_tel == false) {
            sfSound_play(game->music->sound_teleportation);
            game->verif_tel = true;
            player->xp += 20;
            player->pos_arrow = (sfVector2f){-310, 1020};
            player->pos = (sfVector2f){-40, 870};
        }
    }
    check_devil(game);
    check_back_teleportation(game, player);
}