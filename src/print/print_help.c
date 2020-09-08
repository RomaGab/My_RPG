/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** print_help.c
*/

#include "usage.h"

int print_help(void)
{
    if (my_putstr("'./my_defender' for play\n") == -1) {
        return (84);
    }
    if (my_putstr("Or './my_defender -h' for more information\n") == -1) {
        return (84);
    }
    return (84);
}