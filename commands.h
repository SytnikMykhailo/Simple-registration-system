#pragma once
#include <regex>
#include "sqlite3.h"
#include "user.h"

struct command_regex{
    std::regex command_reg;
    std::string description;
    command_regex* next;
};

command_regex* create_command(command_regex* command);
command_regex* fill_commands(command_regex* command);
command_regex* insert_command(command_regex** head, command_regex* command);
bool execute_command(std::string &command, sqlite3 *db, User &user);