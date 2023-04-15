# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 15:20:05 by seojulee          #+#    #+#              #
#    Updated: 2023/03/18 15:45:29 by seojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror #-fsanitize=address
RM			= rm -f

NAME		= server
NAME_C		= client

SRCS_S		= server.c utils.c
SRCS_SB		= server_bonus.c utils_bonus.c
SRCS_C		= client.c utils.c
SRCS_CB		= client_bonus.c utils_bonus.c
SRCS_U		= ft_printf/ft_printf.c \
			  ft_printf/ft_printf_utils.c \
			  ft_printf/ft_printf_specifier.c

OBJS_S		= $(SRCS_S:.c=.o)
OBJS_SB		= $(SRCS_SB:.c=.o)
OBJS_C		= $(SRCS_C:.c=.o)
OBJS_CB		= $(SRCS_CB:.c=.o)
OBJS_U		= $(SRCS_U:.c=.o)

ifdef BONUS
	OBJS_A	= $(OBJS_SB)
	OBJS_B	= $(OBJS_CB)
else
	OBJS_A	= $(OBJS_S)
	OBJS_B	= $(OBJS_C)
endif

all			: $(NAME) $(NAME_C)

$(NAME)		: $(OBJS_A) $(OBJS_U)
			@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS_A) $(OBJS_U)

$(NAME_C)	: $(OBJS_B)
			@ $(CC) $(CFLAGS) -o $(NAME_C) $(OBJS_B) $(OBJS_U)

bonus		:
			@ make BONUS=1 all

.c.o		:
			@ $(CC) $(CFLAGS) -c $< -o $@

clean		:
			@ $(RM) $(OBJS_S) $(OBJS_SB) $(OBJS_C) $(OBJS_CB) $(OBJS_U)

fclean		: clean
			@ $(RM) $(NAME) $(NAME_C)

re			: fclean all

.PHONY		: all clean fclean re bonus
