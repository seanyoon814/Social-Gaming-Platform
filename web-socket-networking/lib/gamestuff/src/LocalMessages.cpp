#include "LocalMessages.h"
LocalMessage::LocalMessage(std::string msg, std::shared_ptr<participant> p, uint8_t id, std::shared_ptr<server> s)
{
    memset(message.data(), '\0', message.size());
    strcpy(message.data(), msg.c_str());
    idVector.push_back(id);
    serv = s;
    this->client = p;
}
LocalMessage::LocalMessage(std::string msg, std::shared_ptr<participant> p, std::vector<uint8_t> id, std::shared_ptr<server> s)
{
    memset(message.data(), '\0', message.size());
    strcpy(message.data(), msg.c_str());
    idVector = id;
    serv = s;
    this->client = p;
}
std::shared_ptr<participant> LocalMessage::findCallingParticipant(std::string name)
{
    return serv.get()->room_.name_table_reverse[name];
}
void LocalMessage::addParticipants(uint8_t newID)
{
    idVector.push_back(newID);
}
//Run to ALL clients (basically a global message)
void LocalMessage::runRule()
{
    serv.get()->room_.broadcast(message, client);
}
//Run to SPECIFIC CLIENT IDs
void LocalMessage::runRule(uint8_t id)
{
    for(auto iden : idVector)
    {
        //run the overloaded broadcast method
        serv.get()->room_.broadcast(message, client, iden);
    }
}
void LocalMessage::changeMessage(std::string msg)
{
    memset(message.data(), '\0', message.size());
    strcpy(message.data(), msg.c_str());
}