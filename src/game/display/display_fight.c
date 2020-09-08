/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_fight.c
*/

#include "fight.h"
#include "game.h"

int check_rect(sfClock *clock)
{
    sfInt64 time = sfClock_getElapsedTime(clock).microseconds;
    static int idx = 0;

    if (sfKeyboard_isKeyPressed(sfKeyRight) == 1 && time > 200000) {
        idx += 1;
        sfClock_restart(clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == 1 && time > 200000) {
        idx -= 1;
        sfClock_restart(clock);
    }
    if (idx == 3)
        idx = 0;
    if (idx == -1)
        idx = 2;
    return idx;
}

void display_cadre(sfRenderWindow *window, fight_t *fight)
{
    int idx = 0;

    idx = check_rect(fight->clock_button);
    if (idx == 1) {
        sfSprite_setTextureRect(fight->cadre->spr,
        (sfIntRect){622, 0, 365, 59});
        sfSprite_setPosition(fight->cadre->spr, (sfVector2f){697, 963});
        fight->choice = 2;
    } else if (idx == 2) {
        sfSprite_setTextureRect(fight->cadre->spr,
        (sfIntRect){1289, 0, 480, 59});
        sfSprite_setPosition(fight->cadre->spr, (sfVector2f){1364, 963});
        fight->choice = 3;
    } else {
        sfSprite_setTextureRect(fight->cadre->spr, (sfIntRect){0, 0, 319, 59});
        sfSprite_setPosition(fight->cadre->spr, (sfVector2f){75, 963});
        fight->choice = 1;
    }
    sfRenderWindow_drawSprite(window, fight->text->spr, NULL);
    sfRenderWindow_drawSprite(window, fight->cadre->spr, NULL);
}

static void set_rect(fight_t *fight)
{
    sfInt64 time = sfClock_getElapsedTime(fight->clock_rect).microseconds;

    if (time >= 220000) {
        fight->rect_boss.left += fight->rect_boss.width;
        fight->rect_champ.top += fight->rect_champ.height;
        sfClock_restart(fight->clock_rect);
    }
    if (fight->rect_boss.left == fight->rect_boss.width * 3)
        fight->rect_boss.left = 0;
    if (fight->rect_champ.top == fight->rect_champ.height * 2)
        fight->rect_champ.top = 0;
}

void draw_fight(sfRenderWindow *window, game_t *game, fight_t *fight,
                player_t *player)
{
    sfRenderWindow_clear(window, sfBlack);
    set_rect(fight);
    game->zoom_x = 1920;
    game->zoom_y = 1080;
    sfView_setSize(game->view, (sfVector2f){game->zoom_x, game->zoom_y});
    sfView_setCenter(game->view, (sfVector2f){960, 540});
    sfSprite_setPosition(game->back_sprite, (sfVector2f){0, 0});
    sfSprite_setPosition(fight->life_bar_one->spr, (sfVector2f){1864, 762});
    sfSprite_setPosition(fight->life_bar_two->spr, (sfVector2f){842, 239});
    sfRenderWindow_setView(window, game->view);
    sfSprite_setTextureRect(fight->boss->spr, fight->rect_boss);
    sfSprite_setTextureRect(fight->champ->spr, fight->rect_champ);
    sfRenderWindow_drawSprite(window, game->back_sprite, NULL);
    sfRenderWindow_drawSprite(window, fight->life_bar_one->spr, NULL);
    sfRenderWindow_drawSprite(window, fight->life_bar_two->spr, NULL);
    sfRenderWindow_drawSprite(window, fight->champ->spr, NULL);
    sfRenderWindow_drawSprite(window, fight->boss->spr, NULL);
    display_icone_state(window, fight);
    display_name(window, fight, player);
}

void display_fight(sfRenderWindow *window, game_t *game, fight_t *fight,
                    player_t *player)
{
    sfInt64 time = sfClock_getElapsedTime(fight->clock_lose).microseconds;

    draw_fight(window, game, fight, player);
    if (fight->attack_turn == 0 && fight->inventory == 0)
        display_cadre(window, fight);
    else if (fight->attack_turn == 0 && fight->inventory == 1)
        display_item_fight(window, fight, player, fight->clock_button);
    else
        attack_turn(window, fight, player);
    if (player->hp <= 0) {
        fight->lose_pos.y += 0.0003 * time;
        sfSprite_setPosition(fight->lose->spr, fight->lose_pos);
        sfRenderWindow_drawSprite(window, fight->lose->spr, NULL);
    } display_win(fight, time, window);
    sfClock_restart(fight->clock_lose);
    sfRenderWindow_display(window);
}