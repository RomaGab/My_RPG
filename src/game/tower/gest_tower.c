/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** ges_tower.c
*/

#include "tower.h"
#include "game.h"

static void modification_tower(game_t *game, player_t *player)
{
    move_player(player, game);
    check_hitbox_tower(player);
    handle_zoom(game, player);
}

static int init_tower(game_t *game, player_t *player)
{
    sfTexture_destroy(game->back_text);
    game->back_text = sfTexture_createFromFile("res/back/tower.png", NULL);
    if (!game->back_text)
        return 84;
    sfSprite_setTexture(game->back_sprite, game->back_text, sfTrue);
    player->pos = (sfVector2f){-720, -410};
    game->rect_back = (sfIntRect){0, 0, 304, 237};
    sfSprite_setTextureRect(game->back_sprite, game->rect_back);
    sfMusic_stop(game->music->music_city);
    sfMusic_play(game->music->music_tower);
    sfMusic_setLoop(game->music->music_tower, sfTrue);
    sfMusic_setVolume(game->music->music_tower, 30);
    return 0;
}

static game_state_t create_tower(game_t *game, player_t *player)
{
    item_t *item = player->inventory->item;

    if (!item || !game || init_tower(game, player) == 84)
        return StateError;
    return StateTower;
}

static game_state_t loop_event_tower(sfRenderWindow *window, sfEvent *event,
                        game_t *game, player_t *player)
{
    game_state_t scene = StateTower;

    while (sfRenderWindow_pollEvent(window, event)) {
        scene = analyse_eventtower(window, game, event, player);
        if (scene != StateTower)
            return scene;
    }
    return scene;
}

game_state_t gest_tower(sfRenderWindow *window, game_t *game,
                        sfEvent *event, player_t *player)
{
    game_state_t scene = create_tower(game, player);

    if (!game)
        return StateError;
    sfSound_play(game->music->sound_state);
    while (scene == StateTower) {
        scene = loop_event_tower(window, event, game, player);
        if (scene != StateTower)
            break;
        modification_tower(game, player);
        scene = give_gantlet(player, game);
        display_tower(window, game, player);
    }
    sfSound_play(game->music->sound_state);
    sfSprite_setRotation(game->arrow->spr, (float)180);
    player->pos_arrow = (sfVector2f){-402, 1020};
    sfMusic_stop(game->music->music_tower);
    sfMusic_play(game->music->music_city);
    return scene;
}