/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** create_inventory.c
*/

#include "inventory.h"

inventory_ui_t *create_inventory_ui(void)
{
    inventory_ui_t *inventory_ui = malloc(sizeof(inventory_ui_t));

    if (!inventory_ui) {
        return (NULL);
    }
    inventory_ui->back = fill_sprite("res/back/inventory_scene.png");
    inventory_ui->champ = fill_sprite("res/sprite/inventory_champion.png");
    inventory_ui->button = fill_sprite("res/sprite/skill_button.png");
    inventory_ui->skill = fill_sprite("res/sprite/skill_rpg.png");
    if (!inventory_ui->back || !inventory_ui->champ || !inventory_ui->button
    || !inventory_ui->skill)
        return (NULL);
    inventory_ui->idx = 0;
    inventory_ui->rect_skill = (sfIntRect){0, 0, 442, 369};
    sfSprite_setTextureRect(inventory_ui->button->spr,
    (sfIntRect){0, 0, 48, 46});
    sfSprite_setScale(inventory_ui->skill->spr, (sfVector2f){0, 0});
    sfSprite_setPosition(inventory_ui->button->spr, (sfVector2f){747, 280});
    sfSprite_setPosition(inventory_ui->skill->spr, (sfVector2f){30, 328});
    return (inventory_ui);
}