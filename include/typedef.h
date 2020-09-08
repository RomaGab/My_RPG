/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** typedef.h
*/

#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdbool.h>

/*===========================================================================*/
/*Typedef*/

typedef struct npc_s npc_t;
typedef struct butt_s butt_t;
typedef struct menu_s menu_t;
typedef struct game_s game_t;
typedef struct skin_s skin_t;
typedef struct item_s item_t;
typedef struct cave_s cave_t;
typedef struct shop_s shop_t;
typedef struct pause_s pause_t;
typedef struct class_s class_t;
typedef struct scene_s scene_t;
typedef struct clocks_s clocks_t;
typedef struct launch_s launch_t;
typedef struct sprite_s sprite_t;
typedef struct player_s player_t;
typedef struct howtoplay_s howtoplay_t;
typedef struct inventory_s inventory_t;
typedef struct inventory_ui_s inventory_ui_t;
typedef struct fireplace_s fireplace_t;
typedef struct music_s music_t;
typedef struct item_info_s item_info_t;
typedef struct fight_s fight_t;
typedef struct highscore_s highscore_t;

typedef enum id_item_e id_item_t;
typedef enum npc_state_e npc_state_t;
typedef enum game_states_e game_state_t;
typedef enum class_chose_e class_chose_t;
typedef enum player_chose_e player_chose_t;

typedef void (*item_usage_t)(fight_t *, player_t *);

/*---------------------------------------------------------------------------*/

enum game_states_e
{
    StateLoad = 0,
    StateMenu = 1,
    StateGame = 2,
    StatePlayer = 3,
    StatePause = 4,
    StateHighscore = 5,
    StateHowtoplay = 6,
    StateGameOver = 7,
    StateInventory = 8,
    StateCave = 9,
    StateTower = 10,
    StateShop = 11,
    StateFight = 12,
    StateOver = -1,
    StateError = 84
};

/*---------------------------------------------------------------------------*/

enum player_chose_e
{
    NO_PLAYER,
    ALYSSA,
    LUCAS,
    DENIS,
    CECILE
};

/*---------------------------------------------------------------------------*/

enum class_chose_e
{
    NO_CLASS,
    THIEF,
    BARBARIAN,
    MAGE
};

/*---------------------------------------------------------------------------*/

enum npc_state_e
{
    no_quest,
    quest_never,
    quest_inprogress,
    quest_finish
};

/*---------------------------------------------------------------------------*/

enum id_item_e
{
    Empty,
    Potion_Heal,
    Poison_Vial,
    Suspisious_Shroom,
    Gantlet
};

/*---------------------------------------------------------------------------*/

struct sprite_s
{
    sfSprite *spr;
    sfTexture *text;
};

/*---------------------------------------------------------------------------*/

struct clocks_s
{
    sfTime time;
    float seconds;
    sfClock *clock;
};


/*---------------------------------------------------------------------------*/

struct music_s
{
    sfMusic *music_tower;
    sfMusic *music_city;
    sfMusic *music_cave;
    sfMusic *music_boss;
    sfSound *sound_state;
    sfSound *sound_dialogue;
    sfSound *sound_teleportation;
    sfSoundBuffer *buf_state;
    sfSoundBuffer *buf_dial;
    sfSoundBuffer *buf_tele;
};

/*---------------------------------------------------------------------------*/

struct skin_s
{
    sprite_t *back;
    sprite_t *parallax1;
    sprite_t *parallax2;
    sprite_t *parallax3;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;
    sfIntRect back_rect;
    sprite_t *sprite_laser;
    sfIntRect laser_rect;
    sfVector2f vect_laser;
    clocks_t *laser;
    clocks_t *skin;
    clocks_t *clock_par;
};

/*---------------------------------------------------------------------------*/

struct class_s
{
    sprite_t *back;
    sprite_t *sprite_laser;
    sprite_t *transition;
    sprite_t *parallax1;
    sprite_t *parallax2;
    sprite_t *parallax3;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f pos3;
    sfIntRect rect_transition;
    sfIntRect laser_rect;
    sfVector2f vect_laser;
    clocks_t *clock;
    clocks_t *clock_par;
};

/*---------------------------------------------------------------------------*/

struct npc_s
{
    sprite_t *sprite;
    sfIntRect rect;
    sprite_t *sprite_chat;
    int length_rect;
    int nb_step;
    char **dialogue;
    sfVector2f pos;
    npc_state_t state_quest;
    clocks_t *move;
    clocks_t *clock_npc;
    int where;
    int nb_quest;
    int max_quest;
    int nb_npc;
    bool devil;
    bool conversation;
    struct npc_s *next;
};

/*---------------------------------------------------------------------------*/

struct item_s
{
    id_item_t id;
    sprite_t *sprite;
    int quantity;
    bool error;
};

/*---------------------------------------------------------------------------*/

struct inventory_s
{
    item_t *item;
    int hand_index;
};

/*---------------------------------------------------------------------------*/

struct player_s
{
    bool over;
    sprite_t *player_spr;
    sprite_t *char_logo;
    sprite_t *class_logo;
    sfIntRect rect_char;
    sfIntRect rect_class;
    sfVector2f pos;
    sfIntRect rect;
    int hp;
    int hp_max;
    int strength;
    int gold;
    int xp;
    int lvl;
    int armor;
    int check;
    sfText *text_hp;
    sfText *text_strength;
    sfText *text_lvl;
    sfText *text_gold;
    clocks_t *clock;
    clocks_t *clock_move;
    sfVector2f pos_arrow;
    inventory_t *inventory;
    class_chose_t class;
    player_chose_t character;
};

/*---------------------------------------------------------------------------*/

struct fireplace_s
{
    sprite_t *smoke;
    sprite_t *red_particule;
    sprite_t *blue_particule;
    clocks_t *clock;
    sfIntRect rect_smoke;
    sfIntRect rect_red;
    sfIntRect rect_blue;
    sfVector2f pos;
    bool verif;
    struct fireplace_s *next;
};

/*---------------------------------------------------------------------------*/

struct game_s
{
    sfTexture *back_text;
    sfSprite *back_sprite;
    sprite_t *xp_cadre;
    sprite_t *xp;
    sprite_t *arrow;
    sfIntRect rect_back;
    clocks_t *back;
    clocks_t *time;
    sprite_t *transition;
    sfView *view;
    struct music_s *music;
    clocks_t *zoom;
    float zoom_x;
    float zoom_y;
    bool first_zoom;
    sfFont *font;
    sfText *text;
    sprite_t *mini_map;
    char *str;
    npc_t *npc;
    sprite_t *bubble;
    sprite_t *box;
    sfVector2f pos_box;
    sfVector2f pos_xp;
    sfIntRect rect;
    fireplace_t *fire_place;
    bool verif_e;
    bool verif_tel;
    bool verif_back_tel;
    bool verif_int;
    bool verif_gantlet;
    bool idx_gantlet;
    bool verif_zoom;
    int quest_id;
};

/*---------------------------------------------------------------------------*/

struct butt_s
{
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f vect;
    game_state_t ret;
};

/*---------------------------------------------------------------------------*/

struct item_info_s
{
    char name[20];
    char price[5];
};

#endif