/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_menu.c
*/

#include "menu.h"

void free_menu(menu_t *menu)
{
    int i = 0;

    free_sprite(menu->parallax1);
    free_sprite(menu->parallax2);
    free_sprite(menu->parallax3);
    free_sprite(menu->fps_button);
    for (i = 0; i <= 1; i += 1) {
        sfSprite_destroy(menu->button[i].sprite);
        sfTexture_destroy(menu->button[i].texture);
    }
    sfMusic_destroy(menu->music);
    sfClock_destroy(menu->clock->clock);
    free(menu->clock);
    free(menu->button);
    free(menu);
}