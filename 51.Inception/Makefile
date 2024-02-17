# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 16:16:31 by seojulee          #+#    #+#              #
#    Updated: 2024/02/16 15:06:03 by seojulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------------- VARIABLES -------------------------------- #
PROJECT				:= Inception
DOCKER_COMPOSE_FILE	:= ./srcs/docker-compose.yml
DOCKER_COMPOSE		:= docker-compose -f $(DOCKER_COMPOSE_FILE)
# -f : Compose 구성 파일을 지정하는 옵션
VOLUME_DIR			:= /home/seojulee/data
# ---------------------------------- COMMAND --------------------------------- #
.PHONY: all clean fclean re log info

all:
	@mkdir -p $(VOLUME_DIR)
	@mkdir -p $(VOLUME_DIR)/db
	@mkdir -p $(VOLUME_DIR)/wordpress
	@$(DOCKER_COMPOSE) up -d --build
# -d : detached mode, 백그라운드에서 실행
# --build : 이미지가 존재하더라도 새로 빌드

log:
	@$(DOCKER_COMPOSE) logs

info:
	@echo "\033[0m\033[0;36m=== Container List =============="
	@docker ps -a
	@echo "\033[0m\033[0;35m=== Image List =================="
	@docker image ls -a
	@echo "\033[0m\033[0;34m=== Volume List ================="
	@docker volume ls

clean:
	@$(DOCKER_COMPOSE) down

fclean: clean
	@docker system prune -af
	@if [ "$$(docker volume ls -q)" != "" ]; then \
		docker volume rm -f $$(docker volume ls -q); \
	fi
	@rm -rf $(VOLUME_DIR)
# -a : 모든 시스템 리소스 제거
# -f : 강제 제거

re: fclean all
