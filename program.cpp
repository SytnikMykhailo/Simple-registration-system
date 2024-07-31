#include <iostream>
#include "sqlite3.h"
#include "program.h"
#include "database_manip.h"
#include "data_manip.h"
#include <string>
#include <regex>


/*
    main logic of programm 
*/
void reg_system(const char* db_name){
    sqlite3 *db;
    if(FILE *f = fopen(db_name, "r")){
        open_db(db_name, &db);
    }else{
        open_db(db_name, &db);
        create_table(db);
    }

    //USER INTERFACE
    
    std::string user_data;
    std::cout << "Hello, User!" << std::endl;
    std::cout << "Welcome to simple registration system!" << std::endl;
    
    
    
    
    std::cout << "Enter your email and password to login divided by space" << std::endl;
    
    std::getline(std::cin, user_data);
    while(!validate_data_format(user_data)){ //  || !check_email(user_data) || !check_password(user_data)
        std::cout << "Invalid data. Please try again." << std::endl;
        std::getline(std::cin, user_data);
    }

    char *zErrMsg = nullptr;
    int rc = 0;
}