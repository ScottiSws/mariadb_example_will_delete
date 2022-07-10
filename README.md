You'll need to install mariadb-connector-cpp manually.
Install CMAKE ( sudo apt install cmake )

find a directory you want to build it in, then...

git clone https://github.com/mariadb-corporation/mariadb-connector-cpp.git
cd mariadb-connector-cpp
git checkout 1.1.1
cmake .
make
sudo make install

You should now have your new libraries and headers in /usr/local/lib64/mariadb and /usr/local/include/mariadb

Fire up your own mariadb.
Alter the connection string in main.cpp

You can now make this project and run it.

cmake -B ./build -S .
cd build
make
./MariaDbTest