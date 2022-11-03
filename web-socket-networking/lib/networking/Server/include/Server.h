#include <iostream>
#include <cstring>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <vector>
#include <stdio.h>
//Credit: https://www.youtube.com/watch?v=dquxuXeZXgo

struct Connection {
  uintptr_t id;
  std::string code;
  bool operator==(Connection other);
};

//acts as a "lobby"
class Server{
    public:
        Server(unsigned short port, Connection other);
        int createSocket();
        int bind();
        void parseCommand();
        bool checkAddressValidity(char const* argv[]);
        //TODO: Add connection to the main data class so we cannot create duplicates
        //This can be in the form of a vector or unordered map
        bool checkExistingPort(std::vector<uintptr_t> ips, uintptr_t id);
    private:
        int sockfd;
        struct addrinfo hints, *servinfo, *p;
        //stores server address
        struct sockaddr_in addr;
        //unique identifier 
        Connection c;
};

