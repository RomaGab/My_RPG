/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** pause.h
*/

#ifndef SHOP_H
#define SHOP_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Inventory*/

struct shop_s
{
    sprite_t *back;
    item_t *shop_item;
    sfText *text_price;
    sfText *text_info;
    int id_info;
};

/*---------------------------------------------------------------------------*/

shop_t *create_shop(game_t *game);

/*---------------------------------------------------------------------------*/

int my_strlen(char const *str);

/*---------------------------------------------------------------------------*/

game_state_t analyse_eventshop(sfRenderWindow *window, player_t *player,
                                shop_t *shop, sfEvent *event);

/*---------------------------------------------------------------------------*/

item_t remove_item(item_t item);
item_t add_item(item_t item, int id, int quantity);

/*---------------------------------------------------------------------------*/

sprite_t *fill_sprite(char *str);

/*---------------------------------------------------------------------------*/

void free_shop(shop_t *shop_ui);
int display_shop(sfRenderWindow *window, game_t *game,
                    shop_t *shop_ui, player_t *player);
void display_logo(sfRenderWindow *window, player_t *player, game_t *game);
void free_sprite(sprite_t *sprite);
int display_text_shop(sfRenderWindow *window, player_t *player);
int center_text(sfText *text, char const *str);

#endif