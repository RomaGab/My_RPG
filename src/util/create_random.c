/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** create_random.c
*/

#include "util.h"

int create_random(void)
{
    int fd = 0;
    char buff[2];

    fd = open("/dev/urandom", O_RDONLY);
    if (fd == -1)
        return -1;
    if (read(fd, buff, 2) != 2) {
        return (-1);
    }
    close(fd);
    if (buff[0] + buff[1] == -1)
        return -2;
    return (buff[0] + buff[1]);
}