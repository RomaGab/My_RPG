/*
** EPITECH PROJECT, 2019
** PSU_minishell1_2019
** File description:
** my_strlen.c
*/

#include "rpg.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (!str) {
        return (-1);
    }
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
