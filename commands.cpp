#include <iostream>
#include <regex>
#include "commands.h"
#include <iterator>
#include <string_view>

command_regex* create_command(const std::string &command, const std::string &descripttion){
    command_regex* temp = new command_regex;
    temp->next = nullptr;
    std::regex self_regex(command, std::regex_constants::ECMAScript | std::regex_constants::icase);
    temp->command_reg = self_regex;
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
    (*command) = insert_command(command, create_command("^(\\s*)(REGISTER)(\\s*)(\\w+)"));



    return (*command);
}



bool execute_command(std::string &command, sqlite3 *db, User &user){
    
    //SIGN UP
    
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

}