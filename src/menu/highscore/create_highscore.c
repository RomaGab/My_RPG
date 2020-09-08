/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** create_menu.c
*/

#include "highscore.h"

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

static butt_t *create_highbutt(void)
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

static int create_back(highscore_t *high)
{
    high->parallax1 = fill_sprite("res/back/parallax_1.png");
    high->parallax2 = fill_sprite("res/back/parallax_2.png");
    high->parallax3 = fill_sprite("res/back/parallax_3.png");
    if (!high->parallax1 || !high->parallax2 || !high->parallax3)
        return 84;
    high->pos1 = (sfVector2f){0, 0};
    high->pos2 = (sfVector2f){0, 0};
    high->pos3 = (sfVector2f){0, 0};
    return 0;
}

static int create_malloc_high(highscore_t *high)
{
    high->back_text = sfTexture_createFromFile("res/back/scores.png", NULL);
    high->back_sprite = sfSprite_create();
    high->clock = fill_time();
    high->font = sfFont_createFromFile("res/text/font.ttf");
    high->text_highscore = sfText_create();
    high->text_lastscore = sfText_create();
    if (!high->back_text || !high->back_sprite || !high->clock ||
    !high->text_highscore || !high->text_lastscore)
        return 84;
    return 0;
}

highscore_t *create_highscore(void)
{
    highscore_t *high = malloc(sizeof(highscore_t));

    if (!high)
        return (NULL);
    if (create_malloc_high(high) == 84 || create_back(high) == 84)
        return (NULL);
    high->button = create_highbutt();
    if (!high->button)
        return (NULL);
    sfSprite_setTexture(high->back_sprite, high->back_text, sfTrue);
    sfSprite_setPosition(high->back_sprite, (sfVector2f){749, 238});
    sfText_setFont(high->text_lastscore, high->font);
    sfText_setFont(high->text_highscore, high->font);
    sfText_setPosition(high->text_highscore, (sfVector2f){870, 550});
    sfText_setPosition(high->text_lastscore, (sfVector2f){870, 425});
    sfText_setCharacterSize(high->text_lastscore, 30);
    sfText_setCharacterSize(high->text_highscore, 30);
    return (high);
}