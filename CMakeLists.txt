cmake_minimum_required(VERSION 3.0.0)

# Add paths to where mariadbcpp installs after build.
list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib64/mariadb")

project(MariaDbTest VERSION 0.1.0)

# For unit testing
include(CTest)
enable_testing()


find_library(MARIADB_CPP mariadbcpp)


add_executable(MariaDbTest main.cpp)
target_link_libraries(MariaDbTest ${MARIADB_CPP})

# For generating installers
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
