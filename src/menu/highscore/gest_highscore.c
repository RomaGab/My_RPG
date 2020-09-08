/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** gest_howtoplay.c
*/

#include "highscore.h"
#include <stdio.h>

static char *fill_score(char *path)
{
    FILE *file = fopen(path, "r");
    size_t len_score = 0;
    char *scr = NULL;

    if (file == NULL)
        return NULL;
    if (getline(&scr, &len_score, file) == -1)
        return NULL;
    fclose(file);
    return scr;
}

static int set_str(highscore_t *high)
{
    char *last_score = fill_score("src/menu/highscore/lastscore.txt");
    char *high_score = fill_score("src/menu/highscore/highscore.txt");

    if (!last_score || !high_score)
        return 84;
    sfText_setString(high->text_highscore, high_score);
    sfText_setString(high->text_lastscore, last_score);
    free(last_score);
    free(high_score);
    return 0;
}

game_state_t gest_highscore(sfRenderWindow *window, sfEvent *event)
{
    game_state_t scene = StateHighscore;
    highscore_t *highscore = NULL;

    if (!window || !event)
        return (StateError);
    highscore = create_highscore();
    if (!highscore || set_str(highscore) == 84)
        return StateError;
    while (scene == StateHighscore) {
        while (sfRenderWindow_pollEvent(window, event)) {
            scene = analyse_eventhighscore(window, event, highscore);
        }
        display_highscore(window, highscore);
    }
    free_highscore(highscore);
    return (scene);
}