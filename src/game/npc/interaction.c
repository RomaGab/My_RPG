/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** interaction.c
*/

#include "game.h"
#include "util.h"

int chose_nb(npc_t *tmp)
{
    int nb = 0;

    if (tmp->state_quest != no_quest) {
        if (tmp->nb_quest == 1)
            nb = tmp->state_quest - 1;
        if (tmp->nb_quest == 2 && tmp->nb_npc == 1 &&
        tmp->state_quest == quest_never)
            nb = 2;
        if (tmp->nb_quest == tmp->max_quest && tmp->nb_npc == 1 &&
        tmp->state_quest == quest_never)
            nb = 3;
        if (tmp->nb_quest == tmp->max_quest && tmp->nb_npc == 1 &&
        tmp->state_quest == quest_inprogress)
            nb = 4;
    } else
        nb = rand() % 4;
    return nb;
}

static game_state_t chose_interaction(game_t *game, player_t *player,
                                sfEvent *event, sfRenderWindow *window)
{
    if (game->npc->conversation == false && player->pos.x >
    game->npc->pos.x - 60 && player->pos.x < game->npc->pos.x + 60 &&
    player->pos.y > game->npc->pos.y - 60 && player->pos.y <
    game->npc->pos.y + 60 && game->npc->nb_npc != 2 && game->npc->devil
    == false) {
        if (find_dialogue(game->npc, game, player) == 84)
            return StateError;
        game->npc->conversation = true;
    } else if (game->npc->conversation == true && game->npc->dialogue != 0
    && game->npc->nb_npc != 2) {
        if (find_dialogue(game->npc, game, player) == 84)
            return StateError;
        if (game->npc->nb_npc == 0)
            return gest_shop(window, game, event, player);
    }
    if (game->npc->conversation == true && !game->str)
        return StateError;
    return StateGame;
}

game_state_t interaction_npc(game_t *game, player_t *player, sfEvent *event,
                            sfRenderWindow *window)
{
    npc_t *tmp = game->npc;

    for (; game->npc; game->npc = game->npc->next) {
        if (chose_interaction(game, player, event, window) == StateError)
            return StateError;
        if (game->npc->nb_npc == 1)
            game->quest_id = game->npc->nb_quest;
    }
    game->npc = tmp;
    return StateGame;
}