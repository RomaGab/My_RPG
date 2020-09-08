/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** errors.c
*/

#include "error.h"
#include "util.h"

int errors(int ac, char **env)
{
    int i = 0;
    char *display = "DISPLAY=:0";

    if (ac > 2)
        return 84;
    if (env[0] == NULL)
        return 84;
    while (env[i] != NULL) {
        if (my_strcmp(env[i], display) == 0)
            return 0;
        i += 1;
    }
    return 84;
}