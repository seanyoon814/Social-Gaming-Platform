#include "GlobalMessages.h"
GlobalMessage::GlobalMessage(std::array<char, MAX_IP_PACK_SIZE> &msg, std::vector<std::shared_ptr<client>> &client, std::shared_ptr<server> &s)
{
    message = msg;
    clients = client;
    serv = s;
}
void GlobalMessage::addClient(std::shared_ptr<client> &p)
{
    clients.push_back(p);
}
void GlobalMessage::runRule()
{
    for(auto client : clients)
    {
        //is broadcast the correct way to send a message to clients?
        client.get()->write(message);
    }
}
void GlobalMessage::changeMessage(std::array<char, MAX_IP_PACK_SIZE> msg)
{
    message = msg;
}