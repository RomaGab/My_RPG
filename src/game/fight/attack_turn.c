/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight_action.c
*/

#include "fight.h"

static void boss_turn(fight_t *fight, player_t *player)
{
    int damage = (fight->att_boss - player->armor / 10) / (fight->defense + 1);

    if (fight->boss_choice == 2) {
        fight->hp_boss += 50;
    } else if (fight->boss_choice == 1) {
        fight->defense_boss = 1;
    } else {
        player->hp -= damage;
    }
    fight->defense = 0;
}

static void draw_boss_turn(sfRenderWindow *window, fight_t *fight,
                    player_t *player, sfInt64 time)
{
    const char *action_boss[] = {
        "Tyrannus uses a spell !",
        "Tyrannus defends himself.",
        "Tyrannus heals himself."
    };

    sfText_setString(fight->text_action, action_boss[fight->boss_choice]);
    sfText_setPosition(fight->text_action, (sfVector2f){35, 925});
    sfRenderWindow_drawText(window, fight->text_action, NULL);
    if (fight->boss_choice == 0)
        display_boss_animation(window, fight);
    if (time > 1500000) {
        fight->attack_turn += 1;
        boss_turn(fight, player);
        sfClock_restart(fight->clock_button);
    }
}

static void player_turn(fight_t *fight, player_t *player)
{
    int damage = (player->strength * fight->boost) / (fight->defense_boss + 1);

    if (fight->choice == 1) {
        fight->hp_boss -= damage;
        if (fight->poison_sword == true)
            fight->poison_boss = true;
    } else if (fight->choice == 2) {
        fight->defense = 1;
    } else {
        redirect_item(fight, player);
    }
    fight->defense_boss = 0;
}

static void draw_player_turn(sfRenderWindow *window, fight_t *fight,
                        player_t *player, sfInt64 time)
{
    const char *action[] = {
        "Alyssa attacks !", "Alyssa defends herself.", "Alyssa uses an item !",
        "Lucas attacks !", "Lucas defends himself.", "Lucas uses an item !",
        "Denis attacks !", "Denis defends himself.", "Denis uses an item !",
        "Cecile attacks !", "Cecile defends herself.", "Cecile uses an item !"};
    int action_id = 3 * (player->character - 1) + (fight->choice - 1);

    sfText_setString(fight->text_action, action[action_id]);
    sfText_setPosition(fight->text_action, (sfVector2f){35, 925});
    sfRenderWindow_drawText(window, fight->text_action, NULL);
    if (fight->choice == 1)
        display_player_animation(window, fight);
    if (time > 1500000) {
        fight->attack_turn += 1;
        player_turn(fight, player);
        sfClock_restart(fight->clock_button);
    }
}

void attack_turn(sfRenderWindow *window, fight_t *fight, player_t *player)
{
    sfInt64 time = sfClock_getElapsedTime(fight->clock_button).microseconds;

    if (fight->attack_turn == 1) {
        draw_player_turn(window, fight, player, time);
    } else if (fight->attack_turn == 2) {
        draw_boss_turn(window, fight, player, time);
    }
    if (fight->attack_turn == 3) {
        if (fight->poison_boss)
            fight->hp_boss -= 150;
        if (fight->poison_player)
            player->hp -= 50;
        fight->attack_turn = 0;
    }
}