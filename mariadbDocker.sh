docker run \
        --rm    \
        --name sql-maria \
        -e MYSQL_ROOT_PASSWORD=badpassword \
        -e MYSQL_USER=username \
        -e MYSQL_PASSWORD=badpassword \
        -e MYSQL_DATABASE=mydb \
        -p 3306:3306 \
        -d mariadb:10
