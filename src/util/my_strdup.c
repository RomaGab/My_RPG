/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** my_strdup.c
*/

#include "stdlib.h"
#include "util.h"

char *my_strdup(char *src)
{
    char *new = malloc(sizeof(char) * (my_strlen(src) + 1));
    int i = 0;

    if (!new)
        return NULL;
    while (src[i]) {
        new[i] = src[i],
        i++;
    }
    new[i] = '\0';
    return new;
}