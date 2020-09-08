/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gest_pause.c
*/

#include "pause.h"

game_state_t gest_pause(sfRenderWindow *window, game_t *game, sfEvent *event,
                        player_t *player)
{
    pause_t *pause = NULL;
    game_state_t scene = StatePause;

    pause = create_pause(player);
    if (!game || !window || !event || !player || !pause)
        return (StateError);
    game->zoom_x = 1920;
    game->zoom_y = 1080;
    while (scene == StatePause) {
        while (sfRenderWindow_pollEvent(window, event)) {
            scene = analyse_eventpause(window, pause, event, player);
        }
        display_pause(window, game, pause, player);
    }
    free_pause(pause);
    game->zoom_x = 1200;
    game->zoom_y = 675;
    return (scene);
}