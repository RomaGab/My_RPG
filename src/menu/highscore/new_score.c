/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** new_score.c
*/

#include "fight.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

static int get_score(char *path)
{
    int score = 0;
    int fd = open(path, O_RDONLY);
    char *scr = NULL;

    if (fd == -1)
        return -1;
    scr = get_next_line(fd);
    if (scr == NULL)
        return  -1;
    score = my_getnbr(scr);
    free(scr);
    close(fd);
    return score;
}

static int fill_score(int scr, char *path)
{
    int fd = open(path, O_WRONLY);
    char *score = int_str((int)scr);

    if (fd == -1 || score == NULL)
        return 84;
    if (write(fd, score, my_strlen(score)) == -1)
        return 84;
    free(score);
    close(fd);
    return 0;
}

int new_score(game_t *game, fight_t *fight)
{
    int last_score = get_score("src/menu/highscore/lastscore.txt");
    int high_score = get_score("src/menu/highscore/highscore.txt");

    if (last_score == -1 || high_score == -1)
        return 84;
    if (fight->hp_boss > 0)
        return 0;
    game->time->time = sfClock_getElapsedTime(game->time->clock);
    game->time->seconds = sfTime_asMilliseconds(game->time->time);
    if (fill_score(game->time->seconds,
    "src/menu/highscore/lastscore.txt") == 84)
        return 84;
    if (high_score == 0 || (int)(game->time->seconds) < high_score) {
        if (fill_score(game->time->seconds,
        "src/menu/highscore/highscore.txt") == 84)
            return 84;
    }
    return 0;
}