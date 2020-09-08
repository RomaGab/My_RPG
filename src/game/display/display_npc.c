/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_npc.c
*/

#include "game.h"

void move_npc2(npc_t *tmp)
{
    if (tmp->pos.y < 330 && tmp->pos.x < 1040 && tmp->pos.x > 1000) {
        tmp->pos.y += 0.09 * tmp->move->seconds;
        tmp->rect.top = 0;
        return;
    }
    if (tmp->pos.x > 780 && tmp->pos.y > 330 && tmp->pos.y < 350) {
        tmp->pos.x -= 0.09 * tmp->move->seconds;
        tmp->rect.top = 64;
        return;
    }
    if (tmp->pos.y > 320) {
        tmp->pos.y -= 0.09 * tmp->move->seconds;
        tmp->rect.top = 192;
        return;
    }
}

void move_npc(npc_t *tmp)
{
    if (tmp->pos.x > 1115) {
        tmp->pos.x -= 0.09 * tmp->move->seconds;
        tmp->rect.top = 64;
        return;
    }
    if (tmp->pos.y > 185 && tmp->pos.x > 1100) {
        tmp->pos.y -= 0.09 * tmp->move->seconds;
        tmp->rect.top = 192;
        return;
    }
    if (tmp->pos.x > 1040 && tmp->pos. y < 185) {
        tmp->pos.x -= 0.09 * tmp->move->seconds;
        tmp->rect.top = 64;
        return;
    }
    move_npc2(tmp);
}

static void gest_move_npc(npc_t *tmp)
{
    tmp->move->time = sfClock_getElapsedTime(tmp->move->clock);
    tmp->move->seconds = sfTime_asMilliseconds(tmp->move->time);
    if (tmp->nb_npc == 2) {
        move_npc(tmp);
    }
    sfClock_restart(tmp->move->clock);
}

static void gest_npc(npc_t *tmp)
{
    if (tmp->nb_npc == 3)
        return;
    tmp->clock_npc->time = sfClock_getElapsedTime(tmp->clock_npc->clock);
    tmp->clock_npc->seconds = sfTime_asMilliseconds(tmp->clock_npc->time);
    if ((tmp->clock_npc->seconds >= 300 && tmp->nb_npc < 2) ||
    tmp->clock_npc->seconds >= 170 && tmp->nb_npc == 2) {
        tmp->rect.left += tmp->length_rect;
        sfClock_restart(tmp->clock_npc->clock);
    }
    gest_move_npc(tmp);
    sfSprite_setPosition(tmp->sprite->spr, tmp->pos);
    if (tmp->rect.left == tmp->length_rect * (tmp->nb_step - 1))
        tmp->rect.left = 0;
}

void display_npc(sfRenderWindow *window, game_t *game, player_t *player)
{
    for (npc_t *tmp = game->npc; tmp; tmp = tmp->next) {
        if (tmp->nb_npc == 2 && tmp->pos.y <= 320 && tmp->pos.x <= 780)
            continue;
        sfSprite_setTextureRect(tmp->sprite->spr, tmp->rect);
        if (tmp->devil == false) {
            sfRenderWindow_drawSprite(window, tmp->sprite->spr, NULL);
            display_chat_logo(window, tmp, player);
        }
        sfSprite_setPosition(game->bubble->spr, (sfVector2f)
        {player->pos.x - 340, player->pos.y + 220});
        if (tmp->conversation == true && tmp->devil == false)
            sfRenderWindow_drawSprite(window, game->bubble->spr, NULL);
        gest_npc(tmp);
    }
}