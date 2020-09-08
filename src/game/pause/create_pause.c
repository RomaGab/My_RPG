/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** create_pause.c
*/

#include "pause.h"

static butt_t *diff_pausebutton(butt_t *butt, int i, player_t *player)
{
    char *path[] = {"res/button/Resume_B.png", "res/button/Menu_B.png",
                    "res/button/Exit_B.png"};
    game_state_t ret[] = {StateGame, StateMenu, StateOver};

    butt[i].texture = sfTexture_createFromFile(path[i], NULL);
    if (!butt[i].texture)
        return (NULL);
    butt[i].sprite = sfSprite_create();
    if (!butt[i].sprite)
        return (NULL);
    if (player->pos.y <= -365 && player->pos.x <= -710)
        ret[0] = StateTower;
    else if (player->pos.y <= 99)
        ret[0] = StateCave;
    else
        ret[0] = StateGame;
    butt[i].ret = ret[i];
    return (butt);
}

static butt_t *create_pausebutt(player_t *player)
{
    int i = 0;
    butt_t *butt = malloc(sizeof(butt_t) * 4);
    sfIntRect rect = {0, 0, 276, 70};
    sfVector2f vect = {810, 520};

    if (!butt)
        return (NULL);
    for (i = 0; i <= 2; i += 1) {
        butt = diff_pausebutton(butt, i, player);
        butt[i].rect = rect;
        butt[i].vect = vect;
        butt[i].vect.y += 130 * i;
    }
    return (butt);
}

pause_t *create_pause(player_t *player)
{
    pause_t *pause = malloc(sizeof(pause_t));

    if (!pause || !player)
        return (NULL);
    pause->texture = sfTexture_createFromFile("res/back/pause.png", NULL);
    pause->sprite = sfSprite_create();
    pause->back_sprite = fill_sprite("res/back/pause_back.png");
    pause->button = create_pausebutt(player);
    if (!pause->texture || !pause->sprite || !pause->back_sprite
    || !pause->button)
        return (NULL);
    return (pause);
}