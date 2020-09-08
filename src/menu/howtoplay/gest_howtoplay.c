/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gest_howtoplay.c
*/

#include "howtoplay.h"

game_state_t gest_howtoplay(sfRenderWindow *window, sfEvent *event)
{
    game_state_t scene = StateHowtoplay;
    howtoplay_t *help = NULL;

    if (!window || !event)
        return (StateError);
    help = create_help();
    if (!help)
        return StateError;
    while (scene == StateHowtoplay) {
        while (sfRenderWindow_pollEvent(window, event)) {
            scene = analyse_eventhowtoplay(window, event, help);
        }
        display_help(window, help);
    }
    free_help(help);
    return (scene);
}