/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** create_menu.c
*/

#include "howtoplay.h"

static butt_t *diff_helpbutton(butt_t *butt)
{
    butt->texture = sfTexture_createFromFile("res/button/Menu_B.png", NULL);
    if (!butt->texture)
        return (NULL);
    butt->sprite = sfSprite_create();
    if (!butt->sprite)
        return (NULL);
    butt->ret = StateMenu;
    return (butt);
}

static butt_t *create_helpbutt(void)
{
    butt_t *butt = malloc(sizeof(butt_t));
    sfIntRect rect = {0, 0, 276, 70};
    sfVector2f vect = {810, 850};

    if (!butt)
        return (NULL);
    butt = diff_helpbutton(butt);
    butt->rect = rect;
    butt->vect = vect;
    return (butt);
}

static int create_back(howtoplay_t *help)
{
    help->parallax1 = fill_sprite("res/back/parallax_1.png");
    help->parallax2 = fill_sprite("res/back/parallax_2.png");
    help->parallax3 = fill_sprite("res/back/parallax_3.png");
    if (!help->parallax1 || !help->parallax2 || !help->parallax3)
        return 84;
    help->pos1 = (sfVector2f){0, 0};
    help->pos2 = (sfVector2f){0, 0};
    help->pos3 = (sfVector2f){0, 0};
    return 0;
}

howtoplay_t *create_help(void)
{
    howtoplay_t *help = malloc(sizeof(howtoplay_t));

    if (!help) {
        return (NULL);
    }
    help->back_text = sfTexture_createFromFile("res/back/h2p.png", NULL);
    help->back_sprite = sfSprite_create();
    help->clock = fill_time();
    if (!help->back_text || !help->back_sprite || !help->clock ||
    create_back(help) == 84) {
        return (NULL);
    }
    help->button = create_helpbutt();
    if (!help->button) {
        return (NULL);
    }
    sfSprite_setTexture(help->back_sprite, help->back_text, sfTrue);
    sfSprite_setPosition(help->back_sprite, (sfVector2f){438, 239});
    sfSprite_setTextureRect(help->back_sprite, (sfIntRect){0, 0, 1046, 544});
    return (help);
}