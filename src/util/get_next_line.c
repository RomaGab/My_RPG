/*
** EPITECH PROJECT, 2019
** CPE_getnextline_2019
** File description:
** get_next_line.c
*/

#include "get_next_line.h"

static char fill(char *buffer, int *size, int fd)
{
    static int i = 0;

    if (*size == 0) {
        i = 0;
        *size = read(fd, buffer, READ_SIZE);
        buffer[*size] = '\0';
    }
    if (*size == 0)
        return buffer[*size];
    i += 1;
    *size -= 1;
    return buffer[i - 1];
}

static int new_malloc(int i, char **save)
{
    char *new = malloc(sizeof(char) * (i + READ_SIZE + 1));
    int j = 0;

    if (new == NULL) {
        *save = NULL;
        return -1;
    }
    new[i + READ_SIZE] = '\0';
    while ((*save)[j] != '\0') {
        new[j] = (*save)[j];
        j += 1;
    }
    *save = new;
    return 0;
}

char *get_next_line(int fd)
{
    static char buffer[READ_SIZE + 1];
    char *save = malloc(sizeof(char) * (READ_SIZE + 1));
    char stock = 0;
    static int size = 0;
    int i = 0;

    if (fd < 0 || save == NULL)
        return NULL;
    stock = fill(buffer, &size, fd);
    if (stock == '\0' || stock == '\n')
        return NULL;
    while (stock != '\n' && stock != '\0') {
        if (i % READ_SIZE == 0 && i != 0)
            if (new_malloc(i, &save) == -1)
                return NULL;
        save[i] = stock;
        i += 1;
        stock = fill(buffer, &size, fd);
    } save[i] = '\0';
    return save;
}