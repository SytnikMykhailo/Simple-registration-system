#include <iostream>
#include <regex>
#include "commands.h"
#include <iterator>

command_regex* create_command(const std::string &command){
    command_regex* temp = new command_regex;
    temp->next = nullptr;
    std::regex self_regex(command, std::regex_constants::ECMAScript | std::regex_constants::icase);
    temp->command_reg = self_regex;
    return temp;
}

command_regex* insert_commands(command_regex** head, command_regex* command){
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

command_regex* fill_commands(command_regex* command){

}



bool execute_command(std::string &command, sqlite3 *db, User &user){
    //REGISTER, SIGN UP
    std::regex self_regex("");

    //SIGN OFF

    //CHANGE PERSONAL DATA 

    //CANCEL

    //SHOW USERS(ADMIN)

    //DELET USER(ADMIN)

    //CHANGE USER DATA(ADMIN)

    //NOTIFY USER

    //CHECK LOGS

}