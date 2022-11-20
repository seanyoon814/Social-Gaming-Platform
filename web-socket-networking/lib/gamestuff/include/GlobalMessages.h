#include "Rules.h"
#include "web-socket-networking/lib/multi-threaded_server/chat_client.cpp"
#include "web-socket-networking/lib/multi-threaded_server/chat_server.cpp"

class GlobalMessage : public Rules{
    public:
        GlobalMessage(std::string msg, std::string name,  std::shared_ptr<server> s);
        void changeMessage(std::string msg);
        void runRule();
        std::shared_ptr<participant> findCallingParticipant(std::string name);
    private:
        std::shared_ptr<participant> client;
        std::array<char, MAX_IP_PACK_SIZE> message;
        std::shared_ptr<server> serv;
};