/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** display_game.c
*/

#include "inventory.h"

static void display_item(sfRenderWindow *window, item_t item, sfVector2f vect)
{
    if (item.id != 0 && item.quantity > 0) {
        sfSprite_setTexture(item.sprite->spr, item.sprite->text, sfTrue);
        sfSprite_setPosition(item.sprite->spr, vect);
        sfRenderWindow_drawSprite(window, item.sprite->spr, NULL);
    }
}

static void display_inventory_item(sfRenderWindow *window,
                                inventory_t *inventory)
{
    int i = 0;
    sfVector2f vect = {0, 0};
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    item_t item;

    for (i = 0; i < 8; i += 1) {
        if (inventory->hand_index != i) {
            vect = (sfVector2f){856 + (i % 4) * 147, 384 + (i / 4) * 138};
            display_item(window, inventory->item[i], vect);
        }
    }
    if (inventory->hand_index != -1) {
        vect = (sfVector2f){mouse.x - 60, mouse.y - 60};
        display_item(window, inventory->item[inventory->hand_index], vect);
    }
}

static void display_inventory_ui(sfRenderWindow *window, sfVector2f pos,
                                inventory_ui_t *inventory_ui)
{
    sfIntRect rect = {0, 0, 1920, 1080};

    if (pos.y <= -365 && pos.x <= -710)
        rect.left = 1920;
    else if (pos.y <= 99)
        rect.left = 3840;
    sfSprite_setTextureRect(inventory_ui->back->spr, rect);
    sfRenderWindow_drawSprite(window, inventory_ui->back->spr, NULL);
}

void display_inventory_champ(sfRenderWindow *window,
                            inventory_ui_t *inventory_ui, player_t *player)
{
    sfIntRect rect = {0, 0, 161, 192};

    sfSprite_setPosition(inventory_ui->champ->spr, (sfVector2f){565, 397});
    if (player->character == DENIS)
        rect.left += 161;
    if (player->character == CECILE)
        rect.left += 322;
    if (player->character == ALYSSA)
        rect.left += 483;
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
        rect.top += 192;
    else if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
        rect.top += 384;
    sfSprite_setTextureRect(inventory_ui->champ->spr, rect);
    sfRenderWindow_drawSprite(window, inventory_ui->champ->spr, NULL);
}

int display_inventory(sfRenderWindow *window, game_t *game,
                    inventory_ui_t *inventory_ui, player_t *player)
{
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTexture(game->back_sprite, game->back_text, sfTrue);
    sfRenderWindow_drawSprite(window, game->back_sprite, NULL);
    sfView_setSize(game->view, (sfVector2f){game->zoom_x, game->zoom_y});
    sfView_setCenter(game->view, (sfVector2f){960, 540});
    sfRenderWindow_setView(window, game->view);
    display_inventory_ui(window, player->pos, inventory_ui);
    display_inventory_champ(window, inventory_ui, player);
    display_inventory_item(window, player->inventory);
    sfRenderWindow_drawSprite(window, inventory_ui->skill->spr, NULL);
    if (display_text_stats(window, player) == 84)
        return 84;
    sfRenderWindow_drawSprite(window, inventory_ui->button->spr, NULL);
    sfRenderWindow_display(window);
    return 0;
}