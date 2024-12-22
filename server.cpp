#include <iostream>
#include <winsock2.h>
#include "errors/errors.h"
#include <signal.h>

int socket_fd;

void handle_signal(int signum) {
    closesocket(socket_fd);
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
    if(argc != 2){
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    int port = atoi(argv[1]);
    if(port < 1024 || port > 49151){
        std::cout << "Wrong port number" << std::endl;
        return 1;
    }
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == -1){
        error("Error creating spcket", 1);
    }
    struct sockaddr_in server_adress;
    server_adress.sin_family = AF_INET;
    server_adress.sin_port = htons(port);
    server_adress.sin_addr.s_addr = INADDR_ANY;
    if(bind(socket_fd, (struct sockaddr*)&server_adress, sizeof(server_adress)) == -1){
        error("Error binding socket", 10);
    }

    if(listen(socket_fd, 10) == -1){
        error("Error listening socket", 10);
    }
    signal(SIGTERM, handle_signal);
    
    while(1){
        
    }
    return 0;
}
