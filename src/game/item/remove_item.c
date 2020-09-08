/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** remove_item.c
*/

#include "game.h"

item_t remove_item(item_t item)
{
    item.id = Empty;
    item.quantity = 0;
    sfSprite_destroy(item.sprite->spr);
    sfTexture_destroy(item.sprite->text);
    free(item.sprite);
    item.sprite = NULL;
    return (item);
}