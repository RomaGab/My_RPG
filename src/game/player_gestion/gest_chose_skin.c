/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** gest_chose_skin.c
*/

#include "player.h"

static int create_parallax(skin_t *skin)
{
    skin->parallax1 = fill_sprite("res/back/parallax_1.png");
    skin->parallax2 = fill_sprite("res/back/parallax_2.png");
    skin->parallax3 = fill_sprite("res/back/parallax_3.png");
    if (!skin->parallax1 || !skin->parallax2 || !skin->parallax3)
        return 84;
    skin->pos1 = (sfVector2f){0, 0};
    skin->pos2 = (sfVector2f){0, 0};
    skin->pos3 = (sfVector2f){0, 0};
    return 0;
}

static skin_t *init_skin(void)
{
    skin_t *skin = malloc(sizeof(skin_t));

    if (!skin)
        return NULL;
    skin->back = fill_sprite("res/back/chose_skin.png");
    skin->back_rect = (sfIntRect){0, 0, 1920, 1080};
    skin->sprite_laser = fill_sprite("res/sprite/laser.png");
    skin->laser_rect = (sfIntRect){0, 0, 184, 1080};
    skin->vect_laser = (sfVector2f){-1, 0};
    skin->laser = fill_time();
    skin->skin = fill_time();
    skin->clock_par = fill_time();
    if (!skin->back || !skin->sprite_laser || !skin->clock_par ||
    !skin->laser || !skin->skin || create_parallax(skin) == 84)
        return NULL;
    return skin;
}

static void init_empty_player2(player_t *player)
{
    player->over = false;
    player->player_spr = NULL;
    player->pos = (sfVector2f){0, 0};
    player->pos_arrow = (sfVector2f){0, 0};
    player->rect = (sfIntRect){0, 0, 0, 0};
    player->rect_char = (sfIntRect){0, 0, 0, 0};
    player->rect_class = (sfIntRect){0, 0, 0, 0};
    player->strength = 0;
    player->xp = 0;
    player->text_gold = NULL;
    player->text_hp = NULL;
    player->text_lvl = NULL;
    player->text_strength = NULL;
}

static player_t *init_empty_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return NULL;
    player->over = false;
    player->char_logo = NULL;
    player->character = NO_PLAYER;
    player->class = NO_CLASS;
    player->class_logo = NULL;
    player->clock = NULL;
    player->clock_move = NULL;
    player->gold = 0;
    player->hp = 0;
    player->hp_max = 0;
    player->inventory = NULL;
    player->lvl = 0;
    player->check = 0;
    init_empty_player2(player);
    return player;
}

player_t *gest_chose_skin(sfRenderWindow *window, sfEvent *event)
{
    player_t *player = init_empty_player();
    game_state_t scene = StatePlayer;
    skin_t *skin = init_skin();

    if (!player || !skin)
        return NULL;
    while (scene == StatePlayer) {
        while (sfRenderWindow_pollEvent(window, event))
            scene = analyse_eventplayer(window, event, player, skin);
        if (scene == StateError)
            return NULL;
        scene = display_player_back(window, skin, scene);
    } free_skin(skin);
    if (scene != StateError) {
        if (scene == StateOver)
            return player;
        scene = gest_class(player, window, event);
        return (scene != StateError) ? player : NULL;
    } return NULL;
}