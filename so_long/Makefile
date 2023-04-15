# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:20:05 by seojulee          #+#    #+#              #
#    Updated: 2023/03/07 17:23:18 by seojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address
RM		= rm -f

MLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit

SRCS	= ./srcs/main.c \
		  ./srcs/map.c \
		  ./srcs/event.c \
		  ./srcs/printer.c \
		  ./srcs/free.c \
		  ./srcs/dfs.c \
		  ./srcs/error_01.c \
		  ./srcs/error_02.c \
		  ./srcs/utils_01.c \
		  ./srcs/utils_02.c \
		  ./srcs/utils_mlx.c

OBJS	= $(SRCS:.c=.o)

all		: 	$(NAME)

$(NAME) :   $(OBJS)
			$(CC) $(CFLAGS) $(MLX) -o $(NAME) $(OBJS)

.c.o :
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean	:
			$(RM) $(OBJS)
fclean	:	clean
			$(RM) $(NAME)
re		:	fclean all

.PHONY	: all clean fclean re
