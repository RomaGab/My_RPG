/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** chose_class.c
*/

#include "player.h"

static void chose_class(float click_x, float click_y, player_t *player,
                        class_t *class)
{
    player->class = NO_CLASS;
    if (click_x > 724 && click_x < 761 && click_y > 720 && click_y < 760) {
        player->rect_class = (sfIntRect){19, 24, 68, 21};
        player->class = THIEF;
        class->vect_laser.x = 653;
    } if (click_x > 943 && click_x < 979 && click_y > 720 && click_y < 760) {
        player->rect_class = (sfIntRect){11, 48, 86, 34};
        player->class = BARBARIAN;
        class->vect_laser.x = 872;
    } if (click_x > 1162 && click_x < 1198 && click_y > 720 && click_y < 760) {
        player->rect_class = (sfIntRect){0, 0, 108, 21};
        player->class = MAGE;
        class->vect_laser.x = 1090;
    }
}

static game_state_t analyse_eventclass(sfRenderWindow *window, sfEvent *event,
                                    player_t *player, class_t *class)
{
    game_state_t scene = StatePlayer;

    if (event->type == sfEvtClosed || event->key.code == sfKeyEscape) {
        player->over = true;
        return StateOver;
    }
    if (event->type == sfEvtMouseButtonPressed) {
        chose_class(event->mouseButton.x, event->mouseButton.y, player,
                    class);
        if (player->class != NO_CLASS)
            scene = StateGame;
    }
    return scene;
}

static int create_parallax_class(class_t *class)
{
    class->parallax1 = fill_sprite("res/back/parallax_1.png");
    class->parallax2 = fill_sprite("res/back/parallax_2.png");
    class->parallax3 = fill_sprite("res/back/parallax_3.png");
    if (!class->parallax1 || !class->parallax2 || !class->parallax3)
        return 84;
    class->pos1 = (sfVector2f){0, 0};
    class->pos2 = (sfVector2f){0, 0};
    class->pos3 = (sfVector2f){0, 0};
    return 0;
}

static class_t *init_class(void)
{
    class_t *class = malloc(sizeof(class_t));

    if (!class)
        return NULL;
    class->back = fill_sprite("res/back/class.png");
    class->sprite_laser = fill_sprite("res/sprite/laser.png");
    class->transition = fill_sprite("res/sprite/transition.png");
    class->rect_transition = (sfIntRect){0, 0, 1920, 1080};
    class->laser_rect = (sfIntRect){0, 0, 184, 1080};
    class->vect_laser = (sfVector2f){-1, 0};
    class->clock = fill_time();
    class->clock_par = fill_time();
    if (!class->back || !class->sprite_laser || !class->clock ||
    !class->transition || !class->clock_par ||
    create_parallax_class(class) == 84)
        return NULL;
    return class;
}

game_state_t gest_class(player_t *player, sfRenderWindow *window,
                        sfEvent *event)
{
    game_state_t scene = StatePlayer;
    class_t *class = init_class();
    player->class_logo = fill_sprite("res/sprite/class_logo.png");

    if (!player->class_logo || !class)
        return StateError;
    while (scene == StatePlayer) {
        while (sfRenderWindow_pollEvent(window, event))
            scene = analyse_eventclass(window, event, player, class);
        display_back_class(window, class);
    }
    free_class(class);
    return scene;
}