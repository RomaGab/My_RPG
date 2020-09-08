/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** create_menu.c
*/

#include "menu.h"

static butt_t *diff_button(butt_t *butt, int i)
{
    char *path[] = {"res/button/Start_B.png", "res/button/Score_B.png",
                    "res/button/Help_B.png", "res/button/Exit_B.png"};
    game_state_t ret[] = {StateGame, StateHighscore, StateHowtoplay, StateOver};

    butt[i].texture = sfTexture_createFromFile(path[i], NULL);
    if (!butt[i].texture)
        return (NULL);
    butt[i].sprite = sfSprite_create();
    if (!butt[i].sprite)
        return (NULL);
    butt[i].ret = ret[i];
    return (butt);
}

static butt_t *create_menubutt(void)
{
    int i = 0;
    butt_t *butt = malloc(sizeof(butt_t) * 4);
    sfIntRect rect = {0, 0, 276, 70};
    sfVector2f vect = {810, 520};

    if (!butt)
        return (NULL);
    for (i = 0; i <= 3; i += 1) {
        butt = diff_button(butt, i);
        butt[i].rect = rect;
        butt[i].vect = vect;
        butt[i].vect.y += 130 * i;
    }
    return (butt);
}

static int create_more(menu_t *menu)
{
    menu->parallax1 = fill_sprite("res/back/parallax_1.png");
    menu->parallax2 = fill_sprite("res/back/parallax_2.png");
    menu->parallax3 = fill_sprite("res/back/parallax_3.png");
    if (!menu->parallax1 || !menu->parallax2 || !menu->parallax3)
        return 84;
    menu->pos1 = (sfVector2f){0, 0};
    menu->pos2 = (sfVector2f){0, 0};
    menu->pos3 = (sfVector2f){0, 0};
    menu->fps = 1;
    return 0;
}

menu_t *create_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    if (!menu)
        return (NULL);
    menu->back_text = sfTexture_createFromFile("res/back/menu.png", NULL);
    menu->back_sprite = sfSprite_create();
    menu->music = sfMusic_createFromFile("res/audio/menu_theme.ogg");
    menu->clock = fill_time();
    if (!menu->back_text || !menu->back_sprite || !menu->music || !menu->clock)
        return (NULL);
    menu->button = create_menubutt();
    if (!menu->button || create_more(menu) == 84)
        return (NULL);
    menu->fps_button = fill_sprite("res/button/Frame_B.png");
    if (!menu->fps_button)
        return (NULL);
    sfMusic_setVolume(menu->music, 25);
    sfMusic_setLoop(menu->music, sfTrue);
    sfMusic_play(menu->music);
    return (menu);
}