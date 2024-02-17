#!/bin/bash
mysql_install_db --user=root

echo "CREATE DATABASE IF NOT EXISTS ${DB_NAME};
FLUSH PRIVILEGES;
USE ${DB_NAME};
CREATE USER '${MYSQL_USER_ID}'@'%' IDENTIFIED BY '${MYSQL_USER_PWD}';
GRANT ALL PRIVILEGES ON * TO '${MYSQL_USER_ID}'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PWD}';" > sql
# -uroot : root 사용자로 접속하도록 지정
# --bootstrap : 부트스트랩 모드로 시작해 데이터 디렉토리가 비어 있으면 초기 데이터베이스를 생성하고 초기화
#(처음 설치하거나 데이터 디렉토리가 비어 있는 경우에 사용)
# 데이터베이스가 존재하지 않으면 생성
# 권한을 새로고침
# 데이터베이스 사용
# 사용자 생성 및 암호 설정
# 사용자에게 모든 권한 부여 및 GRANT OPTION 설정
# 권한을 새로고침
# 'root'@'localhost' 사용자의 암호 변경

mysqld -uroot --bootstrap < sql
mysqld -uroot
