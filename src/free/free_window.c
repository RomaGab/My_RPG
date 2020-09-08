/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** free_window.c
*/

#include "rpg.h"

void free_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
    sfRenderWindow_destroy(window);
}