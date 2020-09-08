/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gest_launch.c
*/

#include "launch.h"

static launch_t *create_back(void)
{
    launch_t *launch = malloc(sizeof(launch_t));

    if (!launch)
        return (NULL);
    launch->spr = fill_sprite("res/intro/intro_1.png");
    if (!launch->spr)
        return (NULL);
    launch->logo = fill_sprite("res/back/tchoupi.png");
    if (!launch->logo)
        return (NULL);
    launch->title = fill_sprite("res/back/menu.png");
    if (!launch->title)
        return (NULL);
    return (launch);
}

static launch_t *create_launch(void)
{
    launch_t *launch = NULL;

    launch = create_back();
    if (!launch)
        return (NULL);
    launch->music = sfMusic_createFromFile("res/audio/launch.ogg");
    if (!launch->music)
        return (NULL);
    launch->clock = fill_time();
    if (!launch->clock)
        return (NULL);
    launch->vect_spr = (sfVector2f){0, 0};
    launch->color_logo = (sfColor){255, 255, 255, 0};
    return (launch);
}

game_state_t gest_launch(sfRenderWindow *window, sfEvent event)
{
    game_state_t scene = StateLoad;
    launch_t *launch = create_launch();

    if (!launch)
        return (StateError);
    sfMusic_play(launch->music);
    sfMusic_setVolume(launch->music, 50);
    while (scene == StateLoad) {
        while (sfRenderWindow_pollEvent(window, &event))
            scene = analyse_eventlaunch(&event);
        display_launch(window, launch);
        if (sfMusic_getStatus(launch->music) == sfStopped)
            scene = StateMenu;
    }
    free_launch(launch);
    return (scene);
}