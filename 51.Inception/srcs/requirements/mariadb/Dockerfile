FROM debian:bullseye
# 포트 열기
EXPOSE 3306

# 설치 및 설정
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y dumb-init && \
    apt-get install -y mariadb-client mariadb-server
# dumb-init은 PID 1로 실행되는 프로세스를 위한 init 시스템

RUN mkdir -p /var/run/mysqld
RUN chown mysql:mysql /var/run/mysqld
RUN chmod -R 755 /var/run/mysqld

COPY ./conf/my.cnf /etc/mysql/my.cnf
COPY ./tools/entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh

ENTRYPOINT ["dumb-init", "--", "/entrypoint.sh"]
