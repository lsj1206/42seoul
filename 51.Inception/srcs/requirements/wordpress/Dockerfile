FROM debian:bullseye
# 포트 열기
EXPOSE 9000

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y dumb-init && \
    apt-get install -y php7.4 php-fpm php-mysql php-cli wget curl
# dumb-init은 PID 1로 실행되는 프로세스를 위한 init 시스템

# wp-cli 설치
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp
# wp-cli는 WordPress의 커맨드라인 인터페이스

RUN rm /etc/php/7.4/fpm/pool.d/www.conf
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

COPY ./tools/entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

ENTRYPOINT [ "dumb-init", "--", "/entrypoint.sh" ]
