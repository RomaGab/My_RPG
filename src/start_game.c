/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** start_game.c
*/

#include "rpg.h"

const scene_t scene[] =
{
    {&gest_launch},
    {&gest_menu},
    {&gest_game}
};

int start_game(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "Tchoupi",
    sfClose, NULL);
    sfEvent event;
    game_state_t flg = StateLoad;

    sfRenderWindow_setPosition(window, (sfVector2i){0, 0});
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window) &&
    flg != StateError && flg != StateOver) {
        flg = scene[flg].fptr(window, event);
    }
    free_window(window);
    if (flg == StateError)
        return (84);
    return (0);
}