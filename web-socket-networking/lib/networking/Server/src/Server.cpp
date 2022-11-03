#include "Server.h"
//TODO: Add connection to the main data class so we cannot create duplicates
//This can be in the form of a vector or unordered map
Server::Server(unsigned short port, Connection other)
{
    createSocket();
}
int Server::createSocket()
{   
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0)
    {
        std::cerr << "Socket creation failed." << std::endl;
        return -1;
    }
    return 1;
}
bool Server::checkAddressValidity(char const* argv[])
{
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int addr = getaddrinfo(argv[2], argv[1], &hints, &servinfo);
    if(addr!=0)
    {
        std::cerr << "error in getaddrinfo: " << gai_strerror(addr) << std::endl;
        return false;
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
// int Server::bind()
// {
//     addr.sin_addr
// }

int main(int argc, char const *argv[])
{
    if(argc!=4)
    {
        std::cerr << "Usage:\n ./lets-talk <unique_code> <ip> <unique_code>\n" << std::endl;
        std::cerr << "Examples:" << std::endl;
        std::cerr << " ./lets-talk 3000 127.0.0.1 3001\n" << std::endl;
        exit(EXIT_FAILURE);
    }
    /* code */
    return 0;
}
