/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** display_menu.c
*/

#include "menu.h"

static void display_menubutt(sfRenderWindow *window, butt_t *button)
{
    int i = 0;

    for (i = 0; i <= 3; i += 1) {
        sfSprite_setTexture(button[i].sprite, button[i].texture, sfTrue);
        sfSprite_setTextureRect(button[i].sprite, button[i].rect);
        sfSprite_setPosition(button[i].sprite, button[i].vect);
        sfRenderWindow_drawSprite(window, button[i].sprite, NULL);
    }
}

static void display_framebutt(sfRenderWindow *window, menu_t *menu)
{
    sfIntRect rect = {0, 70 * (2 - menu->fps), 120, 70};

    sfSprite_setTextureRect(menu->fps_button->spr, rect);
    sfSprite_setPosition(menu->fps_button->spr, (sfVector2f){1750, 50});
    sfRenderWindow_drawSprite(window, menu->fps_button->spr, NULL);
}

static void move_parallax_menu(menu_t *menu)
{
    menu->clock->time = sfClock_getElapsedTime(menu->clock->clock);
    menu->clock->seconds = sfTime_asMilliseconds(menu->clock->time);
    if (menu->pos1.x >= -1920)
        menu->pos1.x -= 0.125 * menu->clock->seconds;
    else
        menu->pos1.x = 0;
    if (menu->pos2.x >= -1920)
        menu->pos2.x -= 0.184375 * menu->clock->seconds;
    else
        menu->pos2.x = 0;
    if (menu->pos3.x >= -1920)
        menu->pos3.x -= 0.140625 * menu->clock->seconds;
    else
        menu->pos3.x = 0;
    sfSprite_setPosition(menu->parallax1->spr, menu->pos1);
    sfSprite_setPosition(menu->parallax2->spr, menu->pos2);
    sfSprite_setPosition(menu->parallax3->spr, menu->pos3);
    sfClock_restart(menu->clock->clock);
}

void display_menu(sfRenderWindow *window, menu_t *menu)
{
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTexture(menu->back_sprite, menu->back_text, sfTrue);
    move_parallax_menu(menu);
    sfRenderWindow_drawSprite(window, menu->parallax1->spr, NULL);
    sfRenderWindow_drawSprite(window, menu->parallax3->spr, NULL);
    sfRenderWindow_drawSprite(window, menu->parallax2->spr, NULL);
    sfRenderWindow_drawSprite(window, menu->back_sprite, NULL);
    display_menubutt(window, menu->button);
    display_framebutt(window, menu);
    sfRenderWindow_display(window);
}