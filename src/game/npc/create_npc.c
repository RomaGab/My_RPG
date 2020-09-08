/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_npc.c
*/

#include "game.h"

static void create_npc2(npc_t *tmp, int i)
{
    float pos[8] = {810, 705, 1640, 185, 1750, 760, -210, -480};
    int rect[8] = {50, 68, 64, 64, 64, 64, 93, 88};

    tmp->length_rect = rect[i * 2];
    tmp->rect = (sfIntRect){0, 0, rect[i * 2], rect[i * 2 + 1]};
    tmp->pos = (sfVector2f){pos[i * 2], pos[i * 2 + 1]};
    tmp->nb_step = (i != 3) ? 3 : 0;
    if (i != 1 && i != 3) {
        tmp->state_quest = no_quest;
        tmp->max_quest = 0;
    } else {
        tmp->state_quest = quest_never;
        tmp->max_quest = 3;
    }
    tmp->nb_quest = 1;
    tmp->where = 0;
    tmp->devil = (i != 3) ? false : true;
}

static void setup_npc_sprite(npc_t *tmp, int i)
{
    int rect[8] = {50, 68, 64, 64, 64, 64, 93, 88};

    sfSprite_setTexture(tmp->sprite->spr, tmp->sprite->text, sfTrue);
    sfSprite_setTexture(tmp->sprite_chat->spr, tmp->sprite_chat->text, sfTrue);
    sfSprite_setScale(tmp->sprite->spr, (sfVector2f) {0.85, 0.85});
    sfSprite_setPosition(tmp->sprite->spr, tmp->pos);
    sfSprite_setPosition(tmp->sprite_chat->spr,
    (sfVector2f){tmp->pos.x + (rect[i * 2] / 2) - 18, tmp->pos.y - 50});
}

npc_t *create_npc(npc_t *npc, int i)
{
    char *what_npc[4] = {"res/sprite/slash.png", "res/sprite/mayor.png",
    "res/sprite/female_npc.png", "res/sprite/boss.png"};
    npc_t *tmp = malloc(sizeof(npc_t));

    if (!tmp)
        return NULL;
    tmp->sprite = fill_sprite(what_npc[i]);
    tmp->sprite_chat = fill_sprite("res/sprite/button_chat.png");
    tmp->move = fill_time();
    tmp->clock_npc = fill_time();
    tmp->dialogue = give_dialogue(i);
    if (!tmp->sprite || !tmp->move || (i != 2 && !tmp->dialogue)
    || !tmp->sprite_chat || !tmp->clock_npc)
        return NULL;
    create_npc2(tmp, i);
    setup_npc_sprite(tmp, i);
    tmp->conversation = false;
    tmp->nb_npc = i;
    tmp->next = npc;
    return tmp;
}