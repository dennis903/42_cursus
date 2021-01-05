#!/bin/bash

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

cp ./tmp/default etc/nginx/sites-available/

mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/

cp ./tmp/config.inc.php /var/www/html/phpmyadmin/

mv wordpress /var/www/html/
chown -R www-data:www-data /var/www/html/wordpress

cp ./tmp/wp-config.php /var/www/html/wordpress/

service mysql start
service nginx start
service php7.3-fpm start

echo "CREATE DATABASE IF NOT EXISTS wordpress;" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* TO 'hyeolee'@'%' IDENTIFIED BY '1111' WITH GRANT OPTION" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password

service nginx reload
bash
