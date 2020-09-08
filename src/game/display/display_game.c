/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** display_game.c
*/

#include "game.h"

void draw_xp_bar(sfRenderWindow *window, game_t *game, player_t *player)
{
    int idx = player->xp * 1557 / (5 * 25);

    game->pos_xp.x = player->pos.x - 570;
    game->pos_xp.y = player->pos.y - 306;
    sfSprite_setTextureRect(game->xp->spr, (sfIntRect){0, 0, idx, 28});
    sfSprite_setPosition(game->xp->spr, game->pos_xp);
    sfSprite_setPosition(game->xp_cadre->spr, game->pos_xp);
    sfSprite_setScale(game->xp_cadre->spr, (sfVector2f){0.7725, 0.7725});
    sfSprite_setScale(game->xp->spr, (sfVector2f){0.7725, 0.7725});
    if (game->zoom_x == 1200) {
        sfRenderWindow_drawSprite(window, game->xp->spr, NULL);
        sfRenderWindow_drawSprite(window, game->xp_cadre->spr, NULL);
    }
}

static void display_end_transition(sfRenderWindow *window, game_t *game)
{
    static bool verif_transition = false;

    if (verif_transition == false) {
        sfSprite_setTextureRect(game->transition->spr,
        (sfIntRect){9600, 0, 1920, 1080});
        sfRenderWindow_drawSprite(window, game->transition->spr, NULL);
        verif_transition = true;
    }
}

static void display_back(sfRenderWindow *window, game_t *game)
{
    static bool verif = false;

    game->back->time = sfClock_getElapsedTime(game->back->clock);
    game->back->seconds = sfTime_asMilliseconds(game->back->time);
    if (game->rect_back.left != 0 && game->back->seconds >= 250
    && verif == true) {
        game->rect_back.left -= 3840;
        sfClock_restart(game->back->clock);
    } if (verif == true && game->rect_back.left == 0)
        verif = false;
    else if (game->rect_back.left != 7680 && game->back->seconds >= 250
    && verif == false) {
        game->rect_back.left += 3840;
        sfClock_restart(game->back->clock);
    } if (game->rect_back.left == 7680)
        verif = true;
    sfRenderWindow_setView(window, game->view);
    sfSprite_setTexture(game->back_sprite, game->back_text, sfTrue);
    sfSprite_setTextureRect(game->back_sprite, game->rect_back);
    sfRenderWindow_drawSprite(window, game->back_sprite, NULL);
}

void display_minimap(sfRenderWindow *window, game_t *game, player_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyTab) == 1
    && sfKeyboard_isKeyPressed(sfKeyUp) == 0
    && sfKeyboard_isKeyPressed(sfKeyDown) == 0
    && sfKeyboard_isKeyPressed(sfKeyRight) == 0
    && sfKeyboard_isKeyPressed(sfKeyLeft) == 0) {
        sfRenderWindow_drawSprite(window, game->mini_map->spr, NULL);
        sfRenderWindow_drawSprite(window, game->arrow->spr, NULL);
    }
}

void display_game(sfRenderWindow *window, game_t *game, player_t *player)
{
    sfRenderWindow_clear(window, sfBlack);
    display_back(window, game);
    sfSprite_setTextureRect(player->player_spr->spr, player->rect);
    sfSprite_setPosition(player->player_spr->spr, player->pos);
    display_logo(window, player, game);
    display_end_transition(window, game);
    display_fireplace(game, window);
    display_npc(window, game, player);
    sfRenderWindow_drawSprite(window, player->player_spr->spr, NULL);
    display_text(window, game, player);
    display_minimap(window, game, player);
    draw_xp_bar(window, game, player);
    sfRenderWindow_display(window);
}