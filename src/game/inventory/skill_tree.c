/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** skill_tree.c
*/

#include "inventory.h"

void display_button(inventory_ui_t *inventory_ui,
                player_t *player, int idx, sfEvent *event)
{
    if (idx == 1)
        sfSprite_setTextureRect(inventory_ui->button->spr,
        (sfIntRect){48, 0, 48, 46});
    else
        sfSprite_setTextureRect(inventory_ui->button->spr,
        (sfIntRect){0, 0, 48, 46});
}

void gest_skill(inventory_ui_t *inventory_ui, player_t *player, sfEvent *event,
                    game_t *game)
{
    int skill = player->lvl - 1;

    if (skill >= 1 && game->rect.top == 0 &&
    event->mouseButton.x >= 30 && event->mouseButton.x <= 100 &&
    event->mouseButton.y >= 478 && event->mouseButton.y <= 548) {
        game->rect.top = 369;
        player->gold += 50;
    } else if (skill >= 2 && game->rect.top == 369 &&
    event->mouseButton.x >= 216 && event->mouseButton.x <= 286 &&
    event->mouseButton.y >= 478 && event->mouseButton.y <= 548) {
        game->rect.top = 738;
        player->armor += 50;
    } if (player->check == 0 || player->check == 1)
        gest_skill_top(&game->rect, player, skill, event);
    if (player->check == 0 || player->check == 2)
        gest_skill_mid(&game->rect, player, skill, event);
    if (player->check == 0 || player->check == 3)
        gest_skill_bot(&game->rect, player, skill, event);
    sfSprite_setTextureRect(inventory_ui->skill->spr, game->rect);
}

void gest_skill_tree(inventory_ui_t *inventory_ui, player_t *player,
                        sfEvent *event, game_t *game)
{
    int skill = 0;

    sfSprite_setScale(inventory_ui->skill->spr,
    (sfVector2f){inventory_ui->idx, inventory_ui->idx});
    if (event->type != sfEvtMouseButtonPressed)
        return;
    if (event->mouseButton.x >= 747 && event->mouseButton.x <= 793 &&
    event->mouseButton.y >= 280 && event->mouseButton.y <= 328)
        inventory_ui->idx = (inventory_ui->idx == 0) ? 1 : 0;
    display_button(inventory_ui, player, inventory_ui->idx, event);
    if (inventory_ui->idx == 1)
        gest_skill(inventory_ui, player, event, game);
}