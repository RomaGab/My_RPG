/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_pause.c
*/

#include "shop.h"

void free_shop(shop_t *shop)
{
    free_sprite(shop->back);
    sfText_destroy(shop->text_info);
    sfText_destroy(shop->text_price);
    free(shop->shop_item);
    free(shop);
}