/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** gest_fight.c
*/

#include "fight.h"

static void modification_fight(game_t *game, fight_t *fight, player_t *player)
{
    fight_rounds(game, player, fight);
    hp_bar(player, fight);
}

static game_state_t loop_eventfight(sfRenderWindow *window, sfEvent *event,
                        game_t *game, player_t *player)
{
    game_state_t scene = StateFight;

    while (sfRenderWindow_pollEvent(window, event)) {
        scene = analyse_eventfight(window, game, event, player);
        if (scene != StateFight)
            return scene;
    }
    return scene;
}

game_state_t gest_fight(sfRenderWindow *window, sfEvent *event,
                        game_t *game, player_t *player)
{
    fight_t *fight = malloc(sizeof(fight_t));
    game_state_t scene = create_fight(game, fight, player);

    if (!game || !fight || scene == StateError)
        return StateError;
    while (scene == StateFight) {
        scene = loop_eventfight(window, event, game, player);
        if (fight->lose_pos.y >= 0 || fight->win_pos.y <= 0)
            scene = StateMenu;
        if (scene != StateFight)
            break;
        modification_fight(game, fight, player);
        display_fight(window, game, fight, player);
    }
    if (new_score(game, fight) == 84)
        return StateError;
    sfMusic_stop(game->music->music_boss);
    sfMusic_play(game->music->music_cave);
    free_fight(fight);
    return scene;
}