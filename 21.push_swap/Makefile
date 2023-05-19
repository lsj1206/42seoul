# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:20:05 by seojulee          #+#    #+#              #
#    Updated: 2023/02/20 16:30:07 by seojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address
RM		= rm -f

HEADER	= ./header

SRCS	= ./srcs/main.c \
		  ./srcs/push_swap_init.c \
		  ./srcs/push_swap_error.c \
		  ./srcs/push_swap_utils_01.c \
		  ./srcs/push_swap_utils_02.c \
		  ./srcs/push_swap_utils_03.c \
		  ./srcs/sort.c \
		  ./srcs/sort_utils.c \
		  ./srcs/sort_pivot.c \
		  ./srcs/sort_three.c \
		  ./srcs/command_00.c \
		  ./srcs/command_01.c \
		  ./srcs/command_02.c \
		  ./srcs/command_03.c \
		  ./srcs/only_case.c \
		  ./srcs/only_case_utils.c \
		  ./srcs/printer.c

OBJS	= $(SRCS:.c=.o)

all		: 	$(NAME)

$(NAME) :   $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.c.o :
			$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean	:
			$(RM) $(OBJS)
fclean	:	clean
			$(RM) $(NAME)
re		:	fclean all

.PHONY	: all clean fclean re
