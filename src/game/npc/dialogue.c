/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** dialogue.c
*/

#include "game.h"
#include "get_next_line.h"
#include "util.h"

void handle_dialogue(game_t *game, player_t *player)
{
    for (npc_t *tmp = game->npc; tmp; tmp = tmp->next) {
        if (tmp->conversation == true && (player->pos.x < tmp->pos.x - 60 ||
        player->pos.x > tmp->pos.x + 60 || player->pos.y < tmp->pos.y - 60 ||
        player->pos.y > tmp->pos.y + 60)) {
            tmp->where = 0;
            tmp->conversation = false;
        }
    }
}

char **chose_dialogue(char *dialogue[11], int i)
{
    int nb[4] = {4, 5, 0, 2};
    int start[4] = {0, 4, 0, 9};
    char **new = malloc(sizeof(char *) * (nb[i] + 1));

    if (!new || i == 2)
        return NULL;
    for (int a = 0; a < nb[i]; a++) {
        new[a] = malloc(sizeof(char) *
        (my_strlen(dialogue[start[i] + a]) + 1));
        if (!new[a])
            return NULL;
        new[a][my_strlen(dialogue[start[i] + a])] = '\0';
    }
    for (int a = 0; a < nb[i]; a++) {
        new[a] = my_strcpy(new[a], dialogue[start[i] + a]);
    }
    new[nb[i]] = NULL;
    return new;
}

char **give_dialogue(int i)
{
    int fd = open("src/game/npc/dialogue.txt", O_RDONLY);

    if (fd == -1)
        return NULL;
    char *dialogue[11] = {get_next_line(fd), get_next_line(fd),
    get_next_line(fd), get_next_line(fd), get_next_line(fd),
    get_next_line(fd), get_next_line(fd), get_next_line(fd),
    get_next_line(fd), get_next_line(fd), get_next_line(fd)};
    for (int a = 0; a != 11; a++) {
        if (!dialogue[a])
            return NULL;
    }
    close(fd);
    return (chose_dialogue(dialogue, i));
}

static bool find_dialogue2(char *new, game_t *game, player_t *player,
                            npc_t *tmp)
{
    if (my_strcmp(new, "+") == 0) {
        tmp->conversation = false;
        tmp->where = 0;
        if (tmp->state_quest == quest_never && tmp->nb_quest == 1 &&
        tmp->nb_npc == 1)
            player->gold += 30;
        if ((tmp->state_quest == quest_never)) {
            tmp->state_quest++;
            player->xp += 20;
        }
        game->str = NULL;
        return true;
    }
    return false;
}

int find_dialogue(npc_t *tmp, game_t *game, player_t *player)
{
    char *new = NULL;
    int nb = chose_nb(tmp);

    sfSound_play(game->music->sound_dialogue);
    if (tmp->conversation == true && tmp->state_quest == no_quest &&
    game->str && my_strcmp(game->str, "+") != 0) {
        tmp->where = 0;
        new = my_strdup("+");
    } else
        new = my_super_strpull(tmp->dialogue[nb], '+', &(tmp->where));
    if (!new)
        return 84;
    tmp->where++;
    if (find_dialogue2(new, game, player, tmp) == true)
        return 0;
    game->str = new;
    return 0;
}