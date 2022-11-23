#include "GlobalMessages.h"
GlobalMessage::GlobalMessage(std::string msg, std::string name, std::shared_ptr<server> s)
{
    memset(message.data(), '\0', message.size());
    strcpy(message.data(), msg.c_str());
    client = findCallingParticipant(name);
    serv = s;
}
std::shared_ptr<participant> GlobalMessage::findCallingParticipant(std::string name)
{
    return serv.get()->room_.name_table_reverse[name];
}
void GlobalMessage::runRule()
{
    serv.get()->room_.broadcast(message);
}
void GlobalMessage::changeMessage(std::string msg)
{
    memset(message.data(), '\0', message.size());
    strcpy(message.data(), msg.c_str());
}