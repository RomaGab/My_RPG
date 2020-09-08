/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** analyse_eventpause.c
*/

#include "shop.h"

const int price[] = {10, 15, 2};

static game_state_t verif_shop(player_t *player, int id, int m)
{
    item_t *item = player->inventory->item;
    int i = 0;

    if (!player || !item)
        return StateError;
    if (m != 1)
        return StateShop;
    while (i < 8) {
        if (player->inventory->item[i].id == Empty)
            break;
        i += 1;
    }
    if (i != 8 && player->gold >= price[id - 1]) {
        item[i] = add_item(item[i], id, 1);
        if (item[i].error == true)
            return StateError;
        player->gold -= price[id - 1];
    }
    return StateShop;
}

static game_state_t item_shop(sfRenderWindow *window, player_t *player,
                            shop_t *shop, sfEvent *event)
{
    int i = 0;
    int m = 0;
    sfVector2f pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    game_state_t scene = StateShop;

    shop->id_info = -1;
    if (event->type == sfEvtMouseButtonPressed)
        m = 1;
    for (i = 0; i < 16; i += 1) {
        pos.x = 138 + (i % 4) * 147;
        pos.y = 214 + (i / 4) * 143;
        if (mouse.x >= pos.x && mouse.x <= pos.x + 119
        && mouse.y >= pos.y && mouse.y <= pos.y + 119
        && shop->shop_item[i].id > 0 && shop->shop_item[i].id < 4) {
            shop->id_info = i;
            scene = verif_shop(player, shop->shop_item[i].id, m);
        }
    }
    return (scene);
}

game_state_t analyse_eventshop(sfRenderWindow *window, player_t *player,
                                shop_t *shop, sfEvent *event)
{
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape) {
        return (StateOver);
    }
    if (event->key.code == sfKeyR) {
        return (StateGame);
    }
    return (item_shop(window, player, shop, event));
}