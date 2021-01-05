FROM debian:buster

LABEL		maintainer="<hyeolee.student.42seoul.kr>"

RUN			apt-get update && apt-get -y upgrade && apt-get -y install \
			nginx \
			openssl \
			php-fpm \
			mariadb-server php-mysql \
			wget \
			vim
RUN			wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN			tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN 		wget https://wordpress.org/latest.tar.gz
RUN			tar -xvf latest.tar.gz

COPY		./srcs/run.sh ./
COPY		./srcs/default ./tmp
COPY		./srcs/wp-config.php ./tmp
COPY		./srcs/config.inc.php ./tmp

EXPOSE		80 443

CMD			bash run.sh
