#include "database_manip.h"

void callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << " ";
    }
    std::cout << std::endl;
}


void create_table(sqlite3* db) {
    const char* sql = "CREATE TABLE USERS ("
                      "ID INT PRIMARY KEY NOT NULL,"
                      "EMAIL TEXT NOT NULL,"
                      "PASSWORD TEXT NOT NULL,"
                      "NAME TEXT NOT NULL,"
                      "SURNAME TEXT NOT NULL,"
                      "NOTE TEXT NOT NULL);";

    int rc = sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Table created successfully" << std::endl;
    }
}

void open_db(const char *name, sqlite3 **db) {
    int rc = sqlite3_open(name, db);
    if (rc) {
        std::cerr << "Error opening DB: " << sqlite3_errmsg(*db) << std::endl;
        sqlite3_close(*db); // Close the database connection on error
    } else {
        std::cout << "Opened database successfully!" << std::endl;
    }
}

