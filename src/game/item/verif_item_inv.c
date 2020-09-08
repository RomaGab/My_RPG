/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** verif_item.c
*/

#include "game.h"

int verif_item_inv(item_t *item)
{
    int i = 0;

    for (i = 0; i < 8 && item[i].id == 0; i += 1);
    if (i == 8)
        return (0);
    return (1);
}