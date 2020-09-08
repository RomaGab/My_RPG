/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** move_player.c
*/

#include "game.h"

static void move_player_left(player_t *player, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        if (player->clock->seconds >= 150) {
            player->rect.top = 64;
            player->rect.left += 64;
            if (player->rect.left == 192)
                player->rect.left = 0;
            sfClock_restart(player->clock->clock);
        }
        player->pos.x -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x -= 0.1733 * player->clock_move->seconds;
        if (player->pos.x >= game->pos_box.x + 54 && player->pos.x <=
        game->pos_box.x + 54 + player->clock_move->seconds && player->pos.y +
        player->rect.height - 15 >= game->pos_box.y &&
        player->pos.y + player->rect.height - 15 <= game->pos_box.y + 34)
            game->pos_box.x -= 0.1333 * player->clock_move->seconds;
    }
}

static void move_player_right(player_t *player, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        if (player->clock->seconds >= 150) {
            player->rect.top = 128;
            player->rect.left += 64;
            if (player->rect.left == 192)
                player->rect.left = 0;
            sfClock_restart(player->clock->clock);
        }
        player->pos.x += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.x += 0.1733 * player->clock_move->seconds;
        if (player->pos.x + 32 <= game->pos_box.x && player->pos.x + 32 >=
        game->pos_box.x - player->clock_move->seconds && player->pos.y +
        player->rect.height - 15 >= game->pos_box.y &&
        player->pos.y + player->rect.height - 15 <= game->pos_box.y + 34)
            game->pos_box.x += 0.1333 * player->clock_move->seconds;
    }
}

static void move_player_down(player_t *player, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        if (player->clock->seconds >= 150) {
            player->rect.top = 0;
            player->rect.left += 64;
            if (player->rect.left == 192)
                player->rect.left = 0;
            sfClock_restart(player->clock->clock);
        }
        player->pos.y += 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y += 0.1733 * player->clock_move->seconds;
        if (player->pos.y + player->rect.height - 17 >= game->pos_box.y -
        player->clock_move->seconds && player->pos.y +
        player->rect.height - 16 <= game->pos_box.y && player->pos.x +
        player->rect.height - 16 >= game->pos_box.x && player->pos.x +
        15 <= game->pos_box.x + 74)
            game->pos_box.y += 0.1333 * player->clock_move->seconds;
    }
}

static void move_player_up(player_t *player, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        if (player->clock->seconds >= 150) {
            player->rect.top = 192;
            player->rect.left += 64;
            if (player->rect.left == 192)
                player->rect.left = 0;
            sfClock_restart(player->clock->clock);
        }
        player->pos.y -= 0.1333 * player->clock_move->seconds;
        player->pos_arrow.y -= 0.1733 * player->clock_move->seconds;
        if (player->pos.y + player->rect.height - 17 >= game->pos_box.y + 34 -
        player->clock_move->seconds && player->pos.y +
        player->rect.height - 16 <= game->pos_box.y + 34 && player->pos.x +
        player->rect.height - 16 >= game->pos_box.x && player->pos.x +
        15 <= game->pos_box.x + 74)
            game->pos_box.y -= 0.1333 * player->clock_move->seconds;
    }
}

void move_player(player_t *player, game_t *game)
{
    if (game->first_zoom == false)
        return;
    if (game->verif_zoom == false) {
        sfClock_restart(player->clock_move->clock);
        game->verif_zoom = true;
    }
    player->clock->time = sfClock_getElapsedTime(player->clock->clock);
    player->clock->seconds = sfTime_asMilliseconds(player->clock->time);
    player->clock_move->time = sfClock_getElapsedTime(
    player->clock_move->clock);
    player->clock_move->seconds = sfTime_asMilliseconds(
    player->clock_move->time);
    move_player_down(player, game);
    move_player_right(player, game);
    move_player_left(player, game);
    move_player_up(player, game);
    sfClock_restart(player->clock_move->clock);
}