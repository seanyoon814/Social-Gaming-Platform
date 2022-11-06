#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>
class Client{
    public:
        Client(std::string n, unsigned int p);
        void createSocket();
        void connectIP();
        void connectToServer();
        int getSocket();

    private:
        std::string name;
        int wins = 0;
        int losses = 0;
        int clientSocket;
        struct sockaddr_in addr;
        int sockfd;
        unsigned int port;
};