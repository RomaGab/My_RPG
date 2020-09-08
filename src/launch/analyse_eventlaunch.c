/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2019
** File description:
** analyse_eventlaunch.c
*/

#include "launch.h"

game_state_t analyse_eventlaunch(sfEvent *event)
{
    if (event->type == sfEvtClosed) {
        return (StateOver);
    }
    if (event->key.code == sfKeyEscape) {
        return (StateOver);
    } else if (event->key.code == sfKeySpace) {
        return (StateMenu);
    }
    return (StateLoad);
}