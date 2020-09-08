/*
** EPITECH PROJECT, 2019
** rpg.h
** File description:
** rpg
*/

#ifndef RPG_H
#define RPG_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include "typedef.h"
#include "cave.h"

/*===========================================================================*/
/*Inventory*/

struct scene_s
{
    game_state_t (*fptr)(sfRenderWindow *, sfEvent);
};

/*---------------------------------------------------------------------------*/

game_state_t gest_menu(sfRenderWindow *window, sfEvent event);
game_state_t gest_game(sfRenderWindow *window, sfEvent event);
game_state_t gest_launch(sfRenderWindow *window, sfEvent event);

/*---------------------------------------------------------------------------*/

int print_help(void);
int start_game(void);
int print_usage(void);
int create_random(void);
int errors(int ac, char **env);
int main(int ac, char **av, char **env);

/*---------------------------------------------------------------------------*/

void free_window(sfRenderWindow *window);

#endif