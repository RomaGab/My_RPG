/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gest_pause.c
*/

#include "shop.h"

game_state_t gest_shop(sfRenderWindow *window, game_t *game,
                        sfEvent *event, player_t *player)
{
    shop_t *shop = NULL;
    game_state_t scene = StateShop;

    shop = create_shop(game);
    if (!game || !window || !event || !player || !shop)
        return (StateError);
    game->zoom_x = 1920;
    game->zoom_y = 1080;
    while (scene == StateShop) {
        while (sfRenderWindow_pollEvent(window, event)
        && scene == StateShop) {
            scene = analyse_eventshop(window, player, shop, event);
        }
        display_shop(window, game, shop, player);
    }
    free_shop(shop);
    game->zoom_x = 1200;
    game->zoom_y = 675;
    return (scene);
}