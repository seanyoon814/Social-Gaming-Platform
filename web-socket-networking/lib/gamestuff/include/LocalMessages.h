#include "Rules.h"
#include "web-socket-networking/lib/multi-threaded_server/chat_client.cpp"
#include "web-socket-networking/lib/multi-threaded_server/chat_server.cpp"

class LocalMessage : public Rules{
    public:
        LocalMessage(std::string msg);
        void changeMessage(std::string msg);
        void runRule();
        void addClient(int socket);
    private:
        std::unordered_set<int> clients; //identify clients by socket
        std::string message;
};