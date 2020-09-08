/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** display_game.c
*/

#include "pause.h"

static void display_pausemenu(sfRenderWindow *window, pause_t *pause,
                                player_t *player)
{
    int i = 0;
    butt_t *button = pause->button;
    sfIntRect rect = {0, 0, 1920, 1080};

    if (player->pos.y <= -365 && player->pos.x <= -710)
        rect.left = 1920;
    else if (player->pos.y <= 99)
        rect.left = 3840;
    sfSprite_setTextureRect(pause->back_sprite->spr, rect);
    sfRenderWindow_drawSprite(window, pause->back_sprite->spr, NULL);
    sfSprite_setTexture(pause->sprite, pause->texture, sfTrue);
    sfRenderWindow_drawSprite(window, pause->sprite, NULL);
    for (i = 0; i <= 2; i += 1) {
        sfSprite_setTexture(button[i].sprite, button[i].texture, sfTrue);
        sfSprite_setTextureRect(button[i].sprite, button[i].rect);
        sfSprite_setPosition(button[i].sprite, button[i].vect);
        sfRenderWindow_drawSprite(window, button[i].sprite, NULL);
    }
}

void display_pause(sfRenderWindow *window, game_t *game, pause_t *pause,
                    player_t *player)
{
    sfRenderWindow_clear(window, sfBlack);
    sfView_setSize(game->view, (sfVector2f){game->zoom_x, game->zoom_y});
    sfView_setCenter(game->view, (sfVector2f){960, 540});
    sfRenderWindow_setView(window, game->view);
    display_pausemenu(window, pause, player);
    sfRenderWindow_display(window);
}