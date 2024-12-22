#include <iostream>

void error(const char *msg, int exit_code){
    std::cerr << msg << std::endl;
    exit(exit_code);
}