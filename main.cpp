#include <iostream>
#include <string>
#include <mariadb/conncpp.hpp>
#include <stdlib.h>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

using namespace std;

std::string getLocalTime() {
    auto now = std::chrono::system_clock::now();
    time_t as_time = std::chrono::system_clock::to_time_t(now);
    std::stringstream string_stream;
    string_stream << std::put_time(std::localtime(&as_time), "%Y-%m-%d %X");

    return string_stream.str();
}

int main() 
{
    // Instantiate Driver
    sql::Driver* driver = sql::mariadb::get_driver_instance();

    // Configure Connection
    sql::SQLString url("jdbc:mariadb://localhost:3306/mydb");
    sql::Properties properties({{"user", "root"}, {"password", "badpassword"}});

    // Establish Connection
    std::unique_ptr<sql::Connection> conn(driver->connect(url, properties));

    // Create a new PreparedStatement
    std::unique_ptr<sql::PreparedStatement> stmntCreate(conn->prepareStatement("CREATE TABLE IF NOT EXISTS stuff (name varchar(80))"));
    // Execute query
    stmntCreate->executeQuery();

    // Create a new PreparedStatement
    std::unique_ptr<sql::PreparedStatement> stmntInsert(conn->prepareStatement("INSERT INTO stuff (name) values (?)"));
    // Bind values to SQL statement
    stmntInsert->setString(1, "Data inserted at: " + getLocalTime());
    // Execute query
    stmntInsert->executeQuery();

    // Create a new Statement
    std::unique_ptr<sql::Statement> stmntQuery(conn->createStatement());
    // Execute query
    sql::ResultSet *res = stmntQuery->executeQuery("select * from stuff");
    // Loop through and print results
    while (res->next()) {
        std::cout << "stuff = " << res->getString(1) << "\n";
    }
}
