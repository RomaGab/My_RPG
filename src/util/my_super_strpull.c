/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_super_strpull.c
*/

#include <stdlib.h>

static int my_malloc(int i, char *src, char stop)
{
    int count = 0;

    for (int a = i; src[a] != '\0' && src[a] != stop; a++)
        count++;
    return count;
}

char *my_super_strpull(char *src, char stop, int *i)
{
    char *new = NULL;
    int count = 0;

    if (*i > 0 && src[*i - 1] == '\0' || src[*i] == '\0') {
        new = malloc(sizeof(char) * (2));
        if (!new)
            return NULL;
        new[0] = '+';
        new[1] = '\0';
        return new;
    } new = malloc(sizeof(char) * (my_malloc(*i, src, stop) + 1));
    if (!new)
        return NULL;
    for (; src[*i] != '\0' && src[*i] != stop; (*i)++, count++) {
        if (src[*i] == '/')
            new[count] = '\n';
        else
            new[count] = src[*i];
    } new[count] = '\0';
    return new;
}