/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_pause.c
*/

#include "pause.h"

void free_pause(pause_t *pause)
{
    int i = 0;

    sfSprite_destroy(pause->sprite);
    sfTexture_destroy(pause->texture);
    free_sprite(pause->back_sprite);
    for (i = 0; i <= 1; i += 1) {
        sfSprite_destroy(pause->button[i].sprite);
        sfTexture_destroy(pause->button[i].texture);
    }
    free(pause->button);
    free(pause);
}