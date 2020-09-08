/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** util.h
*/

#ifndef UTIL_H
#define UTIL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "typedef.h"

/*===========================================================================*/
/*Utils*/

char *my_strdup(char *src);
char *my_strcpy(char *dest, char const *src);
char *my_super_strpull(char *src, char stop, int *i);
char *my_revstr(char *str);

/*---------------------------------------------------------------------------*/

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);

#endif