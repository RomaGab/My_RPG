/*
** EPITECH PROJECT, 2019
** Minimum
** File description:
** main.c
*/

#include "rpg.h"
#include "util.h"

int main(int argv, char **argc, char **env)
{
    int ret = StateLoad;
    int create_rand = 0;

    if (errors(argv, env) == 84)
        return 84;
    if (argv == 1) {
        create_rand = create_random();
        if (create_rand == -1)
            return 84;
        srand(create_rand);
        ret = start_game();
    } else if (argv == 2 && my_strcmp(argc[1], "-h") == 0) {
        ret = print_usage();
    } else {
        ret = print_help();
    }
    return (ret);
}
