/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_launch.c
*/

#include "launch.h"

void free_launch(launch_t *launch)
{
    free_sprite(launch->spr);
    free_sprite(launch->logo);
    free_sprite(launch->title);
    sfClock_destroy(launch->clock->clock);
    free(launch->clock);
    sfMusic_destroy(launch->music);
    free(launch);
}