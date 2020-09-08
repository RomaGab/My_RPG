/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** choose_skin.c
*/

#include "player.h"

static game_state_t fill_player(char *filepath, player_chose_t character,
                player_t *player, sfIntRect char_rect)
{
    game_state_t scene = StatePlayer;

    player->player_spr = fill_sprite(filepath);
    if (player->player_spr == NULL)
        return (StateError);
    player->character = character;
    player->char_logo = fill_sprite("res/sprite/character_logo.png");
    if (!player->char_logo)
        return StateError;
    player->rect_char = char_rect;
    player->rect = (sfIntRect){0, 0, 64, 60};
    player->pos = (sfVector2f) {1112, 920};
    sfSprite_setScale(player->player_spr->spr, (sfVector2f) {0.85, 0.85});
    return (scene);
}

game_state_t chose_skin(float click_x, float click_y, player_t *player,
                        skin_t *skin)
{
    game_state_t scene = StatePlayer;

    if (click_x > 614 && click_x < 650 && click_y > 720 && click_y < 760) {
        scene = fill_player("res/sprite/alyssa.png", ALYSSA, player,
        (sfIntRect){42, 0, 52, 40});
        skin->vect_laser = (sfVector2f){545, 0};
    } if (click_x > 833 && click_x < 870 && click_y > 720 && click_y < 760) {
        scene = fill_player("res/sprite/lucas.png", LUCAS, player,
        (sfIntRect){146, 0, 52, 40});
        skin->vect_laser = (sfVector2f){762, 0};
    } if (click_x > 1052 && click_x < 1088 && click_y > 720 && click_y < 760) {
        scene = fill_player("res/sprite/denis.png", DENIS, player,
        (sfIntRect){94, 0, 52, 40});
        skin->vect_laser = (sfVector2f){981, 0};
    } if (click_x > 1271 && click_x < 1307 && click_y > 720 && click_y < 760) {
        scene = fill_player("res/sprite/cecile.png", CECILE, player,
        (sfIntRect){0, 0, 42, 40});
        skin->vect_laser = (sfVector2f){1201, 0};
    }
    return scene;
}