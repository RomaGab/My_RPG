/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Display
*/

#include "usage.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_putchar(str[i]) == -1) {
            return (-1);
        }
        i = i + 1;
    }
    return (i);
}
