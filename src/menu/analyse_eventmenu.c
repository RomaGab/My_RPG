/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** analyse_eventmenu.c
*/

#include "menu.h"

game_state_t button_event(sfRenderWindow *window, menu_t *menu,
                            sfEvent *event)
{
    int i = 0;
    int m = 0;
    sfVector2f pos;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (event->type == sfEvtMouseButtonPressed)
        m = 1;
    for (i = 0; i <= 3; i += 1) {
        pos = menu->button[i].vect;
        if (mouse.x >= pos.x && mouse.x <= pos.x + 276
            && mouse.y >= pos.y && mouse.y <= pos.y + 70 && m == 1) {
            menu->button[i].rect.top = 140;
            return (menu->button[i].ret);
        } else if (mouse.x >= pos.x && mouse.x <= pos.x + 276
            && mouse.y >= pos.y && mouse.y <= pos.y + 70) {
            menu->button[i].rect.top = 70;
        } else
            menu->button[i].rect.top = 0;
    }
    return (StateMenu);
}

game_state_t analyse_framerate_button(sfRenderWindow *window, menu_t *menu,
                                        sfEvent *event)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (!window || !menu || !event)
        return (StateError);
    if (event->type == sfEvtMouseButtonPressed
        && mouse.x >= 1750 && mouse.x <= 1870
        && mouse.y >= 50 && mouse.y <= 120) {
        menu->fps = (menu->fps + 1) % 3;
        sfRenderWindow_setFramerateLimit(window, 30 + 30 * menu->fps);
    }
}

game_state_t analyse_eventmenu(sfRenderWindow *window, menu_t *menu,
                                sfEvent *event)
{
    game_state_t scene = StateMenu;

    if (analyse_framerate_button(window, menu, event) == StateError)
        return (StateError);
    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape) {
        return (StateOver);
    } else {
        scene = button_event(window, menu, event);
        if (scene == StateHighscore)
            scene = gest_highscore(window, event);
        else if (scene == StateHowtoplay)
            scene = gest_howtoplay(window, event);
        return (scene);
    }
}