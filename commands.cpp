#include <iostream>
#include <regex>
#include "commands.h"
#include <iterator>
#include <string_view>

command_regex* create_command(std::string_view command, std::string_view description){
    command_regex* temp = new command_regex;
    temp->next = nullptr;
    std::regex self_regex(command.data(), std::regex_constants::ECMAScript | std::regex_constants::icase);
    temp->command_reg = self_regex;
    temp->description = description;
    return temp;
}

command_regex* insert_command(command_regex** head, command_regex* command){
    if(head == nullptr){
        return command;
    }
    
    command_regex* temp = *head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = command;
    return *head;
}

command_regex* fill_commands(command_regex** command){
    (*command) = insert_command(command, create_command("^(\\s*)(REGISTER)(\\s*)(\\w+)@(\\w+)(\\s*)(\\w+)\\$", "registers new account, type your email end password\"REGister john@developer.com johndeveloper\""));
    (*command) = insert_command(command, create_command("^(\\s*)(SIGN UP)(\\s*)(\\w+)@(\\w+)(\\s*)(\\w+)\\$", "signs you up, type your email end password\"SigN Up john@developer.com johndeveloper\""));
    (*command) = insert_command(command, create_command("^(\\s*)(SIGN OFF)(\\s*)\\$", "signs you off, type \"SigN oFF\""));
    (*command) = insert_command(command, create_command("^(\\s*)(HELP)(\\s*)\\$", "prints all available commands type \"HelP\""));
    return (*command);
}




bool execute_command(std::string &command, sqlite3 *db, User &user){
    

    //SIGN UP

    if(std::regex_search(command, ))
    //REGISTER
    std::regex self_regex("");

    //SIGN OFF

    //CHANGE PERSONAL DATA 

    //ACCEPT

    //CANCEL

    //SHOW USERS(ADMIN)

    //DELET USER(ADMIN)

    //CHANGE USER DATA(ADMIN)

    //NOTIFY USER

    //CHECK LOGS

    //HELP
}