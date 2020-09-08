/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fill_fight.c
*/

#include "game.h"
#include "fight.h"

static int fill_animation(fight_t *fight)
{
    fight->play_anim = fill_sprite("res/sprite/spell_champ.png");
    if (!fight->play_anim)
        return (84);
    fight->boss_anim = fill_sprite("res/sprite/spell_animation_boss.png");
    if (!fight->boss_anim)
        return (84);
    return (0);
}

void fill_champ(fight_t *fight, player_t *player)
{
    fight->rect_champ = (sfIntRect){0, 0, 312, 334};
    if (player->character == LUCAS)
        fight->rect_champ.left = 0;
    if (player->character == DENIS)
        fight->rect_champ.left = 312;
    if (player->character == CECILE)
        fight->rect_champ.left = 624;
    if (player->character == ALYSSA)
        fight->rect_champ = (sfIntRect){954, 0, 324, 334};
    sfSprite_setPosition(fight->champ->spr, (sfVector2f){351, 562});
    sfSprite_setTextureRect(fight->champ->spr, fight->rect_champ);
}

void fill_life_bars(fight_t *fight)
{
    fight->hp_boss = 5000;
    fight->hp_max_boss = 5000;
    fight->rect_life_one = (sfIntRect){0, 0, 556, 26};
    fight->rect_life_two = (sfIntRect){0, 0, 556, 26};
    sfSprite_setTextureRect(fight->life_bar_one->spr, fight->rect_life_one);
    sfSprite_setTextureRect(fight->life_bar_two->spr, fight->rect_life_two);
    sfSprite_setScale(fight->life_bar_one->spr, (sfVector2f){-1, 1});
    sfSprite_setScale(fight->life_bar_two->spr, (sfVector2f){-1, 1});
    sfSprite_setPosition(fight->boss->spr, (sfVector2f){1231, 255});
}

int fill_ui_fight(fight_t *fight)
{
    fight->cadre = fill_sprite("res/sprite/cadre.png");
    fight->text = fill_sprite("res/sprite/text_fight.png");
    fight->lose = fill_sprite("res/back/lose_screen.png");
    fight->win = fill_sprite("res/back/win_screen.png");
    if (!fight->text || !fight->cadre || !fight->lose || !fight->win)
        return 84;
    sfSprite_setTextureRect(fight->cadre->spr, (sfIntRect){0, 0, 319, 59});
    sfSprite_setPosition(fight->text->spr, (sfVector2f){96, 976});
    fight->lose_pos = (sfVector2f){0, -1280};
    fight->win_pos = (sfVector2f){0, 1280};
    fight->att_boss = 120;
    fight->turn = 0;
    fight->defense = 0;
    fight->defense_boss = 0;
    return 0;
}

int fill_fight(fight_t *fight, player_t *player)
{
    fight->life_bar_one = fill_sprite("res/sprite/life_bar.png");
    fight->life_bar_two = fill_sprite("res/sprite/life_bar.png");
    fight->boss = fill_sprite("res/sprite/boss_fight.png");
    fight->champ = fill_sprite("res/sprite/fight_champion.png");
    if (!fight->life_bar_one || !fight->life_bar_two || !fight->boss
    || !fight->champ || fill_ui_fight(fight) == 84
    || fill_animation(fight) == 84)
        return 84;
    fight->rect_boss = (sfIntRect){0, 0, 285, 270};
    sfSprite_setTextureRect(fight->boss->spr, fight->rect_boss);
    fill_champ(fight, player);
    fill_life_bars(fight);
    fight->choice = 0;
    fight->boss_choice = 0;
    fight->attack_turn = 0;
    fight->item_index = 0;
    fight->inventory = 0;
    return 0;
}