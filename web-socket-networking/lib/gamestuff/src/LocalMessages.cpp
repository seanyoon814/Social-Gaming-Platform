#include "LocalMessages.h"
LocalMessage::LocalMessage(std::array<char, MAX_IP_PACK_SIZE> &msg, std::vector<std::shared_ptr<participant>> &client, std::shared_ptr<server> &s)
{
    message = msg;
    clients = client;
    serv = s;
}
void LocalMessage::addClient(std::shared_ptr<participant> &p)
{
    clients.push_back(p);
}
void LocalMessage::runRule()
{
    for(auto client : clients)
    {
        //TODO: Filter out clients using Client ID
        //i.e.:
        //if(client.get().ID == id)
        // {
        //     serv.get()->room_.broadcast(message, client);
        // }
        serv.get()->room_.broadcast(message, client);
    }
}

void LocalMessage::changeMessage(std::array<char, MAX_IP_PACK_SIZE> msg)
{
    message = msg;
}