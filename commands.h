#pragma once


#include <regex>
#include "sqlite3.h"
#include "user.h"


bool execute_command(std::string &command, sqlite3 *db, User &user);