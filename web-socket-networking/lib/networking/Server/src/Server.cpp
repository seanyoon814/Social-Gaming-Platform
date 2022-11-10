#include "Server.h"
#include <iostream>
#include <memory>
#include <limits>
#include <sstream>
#include <arpa/inet.h>
//TODO: Add connection to the main data class so we cannot create duplicates
//This can be in the form of a vector or unordered map
Server::Server(unsigned short p, char const* argv[])
{
    port = p;
    createSocket();
    checkAddressValidity(argv);
    bindSocket();
    setMasterFileDescriptor();
}
void Server::createSocket()
{   
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        std::cerr << "Socket creation failed." << std::endl;
        exit(EXIT_FAILURE);
    }
}
void Server::checkAddressValidity(char const* argv[])
{
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int addr = getaddrinfo(argv[2], argv[1], &hints, &servinfo);
    if(addr!=0)
    {
        std::cerr << "error in getaddrinfo: " << gai_strerror(addr) << std::endl;
        exit(EXIT_FAILURE);
    }
    for(p = servinfo; p != NULL; p = p->ai_next)
    {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) 
        {
            std::cerr << "Server name does not exist" << std::endl;
            continue;
        }
        break;
    }
    //case where user types in "localhost" as server ip
    char str[256];
    getnameinfo(servinfo->ai_addr, servinfo->ai_addrlen, str, sizeof(str), NULL, 0, NI_NUMERICHOST);
}
void Server::bindSocket()
{
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(bind(sockfd, (const struct sockaddr*)&addr, sizeof(addr)) < 0)
    {
        std::cerr << "Error: Failed to bind socket to server." << std::endl;
        exit(EXIT_FAILURE);
    }
    listen(sockfd, SOMAXCONN);
}
void Server::setMasterFileDescriptor()
{
    FD_ZERO(&master);
    FD_SET(sockfd, &master);
}
fd_set Server::getMaster()
{
    return master;
}
int Server::getSocket()
{
    return sockfd;
}
int Server::getNumClients()
{
    return numClients;
}
void Server::incrementClients()
{
    numClients++;
}
fd_set* Server::getMasterAddr()
{
    return &master;
}
int main(int argc, char const *argv[])
{
    if(argc!=3)
    {
        std::cerr << "Usage:\n ./server <port> <ip>\n" << std::endl;
        std::cerr << "Example:" << std::endl;
        std::cerr << "./server 3000 127.0.0.1\n" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::unique_ptr<Server> s (new Server(atoi(argv[1]), argv));
    bool running = true;
    int count = 0;
    //MAIN LOOP THAT RUNS FOR THE SERVER
    while(running)
    {
        //we create a copy since select is destructive
        fd_set copy = s.get()->getMaster();
        //inefficient, 'brute force'
        if(select(FD_SETSIZE, &copy, nullptr, nullptr, nullptr) <0)
        {
            break;
        }
        for (int i = 0; i < FD_SETSIZE; i++)
        {
            if(FD_ISSET(i, &copy))
            {
                //new client case
                if(i == s.get()->getSocket())
                {
                    int client = accept(s.get()->getSocket(), nullptr, nullptr);
                    FD_SET(client, &s.get()->master);
                    std::string welcomeMsg = "Welcome to the game room! Please type !help for available commands, or chat with your friends!\r\n";
				    send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
                    count++;
                }
                //case where its just a new message
                else
                {
                    char buf[4096];
                    int bytes = recv(i, buf, 4096, 0);
                    if(bytes<=0)
                    {
                        close(i);
                        std::cerr << "Client is no longer in the lobby" << std::endl;
                    }
                    else
                    {
                        //ADD SPECIFIC ROOM FLUSHING HERE  
                        //ADD COMMANDS HERE
                        // int n = s.get()->getNumClients();
                        for (int j = 0; j <FD_SETSIZE; j++)
                        {
                            if(FD_ISSET(j, &s.get()->master))
                            {
                                if(j!= s.get()->getSocket() && i!=j)
                                {
                                    std::ostringstream ss;
                                    ss << "SOCKET #" << i << ": " << buf << "\r\n";
                                    std::string strOut = ss.str();

                                    send(j, strOut.c_str(), strOut.size() + 1, 0);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    /* code */
    return 0;
}