/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pause.h
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Inventory*/

struct inventory_ui_s
{
    sprite_t *back;
    sprite_t *champ;
    sprite_t *button;
    sprite_t *skill;
    int idx;
    sfIntRect rect_skill;
};

/*---------------------------------------------------------------------------*/

item_t remove_item(item_t item);
item_t add_item(item_t item, int id, int quantity);

/*---------------------------------------------------------------------------*/

inventory_ui_t *create_inventory_ui(void);

/*---------------------------------------------------------------------------*/

game_state_t analyse_eventinventory(sfRenderWindow *window, player_t *player,
                                inventory_t *inventory, sfEvent *event);

/*---------------------------------------------------------------------------*/

sprite_t *fill_sprite(char *str);

/*---------------------------------------------------------------------------*/

int display_inventory(sfRenderWindow *window, game_t *game,
                    inventory_ui_t *inventory_ui, player_t *player);
int display_text_stats(sfRenderWindow *window, player_t *player);

/*---------------------------------------------------------------------------*/

void free_sprite(sprite_t *sprite);
void free_inventory(inventory_ui_t *inventory_ui);
void display_logo(sfRenderWindow *window, player_t *player, game_t *game);
void gest_skill_tree(inventory_ui_t *inventory_ui, player_t *player,
                        sfEvent *event, game_t *game);
void gest_skill_top(sfIntRect *rect, player_t *player, int skill,
                        sfEvent *event);
void gest_skill_mid(sfIntRect *rect, player_t *player, int skill,
                        sfEvent *event);
void gest_skill_bot(sfIntRect *rect, player_t *player, int skill,
                        sfEvent *event);

#endif