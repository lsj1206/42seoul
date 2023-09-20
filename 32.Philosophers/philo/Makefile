# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 10:09:35 by seojulee          #+#    #+#              #
#    Updated: 2023/09/19 13:53:07 by seojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -pthread #-fsanitize=thread

SRCS		= main.c \
			  philo.c \
			  routine.c \
			  utils.c \
			  destroy.c \

OBJS_DIR	= ./objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all			: $(NAME)

$(NAME)		: $(OBJS)
			@ $(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)	:
			@ mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o \
			: %.c $(OBJS_DIR)
			@ $(CC) $(CFLAGS) -c $< -o $@

clean		:
			@ rm -rf $(OBJS_DIR)

fclean		: clean
			@ rm -rf $(NAME)

re			: fclean $(OBJS_DIR) all

.PHONY		: all clean fclean re
