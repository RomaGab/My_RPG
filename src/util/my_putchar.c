/*
** EPITECH PROJECT, 2019
** myputchar
** File description:
** put
*/

#include "util.h"

int my_putchar(char const c)
{
    if (write(1, &c, 1) != 1) {
        return (84);
    }
    return (0);
}
