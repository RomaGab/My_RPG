/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_rounds.c
*/

#include "fight.h"
#include "game.h"

void boss_play(game_t *game, player_t *player, fight_t *fight)
{
    int i = rand() % 10;

    if (i >= ((fight->hp_boss <= 1000) ? 9 : 10)) {
        fight->boss_choice = 2;
    } else if (i >= ((fight->hp_boss > 1000) ? 6 : 7)) {
        fight->boss_choice = 1;
    } else {
        fight->boss_choice = 0;
    }
}

void hp_bar(player_t *player, fight_t *fight)
{
    int rect = 0;

    rect = (player->hp * 556) / player->hp_max;
    fight->rect_life_one.left = -556 + rect;
    sfSprite_setTextureRect(fight->life_bar_one->spr, fight->rect_life_one);
    rect = (fight->hp_boss * 556) / fight->hp_max_boss;
    fight->rect_life_two.left = -556 + rect;
    sfSprite_setTextureRect(fight->life_bar_two->spr, fight->rect_life_two);
}

void fight_rounds(game_t *game, player_t *player, fight_t *fight)
{
    sfInt64 time = sfClock_getElapsedTime(fight->clock_button).microseconds;

    if (sfKeyboard_isKeyPressed(sfKeyR) == 1 && fight->inventory == 1)
        fight->inventory = 0;
    if (fight->attack_turn == 0 && sfKeyboard_isKeyPressed(sfKeyEnter) == 1
    && time > 200000) {
        if (fight->choice == 3 && fight->inventory == 0) {
            fight->inventory = 1;
            fight->item_index = 0;
            sfClock_restart(fight->clock_button);
        } else if (fight->choice != 3 || (fight->choice == 3
        && fight->inventory == 1 && fight->item_index != -1
        && player->inventory->item[fight->item_index].id != 0)) {
            fight->inventory = 0;
            boss_play(game, player, fight);
            fight->attack_turn = 1;
            sfClock_restart(fight->clock_button);
        }
    }
}