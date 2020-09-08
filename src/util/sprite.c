/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** sprite.c
*/

#include "util.h"

sprite_t *fill_sprite(char *str)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    if (!sprite)
        return NULL;
    sprite->text = sfTexture_createFromFile(str, NULL);
    sprite->spr = sfSprite_create();
    if (!sprite->text || !sprite->spr)
        return NULL;
    sfSprite_setTexture(sprite->spr, sprite->text, sfTrue);
    return (sprite);
}