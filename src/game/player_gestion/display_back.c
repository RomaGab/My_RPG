/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_chose_skin.c
*/

#include "player.h"

static void change_back_rect(skin_t *skin)
{
    skin->skin->time = sfClock_getElapsedTime(skin->skin->clock);
    skin->skin->seconds = sfTime_asMilliseconds(skin->skin->time);

    if (skin->back_rect.left != 5760 && skin->skin->seconds >= 250) {
        skin->back_rect.left += 1920;
        sfClock_restart(skin->skin->clock);
    } else if (skin->skin->seconds >= 250) {
        skin->back_rect.left = 0;
        sfClock_restart(skin->skin->clock);
    }
}

static game_state_t draw_laser_player(sfRenderWindow *window, skin_t *skin,
                                    game_state_t scene)
{
    int i = 0;

    while (skin->vect_laser.x != -1 && skin->laser_rect.left != 736) {
        skin->laser->time = sfClock_getElapsedTime(skin->laser->clock);
        skin->laser->seconds = sfTime_asMilliseconds(skin->laser->time);
        change_back_rect(skin);
        sfRenderWindow_clear(window, sfBlack);
        move_parallax_skin(skin, window);
        sfSprite_setTextureRect(skin->back->spr, skin->back_rect);
        sfSprite_setPosition(skin->sprite_laser->spr, skin->vect_laser);
        sfSprite_setTextureRect(skin->sprite_laser->spr, skin->laser_rect);
        sfRenderWindow_drawSprite(window, skin->sprite_laser->spr, NULL);
        sfRenderWindow_display(window);
        if (skin->laser_rect.left != 736 && skin->laser->seconds >= 50) {
            skin->laser_rect.left += 184;
            sfClock_restart(skin->laser->clock);
        } i += 1;
    } if (i != 0)
        return rm_draw_laser(window, scene, skin);
    return scene;
}

game_state_t display_player_back(sfRenderWindow *window, skin_t *skin,
                                game_state_t scene)
{
    if (scene == StateError)
        return StateError;
    change_back_rect(skin);
    sfRenderWindow_clear(window, sfBlack);
    sfSprite_setTextureRect(skin->back->spr, skin->back_rect);
    move_parallax_skin(skin, window);
    scene = draw_laser_player(window, skin, scene);
    if (scene == StateGame)
        return scene;
    sfRenderWindow_display(window);
    return scene;
}

static void draw_laser_class(sfRenderWindow *window, class_t *class)
{
    while (class->vect_laser.x != -1 && class->laser_rect.left != 736) {
        class->clock->time = sfClock_getElapsedTime(class->clock->clock);
        class->clock->seconds = sfTime_asMilliseconds(class->clock->time);
        sfRenderWindow_clear(window, sfBlack);
        move_parallax_class(class, window);
        sfSprite_setPosition(class->sprite_laser->spr, class->vect_laser);
        sfSprite_setTextureRect(class->sprite_laser->spr, class->laser_rect);
        sfRenderWindow_drawSprite(window, class->sprite_laser->spr, NULL);
        sfRenderWindow_display(window);
        if (class->laser_rect.left != 736 && class->clock->seconds >= 50) {
            class->laser_rect.left += 184;
            sfClock_restart(class->clock->clock);
        }
        if (class->laser_rect.left == 736)
            display_transition(window, class);
    }
}

void display_back_class(sfRenderWindow *window, class_t *class)
{
    sfRenderWindow_clear(window, sfBlack);
    move_parallax_class(class, window);
    draw_laser_class(window, class);
    sfRenderWindow_display(window);
}