/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** zoom.c
*/

#include "game.h"

void handle_zoom(game_t *game, player_t *player)
{
    game->zoom->time = sfClock_getElapsedTime(game->zoom->clock);
    game->zoom->seconds = sfTime_asMilliseconds(game->zoom->time);
    if (game->first_zoom == false) {
        sfView_setSize(game->view, (sfVector2f){game->zoom_x, game->zoom_y});
        sfView_setCenter(game->view, (sfVector2f)
        {player->pos.x + 32, player->pos.y + 32});
        game->zoom_x -= 0.5 * game->zoom->seconds;
        game->zoom_y -= 0.28125 * game->zoom->seconds;
    }
    sfClock_restart(game->zoom->clock);
    if (game->zoom_x <= 1200) {
        game->zoom_x = 1200;
        game->zoom_y = 675;
        game->first_zoom = true;
    }
    if (game->first_zoom == true) {
        sfView_setSize(game->view, (sfVector2f){game->zoom_x, game->zoom_y});
        sfView_setCenter(game->view, (sfVector2f)
        {player->pos.x + 32, player->pos.y + 32});
    }
}

void create_zoom(game_t *game)
{
    game->zoom_x = 1920;
    game->zoom_y = 1080;
    sfView_setSize(game->view, (sfVector2f){game->zoom_x, game->zoom_y});
    sfView_setCenter(game->view, (sfVector2f){960, 540});
    game->first_zoom = false;
}