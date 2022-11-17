#include "LocalMessages.h"
LocalMessage::LocalMessage(std::array<char, MAX_IP_PACK_SIZE> &msg, std::vector<std::shared_ptr<client>> &client, std::shared_ptr<server> &s)
{
    message = msg;
    clients = client;
    serv = s;
}
void LocalMessage::addClient(std::shared_ptr<client> &p)
{
    clients.push_back(p);
}
void LocalMessage::runRule()
{
    for(auto client : clients)
    {
        client.get()->write(message);
    }
}
void LocalMessage::runRule(uint8_t id)
{
    for(auto client : clients)
    {
        if(id == client.get()->getPlayerID())
        {
            client.get()->write(message);
        }
    }
}
void LocalMessage::changeMessage(std::array<char, MAX_IP_PACK_SIZE> msg)
{
    message = msg;
}