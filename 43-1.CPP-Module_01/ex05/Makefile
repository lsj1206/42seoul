# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:58:34 by seojulee          #+#    #+#              #
#    Updated: 2023/12/07 14:21:47 by seojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex05

CXX			= clang++
CXXFLAGS	= -std=c++98 $(WFLAGS)
WFLAGS		= -Wall -Wextra -Werror

SRCS		= main.cpp \
			  Harl.cpp


OBJS_DIR	= ./objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all			: $(NAME)

$(NAME)		: $(OBJS)
			@ $(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)	:
			@ mkdir $(OBJS_DIR)

$(OBJS_DIR)/%.o \
			: %.cpp $(OBJS_DIR)
			@ $(CXX) $(CXXFLAGS) -c $< -o $@

clean		:
			@ rm -rf $(OBJS_DIR)

fclean		: clean
			@ rm -rf $(NAME)

re			: fclean $(OBJS_DIR) all

.PHONY		: all clean fclean re
