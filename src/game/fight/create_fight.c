/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** create_fight.c
*/

#include "fight.h"

static int create_spr_icone(fight_t *fight)
{
    if (!fight)
        return (84);
    fight->psn_icn = fill_sprite("res/sprite/poison_state.png");
    if (!fight->psn_icn)
        return (84);
    fight->psn_swd = fill_sprite("res/sprite/poison_sword.png");
    if (!fight->psn_swd)
        return (84);
    fight->boost_spr = fill_sprite("res/sprite/boost.png");
    if (!fight->boost_spr)
        return (84);
    fight->dfs_spr = fill_sprite("res/sprite/defence_state.png");
    if (!fight->dfs_spr)
        return (84);
    fight->poison_player = false;
    fight->poison_sword = false;
    fight->poison_boss = false;
    fight->boost = 1;
    return (0);
}

static int create_item_text(fight_t *fight, game_t *game)
{
    if (!fight)
        return (84);
    fight->item_name = sfText_create();
    if (!fight->item_name)
        return (84);
    fight->text_action = sfText_create();
    if (!fight->text_action)
        return (84);
    sfText_setFont(fight->item_name, game->font);
    sfText_setFont(fight->text_action, game->font);
    sfText_setColor(fight->item_name, sfBlack);
    sfText_setColor(fight->text_action, sfBlack);
    sfText_setCharacterSize(fight->item_name, 35);
    sfText_setCharacterSize(fight->text_action, 50);
    return (0);
}

static int create_item_rect(fight_t *fight)
{
    if (!fight)
        return (84);
    fight->item_selec = sfRectangleShape_create();
    if (!fight->item_selec)
        return (84);
    sfRectangleShape_setOutlineThickness(fight->item_selec, 3);
    sfRectangleShape_setOutlineColor(fight->item_selec, sfBlack);
    sfRectangleShape_setFillColor(fight->item_selec, sfTransparent);
    sfRectangleShape_setSize(fight->item_selec, (sfVector2f){310, 40});
    return (0);
}

static int init_fight(game_t *game, fight_t *fight, player_t *player)
{
    sfTexture_destroy(game->back_text);
    game->back_text = sfTexture_createFromFile("res/back/fight.png", NULL);
    if (!game->back_text || fill_fight(fight, player) == 84)
        return 84;
    game->rect_back = (sfIntRect){0, 0, 1920, 1080};
    if (create_item_text(fight, game) == 84)
        return 84;
    if (create_item_rect(fight) == 84)
        return 84;
    if (create_spr_icone(fight) == 84)
        return 84;
    sfSprite_setOrigin(game->back_sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(game->back_sprite, game->back_text, sfTrue);
    sfMusic_stop(game->music->music_cave);
    sfMusic_setLoop(game->music->music_boss, sfTrue);
    sfMusic_setVolume(game->music->music_boss, 20);
    sfMusic_play(game->music->music_boss);
    return 0;
}

game_state_t create_fight(game_t *game, fight_t *fight,
                                player_t *player)
{
    if (!game || !fight || init_fight(game, fight, player) == 84)
        return StateError;
    fight->clock_button = sfClock_create();
    fight->clock_rect = sfClock_create();
    fight->clock_lose = sfClock_create();
    if (!fight->clock_button || !fight->clock_rect || !fight->clock_lose)
        return StateError;
    return StateFight;
}