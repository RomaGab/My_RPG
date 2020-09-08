/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gest_menu.c
*/

#include "menu.h"

game_state_t gest_menu(sfRenderWindow *window, sfEvent event)
{
    menu_t *menu = NULL;
    game_state_t scene = StateMenu;

    if (!window)
        return (StateError);
    menu = create_menu();
    if (!menu)
        return (StateError);
    while (scene == StateMenu) {
        display_menu(window, menu);
        while (sfRenderWindow_pollEvent(window, &event)) {
            scene = analyse_eventmenu(window, menu, &event);
            if (scene == StateError)
                return StateError;
        }
    }
    free_menu(menu);
    return (scene);
}