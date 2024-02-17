#!/bin/bash

mkdir -p /run/php/;

if [ ! -f /var/www/wp-config.php ]; then
    mkdir -p /var/www;
    cd /var/www;

    wp core download --allow-root;

    wp config create --allow-root \
        --dbname=$DB_NAME \
        --dbuser=$MYSQL_USER_ID \
        --dbpass=$MYSQL_USER_PWD \
        --dbhost=$DB_HOST \
        --path=/var/www;

    echo "Success: WordPress installation has started."

    wp core install --title=$TITLE \
        --url=$WEB_URL \
        --admin_user=$WEB_ADMIN_ID \
        --admin_password=$WEB_ADMIN_PWD \
        --admin_email=$WEB_ADMIN_EMAIL \
        --path=/var/www \
        --allow-root;

    wp user create $WEB_USER_ID $WEB_USER_EMAIL \
        --user_pass=$WEB_USER_PWD \
        --allow-root \
        --role=author;
fi

chown -R www-data:www-data /var/www/*;
chmod -R 755 /var/www/*;

echo "Success: You can visit $WEB_URL in your browser."

exec  php-fpm7.4 -F
