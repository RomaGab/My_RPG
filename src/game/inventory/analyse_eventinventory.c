/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** analyse_eventpause.c
*/

#include "inventory.h"

static game_state_t swap_item_place(inventory_t *inventory, int i)
{
    item_t stock;

    if (!inventory)
        return StateError;
    stock = inventory->item[i];
    inventory->item[i] = inventory->item[inventory->hand_index];
    inventory->item[inventory->hand_index] = stock;
    if (inventory->item[inventory->hand_index].id == 0) {
        inventory->hand_index = -1;
    } else if (inventory->hand_index == i) {
        inventory->hand_index = -1;
    }
    return StateInventory;
}

static game_state_t item_inventory(sfRenderWindow *window,
                            inventory_t *inventory, sfEvent *event)
{
    int i = 0;
    int m = 0;
    sfVector2f pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (event->type == sfEvtMouseButtonPressed)
        m = 1;
    for (i = 0; i < 8; i += 1) {
        pos.x = 856 + (i % 4) * 147;
        pos.y = 384 + (i / 4) * 138;
        if (m == 1 && mouse.x >= pos.x && mouse.x <= pos.x + 119
        && mouse.y >= pos.y && mouse.y <= pos.y + 119
        && inventory->hand_index == -1 && inventory->item[i].id != 0) {
            inventory->hand_index = i;
        } else if (m == 1 && mouse.x >= pos.x && mouse.x <= pos.x + 119
        && mouse.y >= pos.y && mouse.y <= pos.y + 119
        && inventory->hand_index != -1) {
            if (swap_item_place(inventory, i) == StateError)
                return StateError;
        }
    } return (StateInventory);
}

game_state_t analyse_eventinventory(sfRenderWindow *window, player_t *player,
                                inventory_t *inventory, sfEvent *event)
{
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape) {
        return (StateOver);
    }
    if (event->key.code == sfKeyR) {
        if (player->pos.y <= -365 && player->pos.x <= -710)
            return StateTower;
        else if (player->pos.y <= 99)
            return StateCave;
        else
            return StateGame;
    }
    return (item_inventory(window, inventory, event));
}