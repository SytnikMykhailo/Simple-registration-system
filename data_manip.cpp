#include "data_manip.h"


bool validate_data_format(std::string& user_data){
    size_t found_space = user_data.find(" ");
    if(found_space != std::string::npos){
        if(user_data.find(" ", found_space + 1) == std::string::npos){
            return true;
        }
    }
    
    return false;
}