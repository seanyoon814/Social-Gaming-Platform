#include <cstring>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind/bind.hpp>
using namespace boost::asio;
using namespace boost::asio::ip;

struct Connection {
    uintptr_t id;
    std::string code;
    bool operator==(Connection other);
};

//acts as a "lobby"
class Server{
  public:
    Server(unsigned short port, char const* argv[]);
    void createSocket();
    void bindSocket();
    void checkAddressValidity(char const* argv[]);
    void setMasterFileDescriptor();
    void parseCommand();
    fd_set getMaster();
    fd_set* getMasterAddr();
    int getSocket();
    int getNumClients();
    void incrementClients();
    //TODO: Add connection to the main data class so we cannot create duplicates
    //This can be in the form of a vector or unordered map
    bool checkExistingPort(std::vector<uintptr_t> ips, uintptr_t id);
    fd_set master;
  private:
    //file descriptor which corresponds to a network connection
    //reading and writing is done here
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    //stores server address
    struct sockaddr_in addr;
    //master set
    int port;
    //unique identifier 
    Connection c;
    int numClients = 0;
    //using profs suggestion of finding commands
    std::unordered_map<std::string, std::string> commands = 
    {{"!help", "help"}};
    
    //f
};

class Lobby : public Server{
  public:
    Lobby(Connection c);
    void startGame();
  private:
    uintptr_t id;
};

class DiceGame : public Lobby{

};
