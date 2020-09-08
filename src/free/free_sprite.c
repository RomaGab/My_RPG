/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** free_sprite.c
*/

#include "rpg.h"

void free_sprite(sprite_t *sprite)
{
    sfTexture_destroy(sprite->text);
    sfSprite_destroy(sprite->spr);
    free(sprite);
}