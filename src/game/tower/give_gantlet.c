/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** give_gantlet.c
*/

#include "tower.h"
#include "game.h"

static bool check_pos(player_t *player)
{
    if (player->pos.y <= -437 && player->pos.x >= -957
    && player->pos.y >= -460 && player->pos.x <= -882)
        return true;
    return false;
}

game_state_t gest_gantlet(player_t *player, game_t *game)
{
    item_t *item = player->inventory->item;
    int count = 0;

    for (int i = 0; i < 8; i++, count++) {
        if (item[i].id == Empty && game->verif_gantlet == false) {
            item[i] = add_item(item[i], Gantlet, 1);
            if (item[i].error == true)
                return StateError;
            game->verif_gantlet = true;
            break;
        }
    } if (count == 8 && player->inventory->item[7].id != Gantlet
    && game->verif_gantlet == false) {
        item[7] = remove_item(item[7]);
        item[7] = add_item(item[7], Gantlet, 1);
        if (item[7].error == true)
            return StateError;
        game->verif_gantlet = true;
    }
    return StateTower;
}

game_state_t give_gantlet(player_t *player, game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) == true && game->idx_gantlet == false
    && check_pos(player) == true) {
        if (gest_gantlet(player, game) == StateError)
            return StateError;
        sfSprite_setTextureRect(game->back_sprite,
        (sfIntRect){304, 0, 304, 237});
        game->idx_gantlet = true;
    }
    return StateTower;
}