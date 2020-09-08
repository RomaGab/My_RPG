/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** display_text.c
*/

#include "game.h"

void display_text(sfRenderWindow *window, game_t *game, player_t *player)
{
    sfText_setPosition(game->text,
    (sfVector2f){player->pos.x - 280, player->pos.y + 240});
    for (npc_t *tmp = game->npc; tmp; tmp = tmp->next) {
        if (tmp->conversation == true) {
            sfText_setString(game->text, game->str);
            sfRenderWindow_drawText(window, game->text, NULL);
        }
    }

}

int display_text_stats(sfRenderWindow *window, player_t *player)
{
    char *str_gold = int_str(player->gold);
    char *str_hp = int_str(player->hp_max);
    char *str_strength = int_str(player->strength);
    char *str_lvl = int_str(player->lvl);

    if (!str_gold || !str_hp || !str_lvl || !str_strength)
        return 84;
    sfText_setPosition(player->text_gold, (sfVector2f){1364, 327});
    sfText_setString(player->text_gold, str_gold);
    sfText_setString(player->text_hp, str_hp);
    sfText_setString(player->text_strength, str_strength);
    sfText_setString(player->text_lvl, str_lvl);
    sfRenderWindow_drawText(window, player->text_gold, NULL);
    sfRenderWindow_drawText(window, player->text_hp, NULL);
    sfRenderWindow_drawText(window, player->text_strength, NULL);
    sfRenderWindow_drawText(window, player->text_lvl, NULL);
    return 0;
}

int display_text_shop(sfRenderWindow *window, player_t *player)
{
    char *str_gold = int_str(player->gold);

    if (!str_gold)
        return 84;
    sfText_setPosition(player->text_gold, (sfVector2f){1727, 293});
    sfText_setString(player->text_gold, str_gold);
    sfRenderWindow_drawText(window, player->text_gold, NULL);
    return 0;
}