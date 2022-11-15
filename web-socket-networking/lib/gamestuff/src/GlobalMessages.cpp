#include "GlobalMessages.h"
GlobalMessage::GlobalMessage(std::array<char, MAX_IP_PACK_SIZE> &msg, std::vector<std::shared_ptr<participant>> &client, std::shared_ptr<server> &s)
{
    message = msg;
    clients = client;
    serv = s;
}
void GlobalMessage::addClient(std::shared_ptr<participant> &p)
{
    clients.push_back(p);
}
void GlobalMessage::runRule()
{
    for(auto client : clients)
    {
        //is broadcast the correct way to send a message to clients?
        serv.get()->room_.broadcast(message, client);
    }
}

void GlobalMessage::changeMessage(std::array<char, MAX_IP_PACK_SIZE> msg)
{
    message = msg;
}