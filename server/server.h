#include <iostream>
#include <winsock2.h>
#include "../errors/errors.h"
#include <signal.h>
#include <vector>
#include "../database/database.h"

void handle_signal(int signal);

class Server{
public:
    Server();
    Server(int port, int addrlen, int opt, char *ip);
    void run();
    void setup();
    friend void handle_signal(int signal);
    ~Server();
private:
    Database db;
    SOCKET socket_fd;
    int port;
    struct sockaddr_in server_address;
    int addrlen;
    int opt;
    WSAData wsaData;
    WORD wVersionRequested;
    u_long mode;

};