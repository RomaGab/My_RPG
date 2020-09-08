/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** add_item.c
*/

#include "game.h"

const char *path[] = {
    "res/item/potion_heal.png",
    "res/item/poison.png",
    "res/item/shroom.png",
    "res/item/gantlet.png"
};

item_t add_item(item_t item, int id, int quantity)
{
    item.error = true;
    if (id > 0 && id < 5) {
        item.id = id;
        item.quantity = quantity;
        item.sprite = malloc(sizeof(sprite_t));
        if (!item.sprite)
            return item;
        item.sprite->text = sfTexture_createFromFile(path[id - 1], NULL);
        if (!item.sprite->text)
            return item;
        item.sprite->spr = sfSprite_create();
        item.error = false;
    }
    return item;
}