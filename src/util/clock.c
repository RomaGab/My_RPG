/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** time.c
*/

#include "util.h"

clocks_t *fill_time(void)
{
    clocks_t *clock = malloc(sizeof(clocks_t));

    if (!clock)
        return NULL;
    clock->clock = sfClock_create();
    if (!clock->clock)
        return NULL;
    clock->time = sfClock_getElapsedTime(clock->clock);
    clock->seconds = sfTime_asMilliseconds(clock->time);
    return clock;
}