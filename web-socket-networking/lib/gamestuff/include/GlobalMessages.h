#include "Rules.h"
#include "web-socket-networking/lib/multi-threaded_server/chat_client.cpp"
#include "web-socket-networking/lib/multi-threaded_server/chat_server.cpp"

class GlobalMessage : public Rules{
    public:
        GlobalMessage(std::array<char, MAX_IP_PACK_SIZE> &msg, std::vector<std::shared_ptr<client>> &client, std::shared_ptr<server> &s);
        void changeMessage(std::array<char, MAX_IP_PACK_SIZE> msg);
        void runRule();
        void addClient(std::shared_ptr<client> &p);
    private:
        std::vector<std::shared_ptr<client>> clients;
        std::array<char, MAX_IP_PACK_SIZE> message;
        std::shared_ptr<server> serv;
};