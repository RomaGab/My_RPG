/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** free_all.c
*/

#include "player.h"

void free_skin(skin_t *skin)
{
    free_sprite(skin->parallax1);
    free_sprite(skin->parallax2);
    free_sprite(skin->parallax3);
    free_sprite(skin->back);
    free_sprite(skin->sprite_laser);
    sfClock_destroy(skin->laser->clock);
    sfClock_destroy(skin->skin->clock);
    sfClock_destroy(skin->clock_par->clock);
    free(skin->clock_par);
    free(skin->laser);
    free(skin->skin);
    free(skin);
}

void free_class(class_t *class)
{
    free_sprite(class->parallax1);
    free_sprite(class->parallax2);
    free_sprite(class->parallax3);
    free_sprite(class->back);
    free_sprite(class->sprite_laser);
    free_sprite(class->transition);
    sfClock_destroy(class->clock->clock);
    sfClock_destroy(class->clock_par->clock);
    free(class->clock_par);
    free(class->clock);
    free(class);
}

void free_player(player_t *player)
{
    sfClock_destroy(player->clock->clock);
    free(player->clock);
    sfClock_destroy(player->clock_move->clock);
    free(player->clock_move);
    free_sprite(player->player_spr);
    sfText_destroy(player->text_gold);
    sfText_destroy(player->text_hp);
    sfText_destroy(player->text_strength);
    sfText_destroy(player->text_lvl);
    free(player);
}