# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:57:41 by seojulee          #+#    #+#              #
#    Updated: 2023/12/01 14:57:44 by seojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone

CXX			= clang++
CFLAGS		= -std=c++98 $(WFLAGS)
WFLAGS		= -Wall -Wextra -Werror

SRCS		= megaphone.cpp
OBJS		= $(SRCS:.cpp=.o)

all			: $(NAME)

$(NAME)		: $(OBJS)
			@ $(CXX) $(CFLAGS) -o $(NAME) $(OBJS)

%.o			: %.cpp
			@ $(CXX) $(CFLAGS) -c $< -o $@

clean		:
			@ rm -rf $(OBJS)

fclean		: clean
			@ rm -rf $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
