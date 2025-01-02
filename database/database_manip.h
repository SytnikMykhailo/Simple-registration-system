#ifndef DATABASE_MANIP_H
#define DATABASE_MANIP_H

#include "../sqlite3.h"
#include <iostream>

void create_table(sqlite3 *db);
void open_db(const char *name, sqlite3 **db);
void callback(void *NotUsed, int argc, char **argv, char **azColName);


#endif