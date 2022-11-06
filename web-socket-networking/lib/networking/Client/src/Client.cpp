#include "Client.h"
#include <iostream>
#include <memory>
#include <limits>
#include <sstream>
Client::Client(std::string n, unsigned int p)
{
    name = n;
    port = p;
    createSocket();
    connectIP();
    connectToServer();
}
void Client::createSocket()
{   
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        std::cerr << "Socket creation failed." << std::endl;
        exit(EXIT_FAILURE);
    }
}
void Client::connectIP()
{
    std::string ipAddr = "127.0.0.1";
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    int n = inet_pton(AF_INET, ipAddr.c_str(), &addr.sin_addr);
    if(n == -1)
    {
        std::cerr << "Error: Invalid address family" << std::endl;
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    else if(n == 0)
    {
        std::cerr << "Error: Invalid IP" << std::endl;
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}
void Client::connectToServer()
{
    int connection = connect(sockfd, (const struct sockaddr*)&addr, sizeof(addr));
    if(connection == -1)
    {
        std::cerr << "Error: Failure to connect to server" << std::endl;
        perror("socket");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
}
int Client::getSocket()
{
    return sockfd;
}
int main(int argc, char const *argv[])
{
    if(argc!=3)
    {
        std::cerr << "Usage:\n ./client <port> <name>\n" << std::endl;
        std::cerr << "Example:" << std::endl;
        std::cerr << "./client Sean 3000\n" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::unique_ptr<Client> c (new Client("Sean", atoi(argv[1])));
    char buf[4096];
    std::string input;
    bool connected = true;
    while(connected)
    {
        std::cout << "> ";
		getline(std::cin, input);
        if(input.size() > 0)
		{
			// Send the text
			int sendResult = send(c.get()->getSocket(), input.c_str(), input.size() + 1, 0);
			if (sendResult != -1)
			{
				// Wait for response
				int bytesReceived = recv(c.get()->getSocket(), buf, 4096, 0);
				if (bytesReceived >= 0)
				{
					std::cout << "SERVER> " << std::string(buf, 0, bytesReceived) << std::endl;
				}
			}
		}

    }
    return 0;
}
