#include "InputText.h"

InputText::InputText(shared_ptr<server> &server, shared_ptr<participant> &callingClients, shared_ptr<participant> &participant, std::array<char, MAX_IP_PACK_SIZE> msg)
{
    serv = server;
    client = participant;
    prompt = msg;
    callingClient = callingClients;
}
InputText::InputText(shared_ptr<server> &server, shared_ptr<participant> &callingClients, shared_ptr<participant> &participant, std::array<char, MAX_IP_PACK_SIZE> msg, double tm)
{
    serv = server;
    client = participant;
    prompt = msg;
    callingClient = callingClients;
    timeout = tm;
}
std::string InputText::getResult()
{
    return result.data();
}
void InputText::runRule()
{
    std::vector<shared_ptr<participant>> v;
    v.push_back(client);
    if(timeout!=-1.0)
    {
        //first send the prompt
        std::unique_ptr<LocalMessage> l (new LocalMessage(prompt, v, serv));
        l.get()->runRule();
        //afterwards, wait a certain amount of time   
        std::chrono::seconds timeout(timeout);
        // std::future<std::string> future = std::async(getAnswer);
    }
    else
    {
        std::unique_ptr<LocalMessage> l (new LocalMessage(prompt, v, serv));
        l.get()->runRule();
    }
}