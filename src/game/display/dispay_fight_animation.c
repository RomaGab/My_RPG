/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** dispay_fight_animation.c
*/

#include "fight.h"

void display_boss_animation(sfRenderWindow *window, fight_t *fight)
{
    sfInt64 time = sfClock_getElapsedTime(fight->clock_button).microseconds;
    sfIntRect rect = {0, 60, 504, 595};

    rect.left = rect.width * (time / 150000);
    if (rect.left >= rect.width * 9)
        rect.left = rect.width;
    sfSprite_setTextureRect(fight->boss_anim->spr, rect);
    sfSprite_setPosition(fight->boss_anim->spr, (sfVector2f){245, 300});
    sfRenderWindow_drawSprite(window, fight->boss_anim->spr, NULL);
}

void display_player_animation(sfRenderWindow *window, fight_t *fight)
{
    sfInt64 time = sfClock_getElapsedTime(fight->clock_button).microseconds;
    sfIntRect rect = {0, 0, 477, 273};

    rect.left = rect.width * (time / 150000);
    if (rect.left > rect.width * 8)
        rect.left = rect.width * 8;
    sfSprite_setTextureRect(fight->play_anim->spr, rect);
    sfSprite_setPosition(fight->play_anim->spr, (sfVector2f){1133, 278});
    sfRenderWindow_drawSprite(window, fight->play_anim->spr, NULL);
}

void display_name(sfRenderWindow *window, fight_t *fight, player_t *player)
{
    const char *name[] = {"Alyssa", "Lucas", "Denis", "Cecile"};

    sfText_setString(fight->text_action, "Tyrannus");
    sfText_setPosition(fight->text_action, (sfVector2f){554, 115});
    sfRenderWindow_drawText(window, fight->text_action, NULL);
    sfText_setString(fight->text_action, name[player->character - 1]);
    sfText_setPosition(fight->text_action, (sfVector2f){1576, 638});
    sfRenderWindow_drawText(window, fight->text_action, NULL);
}

void display_icone_state(sfRenderWindow *window, fight_t *fight)
{
    if (fight->poison_player) {
        sfSprite_setPosition(fight->psn_icn->spr, (sfVector2f){1296, 658});
        sfRenderWindow_drawSprite(window, fight->psn_icn->spr, NULL);
    } if (fight->poison_boss) {
        sfSprite_setPosition(fight->psn_icn->spr, (sfVector2f){274, 135});
        sfRenderWindow_drawSprite(window, fight->psn_icn->spr, NULL);
    } if (fight->poison_sword && !fight->poison_boss) {
        sfSprite_setPosition(fight->psn_swd->spr, (sfVector2f){1386, 658});
        sfRenderWindow_drawSprite(window, fight->psn_swd->spr, NULL);
    } if (fight->defense) {
        sfSprite_setPosition(fight->dfs_spr->spr, (sfVector2f){1092, 628});
        sfRenderWindow_drawSprite(window, fight->dfs_spr->spr, NULL);
    } if (fight->defense_boss) {
        sfSprite_setPosition(fight->dfs_spr->spr, (sfVector2f){70, 105});
        sfRenderWindow_drawSprite(window, fight->dfs_spr->spr, NULL);
    } if (fight->boost == 2) {
        sfSprite_setPosition(fight->boost_spr->spr, (sfVector2f){1476, 658});
        sfRenderWindow_drawSprite(window, fight->boost_spr->spr, NULL);
    }
}