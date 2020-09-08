/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_item_fight.c
*/

#include "fight.h"

const char *item_name[] = {
    "Potion of Healing",
    "Poison Vial",
    "Suspicious Shroom",
    "The Doume"
};

static void check_item_rect(fight_t *fight, sfClock *clock)
{
    sfInt64 time = sfClock_getElapsedTime(clock).microseconds;

    if (sfKeyboard_isKeyPressed(sfKeyLeft) == 1 && time > 200000) {
        fight->item_index -= ((fight->item_index >= 2) ? 2 : 0);
        sfClock_restart(clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == 1 && time > 200000) {
        fight->item_index -= ((fight->item_index >= 1) ? 1 : 0);
        sfClock_restart(clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == 1 && time > 200000) {
        fight->item_index += ((fight->item_index <= 6) ? 1 : 0);
        sfClock_restart(clock);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == 1 && time > 200000) {
        fight->item_index += ((fight->item_index <= 5) ? 2 : 0);
        sfClock_restart(clock);
    }
}

static void display_item_cadre(sfRenderWindow *window, fight_t *fight,
                        player_t *player)
{
    int idx = fight->item_index;
    sfVector2f vect = {0, 0};

    if (idx != -1) {
        vect = (sfVector2f){90 + 430 * (idx / 2), 912 + 40 * (idx % 2)};
        sfRectangleShape_setPosition(fight->item_selec, vect);
        sfRenderWindow_drawRectangleShape(window, fight->item_selec, NULL);
    }
}

void display_item_fight(sfRenderWindow *window, fight_t *fight,
                        player_t *player, sfClock *clock)
{
    int idx = 0;
    item_t *item = player->inventory->item;
    sfVector2f vect = {0, 0};

    if (verif_item_inv(player->inventory->item) == 0) {
        sfText_setString(fight->item_name, "No item in inventory. Press [R]");
        sfText_setPosition(fight->item_name, (sfVector2f){100, 910});
        sfRenderWindow_drawText(window, fight->item_name, NULL);
        return;
    }
    check_item_rect(fight, clock);
    for (idx = 0; idx < 8; idx += 1) {
        vect = (sfVector2f){100 + 430 * (idx / 2), 910 + 40 * (idx % 2)};
        if (item[idx].id != 0) {
            sfText_setString(fight->item_name, item_name[item[idx].id - 1]);
            sfText_setPosition(fight->item_name, vect);
            sfRenderWindow_drawText(window, fight->item_name, NULL);
        }
    }
    display_item_cadre(window, fight, player);
}