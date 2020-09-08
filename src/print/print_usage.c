/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** print_usage.c
*/

#include "usage.h"

int print_usage(void)
{
    if (my_putstr("This game is a tower defense.\n") == -1)
        return (84);
    if (my_putstr("The goal is to save the world against ") == -1)
        return (84);
    if (my_putstr("the demons.\n") == -1)
        return (84);
    if (my_putstr("\n\n") == -1)
        return (84);
    if (my_putstr("USAGE\n    ./my_rpg\n\n") == -1)
        return (84);
    if (my_putstr("COMMAND\n    ESC : Close the game\n") == -1)
        return (84);
    if (my_putstr("    P : Pause the game\n") == -1)
        return (84);
    if (my_putstr("    R : Resume the game\n") == -1)
        return (84);
    if (my_putstr("    Directionnal arrows : Move.\n") == -1)
        return (84);
    return (0);
}