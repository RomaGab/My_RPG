/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** returns a number
*/

#include "rpg.h"

int my_getnbr(char const *str)
{
    int count = 0;
    int convert_int = 0;

    while (str[count] != '\0') {
        if (str[count] >= '0' && str[count] <= '9')
            convert_int = convert_int * 10 + (str[count] - 48);
        else
            return -1;
        count = count + 1;
    }
    return convert_int;
}