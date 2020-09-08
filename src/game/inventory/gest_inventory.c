/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gest_pause.c
*/

#include "inventory.h"

game_state_t gest_inventory(sfRenderWindow *window, game_t *game,
                        sfEvent *event, player_t *player)
{
    inventory_ui_t *inventory_ui = NULL;
    game_state_t scene = StateInventory;

    inventory_ui = create_inventory_ui();
    if (!game || !window || !event || !player || !inventory_ui)
        return (StateError);
    game->zoom_x = 1920;
    game->zoom_y = 1080;
    while (scene == StateInventory) {
        while (sfRenderWindow_pollEvent(window, event)) {
            scene = analyse_eventinventory(window, player,
                                            player->inventory, event);
            gest_skill_tree(inventory_ui, player, event, game);
        } if (display_inventory(window, game, inventory_ui, player) == 84)
            return StateError;
    } player->inventory->hand_index = -1;
    free_inventory(inventory_ui);
    game->zoom_x = 1200;
    game->zoom_y = 675;
    return (scene);
}