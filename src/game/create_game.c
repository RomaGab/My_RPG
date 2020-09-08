/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** create_game.c
*/

#include "game.h"

const float pos_fire[] = {
    1208.2, 465.8, 1441, 465.8, 1208.2, 336, 1441, 336, 1208.2, 231.6, 1441,
    231.6, 1388.2, 136.2, 1388.2, 41.2, 1717.3, 465.9, 1864.8, 465.9, 1717.3,
    331.5, 1864.8, 331.5, 1717.3, 205.7, 1864.8, 205.7, 1713.3, 79.9, 1864.8,
    79.9
};

static int create_malloc(game_t *game)
{
    game->back_text = sfTexture_createFromFile("res/back/map.png", NULL);
    game->bubble = fill_sprite("res/sprite/bubble.png");
    game->back_sprite = sfSprite_create();
    game->music = fill_music();
    game->transition = fill_sprite("res/sprite/transition.png");
    game->view = sfView_create();
    game->zoom = fill_time();
    game->back = fill_time();
    game->time = fill_time();
    game->font = sfFont_createFromFile("res/text/font.ttf");
    game->text = sfText_create();
    game->mini_map = fill_sprite("res/back/minimap.png");
    game->arrow = fill_sprite("res/sprite/arrow.png");
    game->box = fill_sprite("res/sprite/box.png");
    if (!game->back_text || !game->bubble || !game->back_sprite ||
    !game->music || !game->transition || !game->view || !game->mini_map
    || !game->zoom || !game->zoom || !game->font || !game->text
    || !game->arrow || !game->box || !game->time)
        return (84);
    return 0;
}

static void create_other_two(game_t *game)
{
    game->rect = (sfIntRect){0, 0, 442, 369};
    game->pos_box = (sfVector2f){-205, -330};
    game->rect_back = (sfIntRect){0, 0, 3840, 2160};
    game->npc = NULL;
    game->fire_place = NULL;
    game->str = NULL;
    game->quest_id = 0;
    game->verif_e = false;
    game->verif_back_tel = false;
    game->verif_tel = false;
    game->verif_int = false;
    game->idx_gantlet = false;
    game->verif_gantlet = false;
    game->verif_zoom = false;
}

static int create_other(game_t *game)
{
    game->xp = fill_sprite("res/sprite/xp_bar.png");
    game->xp_cadre = fill_sprite("res/sprite/xp_bar_cadre.png");
    if (!game->xp || !game->xp_cadre || create_malloc(game) == 84)
        return 84;
    game->pos_xp = (sfVector2f){0, 0};
    sfSprite_setScale(game->bubble->spr, (sfVector2f){1.20, 1});
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 16);
    sfText_setFillColor(game->text, sfBlack);
    sfSprite_setOrigin(game->back_sprite, (sfVector2f){960, 540});
    sfSprite_setRotation(game->arrow->spr, (float)180);
    create_zoom(game);
    sfMusic_play(game->music->music_city);
    sfMusic_setVolume(game->music->music_city, 30);
    sfMusic_setLoop(game->music->music_city, sfTrue);
    create_other_two(game);
    return 0;
}

static fireplace_t *create_fireplace(fireplace_t *fireplace, int i)
{
    fireplace_t *tmp = malloc(sizeof(fireplace_t));

    if (!tmp)
        return NULL;
    tmp->smoke = fill_sprite("res/sprite/smoke.png");
    tmp->red_particule = fill_sprite("res/sprite/particule_1.png");
    tmp->blue_particule = fill_sprite("res/sprite/particule_2.png");
    tmp->clock = fill_time();
    if (!tmp->smoke || !tmp->red_particule || !tmp->blue_particule
    || !tmp->clock)
        return NULL;
    tmp->rect_smoke = (sfIntRect){0, 0, 60, 60};
    tmp->rect_red = (sfIntRect){0, 0, 60, 60};
    tmp->rect_blue = (sfIntRect){0, 0, 60, 60};
    tmp->verif = false;
    tmp->pos = (sfVector2f){pos_fire[i * 2], pos_fire[i * 2 + 1]};
    sfSprite_setPosition(tmp->smoke->spr, tmp->pos);
    sfSprite_setPosition(tmp->red_particule->spr, tmp->pos);
    sfSprite_setPosition(tmp->blue_particule->spr, tmp->pos);
    tmp->next = fireplace;
    return tmp;
}

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game || create_other(game) == 84)
        return (NULL);
    for (int i = 0; i < 4; i++) {
        game->npc = create_npc(game->npc, i);
        if (!game->npc)
            return NULL;
    }
    for (int i = 0; i < 16; i++) {
        game->fire_place = create_fireplace(game->fire_place, i);
        if (!game->fire_place)
            return NULL;
    }
    return (game);
}