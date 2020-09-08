/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** game.h
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Game*/

game_state_t gest_shop(sfRenderWindow *window, game_t *game,
                        sfEvent *event, player_t *player);

game_state_t gest_cave(sfRenderWindow *window, game_t *game,
                        sfEvent *event, player_t *player);

game_state_t gest_tower(sfRenderWindow *window, game_t *game,
                        sfEvent *event, player_t *player);

game_state_t gest_inventory(sfRenderWindow *window, game_t *game,
                        sfEvent *event, player_t *player);

game_state_t analyse_eventgame(sfRenderWindow *window, game_t *game,
                                sfEvent *event, player_t *player);

game_state_t gest_pause(sfRenderWindow *window, game_t *game, sfEvent *event,
                        player_t *player);

game_state_t interaction_npc(game_t *game, player_t *player, sfEvent *event,
                            sfRenderWindow *window);

/*---------------------------------------------------------------------------*/

sprite_t *fill_sprite(char *str);

/*---------------------------------------------------------------------------*/

game_t *create_game(void);

/*---------------------------------------------------------------------------*/

player_t *gest_chose_skin(sfRenderWindow *window, sfEvent *event);

/*---------------------------------------------------------------------------*/

item_t remove_item(item_t item);
item_t add_item(item_t item, int id, int quantity);

/*---------------------------------------------------------------------------*/

npc_t *create_npc(npc_t *npc, int i);

/*---------------------------------------------------------------------------*/

clocks_t *fill_time(void);

/*---------------------------------------------------------------------------*/

music_t *fill_music(void);

/*---------------------------------------------------------------------------*/

char *int_str(int nbr);
char **give_dialogue(int i);

/*---------------------------------------------------------------------------*/

int chose_nb(npc_t *tmp);
int init_text_player(player_t *player, game_t *game);
int find_dialogue(npc_t *tmp, game_t *game, player_t *player);

/*---------------------------------------------------------------------------*/

void free_sprite(sprite_t *sprite);
void check_hitbox(player_t *player);
void check_hitbox_shop(player_t *player);
void check_hitbox_harbor(player_t *player);
void check_hitbox_tavern(player_t *player);
void check_hitbox_church(player_t *player);
void check_hitbox_houses(player_t *player);
void quest(game_t *game, player_t *player);
void check_hitbox_tower_out(player_t *player);
void move_player(player_t *player, game_t *game);
void create_zoom(game_t *game);
void handle_zoom(game_t *game, player_t *player);
void free_game(game_t *game, player_t *player, sfRenderWindow *window);
void handle_dialogue(game_t *game, player_t *player);
void handle_lvl(player_t *player);
void display_npc(sfRenderWindow *window, game_t *game, player_t *player);
void display_text(sfRenderWindow *window, game_t *game, player_t *player);
void display_game(sfRenderWindow *window, game_t *game, player_t *player);
void display_logo(sfRenderWindow *window, player_t *player, game_t *game);
void display_chat_logo(sfRenderWindow *window, npc_t *tmp, player_t *player);
void mini_map(game_t *game, sfRenderWindow *window, player_t *player);
void display_fireplace(game_t *game, sfRenderWindow *window);
void free_player(player_t *player);
void free_music(music_t *music);

#endif