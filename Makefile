##
## EPITECH PROJECT, 2019
## Makefile.c
## File description:
## Makefile
##

SRC	=	src/main.c													\
		src/start_game.c											\
		src/free/free_window.c										\
		src/free/free_sprite.c										\
		src/free/free_player.c										\
		src/free/free_game.c										\
		src/free/free_pause.c										\
		src/error/errors.c											\
		src/launch/gest_launch.c									\
		src/game/mini_map.c											\
		src/launch/analyse_eventlaunch.c							\
		src/launch/display_launch.c									\
		src/launch/free_launch.c									\
		src/menu/gest_menu.c										\
		src/menu/create_menu.c										\
		src/menu/analyse_eventmenu.c								\
		src/menu/display_menu.c										\
		src/menu/free_menu.c										\
		src/menu/move_parallax.c									\
		src/menu/highscore/gest_highscore.c							\
		src/menu/highscore/free_highscore.c							\
		src/menu/highscore/display_highscore.c						\
		src/menu/highscore/create_highscore.c						\
		src/menu/highscore/analyse_eventhighscore.c					\
		src/menu/highscore/new_score.c								\
		src/menu/howtoplay/gest_howtoplay.c							\
		src/menu/howtoplay/create_help.c							\
		src/menu/howtoplay/analyse_eventhowtoplay.c					\
		src/menu/howtoplay/display_help.c							\
		src/menu/howtoplay/free_help.c								\
		src/game/gest_game.c										\
		src/game/create_game.c										\
		src/game/cave/gest_cave.c									\
		src/game/cave/analyse_eventcave.c							\
		src/game/analyse_eventgame.c								\
		src/game/display/display_game.c								\
		src/game/quest.c											\
		src/game/lvl.c												\
		src/game/text.c												\
		src/game/music.c											\
		src/game/display/display_logo.c								\
		src/game/display/display_npc.c								\
		src/game/display/display_tower.c							\
		src/game/display/display_text.c								\
		src/game/display/display_cave.c								\
		src/game/display/display_fireplace.c						\
		src/game/display/display_fight.c							\
		src/game/display/display_item_fight.c						\
		src/game/display/dispay_fight_animation.c					\
		src/game/pause/gest_pause.c									\
		src/game/pause/display_pause.c								\
		src/game/pause/analyse_eventpause.c							\
		src/game/pause/create_pause.c								\
		src/game/item/add_item.c									\
		src/game/item/remove_item.c									\
		src/game/item/verif_item_inv.c								\
		src/game/inventory/gest_inventory.c							\
		src/game/inventory/display_inventory.c						\
		src/game/inventory/skill_tree.c								\
		src/game/inventory/gest_skill_top.c							\
		src/game/inventory/gest_skill_mid.c							\
		src/game/inventory/gest_skill_bot.c							\
		src/game/inventory/analyse_eventinventory.c					\
		src/game/inventory/create_inventory_ui.c					\
		src/game/inventory/free_inventory.c							\
		src/game/shop/gest_shop.c									\
		src/game/shop/display_shop.c								\
		src/game/shop/analyse_eventshop.c							\
		src/game/shop/create_shop.c									\
		src/game/shop/free_shop.c									\
		src/game/player_gestion/analyse_eventplayer.c				\
		src/game/player_gestion/chose_skin.c						\
		src/game/player_gestion/display_back.c						\
		src/game/player_gestion/move_player.c						\
		src/game/player_gestion/gest_chose_skin.c					\
		src/game/player_gestion/gest_chose_class.c					\
		src/game/player_gestion/display_transition.c				\
		src/game/player_gestion/hitbox/hitbox.c						\
		src/game/player_gestion/hitbox/hitbox_tower.c				\
		src/game/player_gestion/hitbox/hitbox_harbor.c				\
		src/game/player_gestion/hitbox/hitbox_builds.c				\
		src/game/player_gestion/hitbox/hitbox_cave.c				\
		src/game/player_gestion/hitbox/hitbox_box.c					\
		src/game/player_gestion/hitbox/hitbox_tower_out.c			\
		src/game/player_gestion/hitbox/hitbox_cave_second_room.c	\
		src/game/player_gestion/hitbox/hitbox_cave_room_four.c		\
		src/game/npc/create_npc.c									\
		src/game/npc/dialogue.c										\
		src/game/npc/interaction.c									\
		src/game/zoom/zoom.c										\
		src/game/tower/gest_tower.c									\
		src/game/tower/analyse_eventtower.c							\
		src/game/tower/give_gantlet.c								\
		src/game/fight/gest_fight.c									\
		src/game/fight/create_fight.c								\
		src/game/fight/fight_rounds.c								\
		src/game/fight/analyse_eventfight.c							\
		src/game/fight/fill_fight.c									\
		src/game/fight/display_win.c										\
		src/game/fight/attack_turn.c								\
		src/game/fight/free_fight.c									\
		src/game/fight/redirect_item.c								\
		src/print/print_help.c										\
		src/print/print_usage.c										\
		src/util/my_putchar.c										\
		src/util/my_putstr.c										\
		src/util/my_strcmp.c										\
		src/util/my_strlen.c										\
		src/util/create_random.c									\
		src/util/my_revstr.c										\
		src/util/get_next_line.c									\
		src/util/my_strcpy.c										\
		src/util/my_super_strpull.c									\
		src/util/my_strdup.c										\
		src/util/my_getnbr.c										\
		src/util/clock.c											\
		src/util/sprite.c											\
		src/util/int_string.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all:	$(NAME)

CFLAGS	+=	-I include -g

CSFML	=	-lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio

$(NAME):	$(OBJ)
	gcc $(CSFML) -o $(NAME) $(OBJ)

%.o:	%.c
	@echo -n "Compiling : $<"
	@$(CC) $(CFLAGS) $(CSFML) -c $< -o $@ && echo -e " [\033[32mOK\033[0m]" || echo -e " [\033[32mK0\033[0m]"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean re