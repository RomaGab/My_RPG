/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** music.c
*/

#include "game.h"

static void set_buffer(music_t *music)
{
    sfSound_setBuffer(music->sound_dialogue, music->buf_dial);
    sfSound_setBuffer(music->sound_state, music->buf_state);
    sfSound_setBuffer(music->sound_teleportation, music->buf_tele);
}

music_t *fill_music(void)
{
    music_t *music = malloc(sizeof(struct music_s));

    if (!music)
        return (NULL);
    music->buf_dial = sfSoundBuffer_createFromFile("res/audio/dialogue.ogg");
    music->buf_state = sfSoundBuffer_createFromFile("res/audio/state.ogg");
    music->buf_tele = sfSoundBuffer_createFromFile("res/audio/teleport.ogg");
    music->music_cave = sfMusic_createFromFile("./res/audio/cave_theme.ogg");
    music->music_city = sfMusic_createFromFile("./res/audio/city_theme.ogg");
    music->music_boss = sfMusic_createFromFile("./res/audio/boss_theme.ogg");
    music->music_tower = sfMusic_createFromFile("./res/audio/tower_theme.ogg");
    music->sound_dialogue = sfSound_create();
    music->sound_state = sfSound_create();
    music->sound_teleportation = sfSound_create();
    if (!music->music_cave || !music->music_city || !music->music_boss
    || !music->music_tower || !music->buf_dial || !music->buf_state ||
    !music->buf_tele)
        return (NULL);
    set_buffer(music);
    return (music);
}

static void free_buffer(music_t *music)
{
    if (music->sound_teleportation)
        sfSound_destroy(music->sound_teleportation);
    if (music->buf_dial)
        sfSoundBuffer_destroy(music->buf_dial);
    if (music->buf_state)
        sfSoundBuffer_destroy(music->buf_state);
    if (music->buf_tele)
        sfSoundBuffer_destroy(music->buf_tele);
}

void free_music(music_t *music)
{
    if (music->music_city)
        sfMusic_destroy(music->music_city);
    if (music->music_cave)
        sfMusic_destroy(music->music_cave);
    if (music->music_boss)
        sfMusic_destroy(music->music_boss);
    if (music->music_tower)
        sfMusic_destroy(music->music_tower);
    if (music->sound_dialogue)
        sfSound_destroy(music->sound_dialogue);
    if (music->sound_state)
        sfSound_destroy(music->sound_state);
    free_buffer(music);
    free(music);
}