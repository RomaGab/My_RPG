/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** create_shop.c
*/

#include "shop.h"

item_t *init_item_shop(item_t *item_shop, game_t *game)
{
    item_shop[0] = add_item(item_shop[0], Potion_Heal, 1);
    if (item_shop[0].error == true)
        return NULL;
    if (game->quest_id != 1) {
        item_shop[1] = add_item(item_shop[1], Poison_Vial, 1);
        if (item_shop[1].error == true)
            return NULL;
        item_shop[2] = add_item(item_shop[2], Suspisious_Shroom, 1);
        if (item_shop[2].error == true)
            return NULL;
    }
    return (item_shop);
}

item_t *init_shop_inv(game_t *game)
{
    item_t *item_shop = malloc(sizeof(item_t) * 16);
    int i = 0;

    if (!item_shop || !game)
        return (NULL);
    for (i = 0; i < 16; i += 1) {
        item_shop[i].id = Empty;
        item_shop[i].quantity = 0;
        item_shop[i].sprite = NULL;
    }
    item_shop = init_item_shop(item_shop, game);
    if (item_shop == NULL)
        return NULL;
    return (item_shop);
}

static sfText *set_shop_text(sfFont *font, unsigned int size)
{
    sfText *text = sfText_create();

    if (!text || !font)
        return (NULL);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    return (text);
}

shop_t *create_shop(game_t *game)
{
    shop_t *shop = malloc(sizeof(shop_t));

    if (!shop || !game)
        return (NULL);
    shop->back = fill_sprite("res/back/shop_scene.png");
    if (!shop->back)
        return (NULL);
    shop->shop_item = init_shop_inv(game);
    if (!shop->shop_item)
        return (NULL);
    shop->text_price = set_shop_text(game->font, 30);
    if (!shop->text_price)
        return (NULL);
    shop->text_info = set_shop_text(game->font, 30);
    if (!shop->text_info)
        return (NULL);
    shop->id_info = -1;
    return (shop);
}