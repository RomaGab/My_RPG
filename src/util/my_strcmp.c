/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** compare str
*/

#include "util.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 || !s2) {
        return (84);
    }
    if (my_strlen(s1) != my_strlen(s2)) {
        return (84);
    }
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i = i + 1;
    }
    return (0);
}