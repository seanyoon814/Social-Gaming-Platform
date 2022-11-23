#include "LocalMessages.h"
LocalMessage::~LocalMessage()
{

}
LocalMessage::LocalMessage(std::string msg, uint8_t id, std::shared_ptr<server> s)
{
    memset(message.data(), '\0', message.size());
    strcpy(message.data(), msg.c_str());
    idVector.push_back(id);
    serv = s;
}
LocalMessage::LocalMessage(std::string msg, std::vector<uint8_t> id, std::shared_ptr<server> s)
{
    memset(message.data(), '\0', message.size());
    strcpy(message.data(), msg.c_str());
    idVector = id;
    serv = s;
}
std::shared_ptr<participant> LocalMessage::findCallingParticipant(std::string name)
{
    return serv.get()->room_.name_table_reverse[name];
}
void LocalMessage::addParticipants(uint8_t newID)
{
    idVector.push_back(newID);
}
void LocalMessage::runRule()
{
    for(auto iden : idVector)
    {
        //run the overloaded broadcast method
        serv.get()->room_.broadcast(message, iden);
    }
}
void LocalMessage::changeMessage(std::string msg)
{
    memset(message.data(), '\0', message.size());
    strcpy(message.data(), msg.c_str());
}