# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaimi <mnaimi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 10:53:27 by mnaimi            #+#    #+#              #
#    Updated: 2022/08/13 17:44:26 by mnaimi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------------------------------------------------------------------------- #

CC			:= gcc
CC_FLAGS	:= -Wall -Wextra -Werror --std=c99 --pedantic \
	-fstack-protector-strong -fno-signed-zeros -mtune=intel \
	-Ofast -Os -march=native -fno-trapping-math
#-fsanitize=address -static-libsan

CC_OPTS		:= -I /usr/local/include -L/usr/local/lib/ -lmlx \
	-framework OpenGL -framework AppKit -lft -L includes/libft \
	includes/get_next_line/get_next_line.c

# ---------------------------------------------------------------------------- #

GEN_LST	:=	file_parcer.c data_init.c check_map.c

DISPLAY	:=	line_drawing_algo.c \
	window_management.c \
	coordinates_calculs.c
DRAWING	:=	minimap.c minimap_player.c misc_drawing.c custom_line_algo.c

EVENTS			:=	handle_keypress.c handle_mouse_events.c
CASTING_RAYS	:=	casting_rays.c cast.c misc_functs.c
RENDERING_WALLS	:=	render_walls.c


SRCS	:= ${addprefix srcs/map_parsing/, ${GEN_LST}} \
	${addprefix srcs/display_management/, ${DISPLAY}} \
	${addprefix srcs/display_management/objects_drawing/, ${DRAWING}} \
	${addprefix srcs/event_handling/, ${EVENTS}} \
	${addprefix srcs/raycast_calculs/, ${CASTING_RAYS}} \
	${addprefix srcs/rendering_walls/, ${RENDERING_WALLS}}

NAME	:= cub3d
MAIN	:= srcs/cub3d.c
HEADER	:= srcs/cub3d.h srcs/m4cr0s.h

# ---------------------------------------------------------------------------- #

.PHONY: all clean fclean re

all: ${NAME}

${NAME}: ${HEADER} ${MAIN} ${SRCS}
	@echo "Making dependencies, please wait ..."
	@make -C includes/libft >> /dev/null
	@echo "Making ./cub3d executable, please wait ..."
	@${CC} ${CC_FLAGS} ${CC_OPTS} ${MAIN} ${SRCS} -o ${NAME}
	@echo "${NAME}: Compiled successfully"

clean:
	@make clean -C includes/libft >> /dev/null

fclean: clean
	@rm -f ${NAME}
	@make fclean -C includes/libft >> /dev/null

re: fclean all
