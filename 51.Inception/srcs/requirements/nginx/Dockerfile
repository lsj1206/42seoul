FROM debian:bullseye
# 포트 열기
EXPOSE 443

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y nginx openssl

RUN openssl req -x509 -nodes \
    -days 365 \
    -newkey rsa:2048 \
    -keyout /etc/ssl/seojulee.key \
    -out /etc/ssl/seojulee.crt \
    -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=seojulee/CN=seojulee.42.fr"
# x509: X.509는 공개키 기반의 인증서를 발급하고 관리하기 위한 표준이다.
# -nodes: 비밀번호를 묻지 않는다.
# -days: 인증서의 유효기간을 설정한다.
# -newkey: 새로운 키를 생성한다.
# -keyout: 생성된 키를 저장할 파일명을 지정한다.
# -out: 생성된 인증서를 저장할 파일명을 지정한다.
# -subj: 인증서의 정보를 설정한다.

COPY ./conf/default /etc/nginx/sites-available/default

RUN chmod 700 /etc/ssl/seojulee.crt
RUN chmod 700 /etc/ssl/seojulee.key

ENTRYPOINT ["nginx", "-g", "daemon off;"]
