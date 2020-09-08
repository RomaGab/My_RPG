/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_game.c
*/

#include "game.h"

void free_npc(npc_t *npc)
{
    npc_t *tmp = npc;

    for (; npc; npc = tmp) {
        free_sprite(npc->sprite);
        free_sprite(npc->sprite_chat);
        sfClock_destroy(npc->clock_npc->clock);
        sfClock_destroy(npc->move->clock);
        free(npc->clock_npc);
        free(npc->move);
        for (int i = 0; npc->nb_npc != 2 && npc->dialogue[i]; i++)
            free(npc->dialogue[i]);
        free(npc->dialogue);
        tmp = tmp->next;
        free(npc);
    }
}

void free_fireplace(fireplace_t *fireplace)
{
    fireplace_t *tmp = fireplace;

    for (; fireplace; fireplace = tmp) {
        free_sprite(fireplace->smoke);
        free_sprite(fireplace->red_particule);
        free_sprite(fireplace->blue_particule);
        sfClock_destroy(fireplace->clock->clock);
        free(fireplace->clock);
        tmp = tmp->next;
        free(fireplace);
    }
}

static void free_game_two(game_t *game)
{
    free_music(game->music);
    sfFont_destroy(game->font);
    sfText_destroy(game->text);
    free_sprite(game->mini_map);
    free_sprite(game->xp_cadre);
    free_sprite(game->xp);
    free(game->str);
    free_sprite(game->box);
}

void free_game(game_t *game, player_t *player, sfRenderWindow *window)
{
    free_sprite(game->transition);
    free_sprite(game->bubble);
    free_sprite(game->arrow);
    sfClock_destroy(game->back->clock);
    free(game->back);
    sfClock_destroy(game->time->clock);
    free(game->time);
    sfClock_destroy(game->zoom->clock);
    free(game->zoom);
    sfTexture_destroy(game->back_text);
    sfSprite_destroy(game->back_sprite);
    free_npc(game->npc);
    sfView_setSize(game->view, (sfVector2f){1920, 1080});
    sfView_setCenter(game->view, (sfVector2f){960, 540});
    sfRenderWindow_setView(window, game->view);
    sfView_destroy(game->view);
    free_player(player);
    free_fireplace(game->fire_place);
    free_game_two(game);
    free(game);
}