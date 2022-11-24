#pragma once

#include "Rules.h"

#include "chat_server.h"
#include <cstring>
#include <memory>
// #include "web-socket-networking/lib/multi-threaded_server/chat_client.cpp"
// #include "web-socket-networking/lib/multi-threaded_server/chat_server.cpp"

class LocalMessage : public Rules{
    public:
        //We need name to find the calling participant, thats why we need the name
        //send a message to one client
        LocalMessage(std::string msg, uint8_t id, std::shared_ptr<server> s);
        //send a message to multiple clients 
        LocalMessage(std::string msg, std::vector<uint8_t> id, std::shared_ptr<server> s);
        virtual ~LocalMessage();
        void changeMessage(std::string msg);
        void runRule();
        //id is the person you want to send a local message to
        void runRule(uint8_t id);
        void addParticipants(uint8_t newID);
        std::shared_ptr<participant> findCallingParticipant(std::string name);
    private:
        //vector of ID's to send a message to
        std::vector<uint8_t> idVector;
        std::array<char, MAX_IP_PACK_SIZE> message;
        std::shared_ptr<server> serv;
};