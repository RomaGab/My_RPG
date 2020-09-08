/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_help.c
*/

#include "howtoplay.h"

void free_help(howtoplay_t *help)
{
    free_sprite(help->parallax1);
    free_sprite(help->parallax2);
    free_sprite(help->parallax3);
    sfTexture_destroy(help->back_text);
    sfSprite_destroy(help->back_sprite);
    sfClock_destroy(help->clock->clock);
    free(help->clock);
    free(help->button);
    free(help);
}