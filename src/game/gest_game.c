/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gest_game.c
*/

#include "game.h"
#include "inventory.h"

static void modification_game(game_t *game, player_t *player)
{
    check_hitbox(player);
    move_player(player, game);
    handle_zoom(game, player);
    handle_dialogue(game, player);
    handle_lvl(player);
    quest(game, player);
}

static inventory_t *init_inventory(void)
{
    int i = 0;
    inventory_t *inventory = malloc(sizeof(inventory_t));

    if (!inventory)
        return (NULL);
    inventory->item = malloc(sizeof(item_t) * 8);
    if (!inventory->item)
        return NULL;
    for (i = 0; i < 8; i += 1) {
        inventory->item[i].id = Empty;
        inventory->item[i].quantity = 0;
        inventory->item[i].sprite = NULL;
    }
    inventory->hand_index = -1;
    return (inventory);
}

static void fill_stat_player(player_t *player)
{
    if (player->class == THIEF) {
        player->hp = 750;
        player->strength = 100;
    } if (player->class == MAGE) {
        player->hp = 1000;
        player->strength = 175;
    } if (player->class == BARBARIAN) {
        player->hp = 1500;
        player->strength = 150;
    }
    player->hp_max = player->hp;
    player->gold = 0;
    player->xp = 0;
    player->lvl = 1;
    player->armor = 0;
    player->pos_arrow = (sfVector2f){1200, 1084};
}

static game_state_t check_player(player_t *player, game_t *game)
{
    if (!player)
        return StateError;
    if (player->over == true)
        return StateOver;
    player->clock = fill_time();
    player->clock_move = fill_time();
    player->inventory = init_inventory();
    if (!player->clock || !player->inventory || !player->clock_move)
        return StateError;
    fill_stat_player(player);
    return StateGame;
}

game_state_t gest_game(sfRenderWindow *window, sfEvent event)
{
    game_state_t scene = StateGame;
    game_t *game = NULL;
    player_t *player = gest_chose_skin(window, &event);
    game_state_t check = check_player(player, game);

    if (check != StateGame)
        return check;
    game = create_game();
    if (!game || init_text_player(player, game) == 84)
        return (StateError);
    while (scene == StateGame) {
        while (sfRenderWindow_pollEvent(window, &event) && scene == StateGame)
            scene = analyse_eventgame(window, game, &event, player);
        modification_game(game, player);
        display_game(window, game, player);
    }
    free_game(game, player, window);
    return (scene);
}