#include <iostream>
#include <winsock2.h>
#include "errors/errors.h"
#include <signal.h>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

SOCKET socket_fd;

void handle_signal(int signum) {
    closesocket(socket_fd);
    WSACleanup();
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
    if(argc != 2){
        error("Wrong number of arguments", 10);
    }
    WSAData wsaData;
    WORD wVersionRequested;

    wVersionRequested = MAKEWORD(2, 2);    
    int err = WSAStartup(wVersionRequested, &wsaData);
    if(err != 0){
        error("Error initializing wisock dll", 10);
    }

    int port = atoi(argv[1]);
    if(port < 1024 || port > 49151){
        WSACleanup();
        error("Wrong port number", 10);
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd == INVALID_SOCKET){
        WSACleanup();
        error("Error creating spcket", 10);
    }
    u_long mode = 1;
    ioctlsocket(socket_fd, FIONBIO, &mode);

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
    std::vector<SOCKET> client_sockets; 
    fd_set readfds;

    while(1){
        FD_ZERO(&readfds);
        FD_SET(socket_fd, &readfds);

        if(FD_ISSET(socket_fd, &readfds)){
            SOCKET client_socket = accept(socket_fd, NULL, NULL);
            if(client_socket == INVALID_SOCKET){
                std::cerr << "Error accepting client" << std::endl;
            }else{
                ioctlsocket(client_socket, FIONBIO, &mode);
                std::cout << "New client added" << std::endl;
                client_sockets.push_back(client_socket);
            }
        }

        for(SOCKET socket : client_sockets){
            FD_SET(socket, &readfds);
        }

        if(select(0, &readfds, NULL, NULL, NULL) == SOCKET_ERROR){
            WSACleanup();
            error("Select error", 10);
        }
        
    }

    WSACleanup();
    return 0;
}
