/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** free_fight.c
*/

#include "fight.h"

void free_more(fight_t *fight)
{
    sfClock_destroy(fight->clock_button);
    sfClock_destroy(fight->clock_rect);
    sfClock_destroy(fight->clock_lose);
    free_sprite(fight->win);
    free(fight);
}

void free_fight(fight_t *fight)
{
    free_sprite(fight->life_bar_one);
    free_sprite(fight->life_bar_two);
    free_sprite(fight->champ);
    free_sprite(fight->boss);
    free_sprite(fight->text);
    free_sprite(fight->cadre);
    free_sprite(fight->lose);
    free_sprite(fight->psn_icn);
    free_sprite(fight->psn_swd);
    free_sprite(fight->boost_spr);
    free_sprite(fight->dfs_spr);
    free_sprite(fight->boss_anim);
    free_sprite(fight->play_anim);
    sfText_destroy(fight->item_name);
    sfText_destroy(fight->text_action);
    sfRectangleShape_destroy(fight->item_selec);
    free_more(fight);
}
