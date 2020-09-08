/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_help.c
*/

#include "highscore.h"

void free_highscore(highscore_t *high)
{
    free_sprite(high->parallax1);
    free_sprite(high->parallax2);
    free_sprite(high->parallax3);
    sfTexture_destroy(high->back_text);
    sfSprite_destroy(high->back_sprite);
    sfClock_destroy(high->clock->clock);
    sfFont_destroy(high->font);
    sfText_destroy(high->text_highscore);
    sfText_destroy(high->text_lastscore);
    free(high->clock);
    free(high->button);
    free(high);
}