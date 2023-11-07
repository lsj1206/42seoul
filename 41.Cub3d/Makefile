# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:20:05 by seojulee          #+#    #+#              #
#    Updated: 2023/11/01 18:07:10 by seojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror $(LEAKS_CHECK)

IFLAGS		= -I $(INCS_DIR) $(LFT_FLAGS) $(MLX_FLAGS)
LFT_FLAGS	= -L ./lib/libft -lft
#MLX_FLAGS	= -L ./lib/mlx -lmlx -framework OpenGL -framework AppKit
MLX_FLAGS = -L ./lib/mlx_linux -lmlx -lm -lXext -lX11

LEAKS_CHECK	= -g -fsanitize=address

INCS_DIR	= ./includes/
SRCS_DIR	= ./srcs
OBJS_DIR	= ./objs

SRCS_FILE	= main.c \
			  utils.c \
			  utils_char.c \
			  parser.c \
			  parser_arg.c \
			  parser_rgb.c \
			  parser_map.c \
			  parser_map_component.c \
			  parser_map_outer.c \
			  parser_texture.c \
			  raycasting.c \
			  draw.c \
			  event.c \
			  move.c \
			  destroy.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS_FILE:.c=.o))

vpath %.c	$(SRCS_DIR)

all			: $(NAME)

$(NAME)		: $(OBJS)
			@ $(MAKE) -C ./lib/libft
			@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(IFLAGS)

$(OBJS_DIR)	:
			@ mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o \
			: %.c $(OBJS_DIR)
			@ $(CC) $(CFLAGS) -c $< -o $@

clean		:
			@ $(MAKE) -C ./lib/libft clean
			@ rm -rf $(OBJS_DIR)

fclean		: clean
			@ rm -rf ./lib/libft/libft.a
			@ rm -rf $(NAME)

re			: fclean $(OBJS_DIR) all

.PHONY		: all clean fclean re
