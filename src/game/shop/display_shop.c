/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** display_game.c
*/

#include "shop.h"

const item_info_t info[] = {
    {"Potion of Healing", "10G"},
    {"Poison Vial", "15G"},
    {"Suspicious Shroom", "2G"}
};


static void display_shop_item(sfRenderWindow *window,
                                shop_t *shop)
{
    int i = 0;
    sfVector2f vect = {0, 0};
    item_t item;

    for (i = 0; i < 8; i += 1) {
        vect.x = 138 + (i % 4) * 147;
        vect.y = 214 + (i / 4) * 143;
        item = shop->shop_item[i];
        if (item.id != 0 && item.quantity > 0) {
            sfSprite_setTexture(item.sprite->spr, item.sprite->text, sfTrue);
            sfSprite_setPosition(item.sprite->spr, vect);
            sfRenderWindow_drawSprite(window, item.sprite->spr, NULL);
        }
    }
}

static void display_inv_item_s(sfRenderWindow *window,
                                inventory_t *inventory)
{
    int i = 0;
    sfVector2f vect = {0, 0};
    item_t item;

    for (i = 0; i < 8; i += 1) {
        vect.x = 1223 + (i % 4) * 147;
        vect.y = 353 + (i / 4) * 138;
        item = inventory->item[i];
        if (item.id != 0 && item.quantity > 0) {
            sfSprite_setTexture(item.sprite->spr, item.sprite->text, sfTrue);
            sfSprite_setPosition(item.sprite->spr, vect);
            sfRenderWindow_drawSprite(window, item.sprite->spr, NULL);
        }
    }
}

static void display_name(sfRenderWindow *window, shop_t *shop)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect rect = sfText_getLocalBounds(shop->text_info);
    int center = 0;
    sfVector2f vect = {mouse.x, mouse.y - 30};
    int id = 0;

    if (shop->id_info != -1 && shop->shop_item[shop->id_info].id != 0) {
        id = shop->shop_item[shop->id_info].id;
        sfText_setString(shop->text_price, info[id - 1].name);
        vect.x -= my_strlen(info[id - 1].name) * 14 / 2;
        sfText_setPosition(shop->text_price, vect);
        sfRenderWindow_drawText(window, shop->text_price, NULL);
    }
}

static void display_price(sfRenderWindow *window, shop_t *shop)
{
    int i = 0;
    int id = 0;
    sfVector2f vect = {0, 0};

    for (i = 0; i < 16; i += 1) {
        if (shop->shop_item[i].id != 0) {
            id = shop->shop_item[i].id;
            vect = (sfVector2f){200 + 147 * (i % 4), 300 + 138 * (i / 4)};
            sfText_setString(shop->text_price, info[id - 1].price);
            sfText_setPosition(shop->text_price, vect);
            sfRenderWindow_drawText(window, shop->text_price, NULL);
        }
    }
}

int display_shop(sfRenderWindow *window, game_t *game,
                    shop_t *shop, player_t *player)
{
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTexture(game->back_sprite, game->back_text, sfTrue);
    sfRenderWindow_drawSprite(window, game->back_sprite, NULL);
    sfView_setSize(game->view, (sfVector2f){game->zoom_x, game->zoom_y});
    sfView_setCenter(game->view, (sfVector2f){960, 540});
    sfRenderWindow_setView(window, game->view);
    sfRenderWindow_drawSprite(window, shop->back->spr, NULL);
    display_shop_item(window, shop);
    display_inv_item_s(window, player->inventory);
    if (display_text_shop(window, player) == 84)
        return 84;
    display_price(window, shop);
    display_name(window, shop);
    sfRenderWindow_display(window);
    return 0;
}