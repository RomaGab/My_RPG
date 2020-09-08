/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** int_string.c
*/

#include "util.h"

int length(int nbr)
{
    int length_nbr = 1;

    while (nbr >= 10) {
        nbr /= 10;
        length_nbr += 1;
    }
    return length_nbr;
}

char *int_str(int nbr)
{
    int length_nbr = length(nbr);
    char *score = malloc(sizeof(char) * (length_nbr + 1));
    int i = 0;
    int calcul = 0;

    if (!score)
        return NULL;
    while (i < length_nbr) {
        calcul = nbr % 10;
        nbr /= 10;
        score[i] = calcul + 48;
        i += 1;
    }
    score[length_nbr] = '\0';
    return (my_revstr(score));
}