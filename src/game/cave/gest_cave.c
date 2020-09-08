/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** cave.c
*/

#include "cave.h"

static void modification_cave(game_t *game, player_t *player)
{
    move_player(player, game);
    check_hitbox_cave(player, game);
    handle_zoom(game, player);
}

static int init_cave(game_t *game, player_t *player)
{
    sfTexture_destroy(game->back_text);
    game->back_text = sfTexture_createFromFile("res/back/cave.png", NULL);
    if (!game->back_text)
        return 84;
    sfSprite_setTexture(game->back_sprite, game->back_text, sfTrue);
    player->pos = (sfVector2f){-540, 80};
    game->rect_back = (sfIntRect){0, 0, 1075, 815};
    sfMusic_stop(game->music->music_city);
    sfMusic_play(game->music->music_cave);
    sfMusic_setVolume(game->music->music_cave, 30);
    sfMusic_setLoop(game->music->music_cave, sfTrue);
    return 0;
}

static game_state_t create_cave(game_t *game, player_t *player)
{
    if (!game || init_cave(game, player) == 84)
        return StateError;
    return StateCave;
}

static game_state_t loop_event(sfRenderWindow *window, sfEvent *event,
                        game_t *game, player_t *player)
{
    game_state_t scene = StateCave;

    while (sfRenderWindow_pollEvent(window, event)) {
        scene = analyse_eventcave(window, game, event, player);
        if (scene != StateCave)
            return scene;
    }
    return scene;
}

game_state_t gest_cave(sfRenderWindow *window, game_t *game,
                        sfEvent *event, player_t *player)
{
    game_state_t scene = create_cave(game, player);

    if (!game)
        return StateError;
    sfSound_play(game->music->sound_state);
    while (scene == StateCave) {
        scene = loop_event(window, event, game, player);
        if (scene != StateCave)
            break;
        modification_cave(game, player);
        display_cave(window, game, player);
    }
    sfSound_play(game->music->sound_state);
    sfMusic_stop(game->music->music_cave);
    sfMusic_play(game->music->music_city);
    return scene;
}