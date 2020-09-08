/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_pause.c
*/

#include "inventory.h"

void free_inventory(inventory_ui_t *inventory_ui)
{
    free_sprite(inventory_ui->back);
    free_sprite(inventory_ui->champ);
    free_sprite(inventory_ui->skill);
    free_sprite(inventory_ui->button);
    free(inventory_ui);
}