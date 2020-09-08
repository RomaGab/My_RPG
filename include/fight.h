    /*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** fight.h
*/

#ifndef FIGHT_H
#define FIGHT_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Fight*/

typedef struct fight_s
{
    sprite_t *life_bar_one;
    sprite_t *life_bar_two;
    sprite_t *champ;
    sprite_t *win;
    sprite_t *boss;
    sprite_t *text;
    sprite_t *cadre;
    sprite_t *lose;
    sprite_t *psn_icn;
    sprite_t *psn_swd;
    sprite_t *boost_spr;
    sprite_t *dfs_spr;
    sprite_t *boss_anim;
    sprite_t *play_anim;
    sfVector2f lose_pos;
    sfVector2f win_pos;
    sfIntRect rect_boss;
    sfIntRect rect_champ;
    sfIntRect rect_life_one;
    sfIntRect rect_life_two;
    sfClock *clock_button;
    sfClock *clock_rect;
    sfClock *clock_lose;
    sfText *item_name;
    sfText *text_action;
    sfRectangleShape *item_selec;
    int inventory;
    int item_index;
    int hp_boss;
    int hp_max_boss;
    int turn;
    int choice;
    int boss_choice;
    int defense;
    int defense_boss;
    int att_boss;
    int attack_turn;
    int boost;
    bool poison_boss;
    bool poison_player;
    bool poison_sword;
} fight_t;

/*---------------------------------------------------------------------------*/

game_state_t gest_pause(sfRenderWindow *window, game_t *game, sfEvent *event,
                        player_t *player);

game_state_t analyse_eventfight(sfRenderWindow *window, game_t *game,
                                sfEvent *event, player_t *player);

game_state_t create_fight(game_t *game, fight_t *fight,
                                player_t *player);

/*---------------------------------------------------------------------------*/

sprite_t *fill_sprite(char *str);

/*---------------------------------------------------------------------------*/

clocks_t *fill_time(void);

/*---------------------------------------------------------------------------*/

item_t remove_item(item_t item);

/*---------------------------------------------------------------------------*/

char *int_str(int nbr);

/*---------------------------------------------------------------------------*/

int fill_fight(fight_t *fight, player_t *player);
int verif_item_inv(item_t *item);

/*---------------------------------------------------------------------------*/

void free_sprite(sprite_t *sprite);
void hp_bar(player_t *player, fight_t *fight);
void fight_rounds(game_t *game, player_t *player, fight_t *fight);
void display_fight(sfRenderWindow *window, game_t *game, fight_t *fight,
                    player_t *player);
void display_item_fight(sfRenderWindow *window, fight_t *fight,
                        player_t *player, sfClock *clock);
void display_icone_state(sfRenderWindow *window, fight_t *fight);
void display_boss_animation(sfRenderWindow *window, fight_t *fight);
void display_player_animation(sfRenderWindow *window, fight_t *fight);
void display_name(sfRenderWindow *window, fight_t *fight, player_t *player);
void attack_turn(sfRenderWindow *window, fight_t *fight, player_t *player);
void free_fight(fight_t *fight);
void display_win(fight_t *fight, sfInt64 time, sfRenderWindow *window);
void redirect_item(fight_t *fight, player_t *player);
int new_score(game_t *game, fight_t *fight);
char *get_next_line(int fd);
int my_getnbr(char const *str);
int my_strlen(char const *str);

static void use_potion(fight_t *fight, player_t *player);
static void use_poison(fight_t *fight, player_t *player);
static void use_shroom(fight_t *fight, player_t *player);
static void use_doume(fight_t *fight, player_t *player);

#endif