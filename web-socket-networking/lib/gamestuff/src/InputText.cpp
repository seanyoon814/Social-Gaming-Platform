#include "InputText.h"

InputText::InputText(shared_ptr<server> &server, shared_ptr<client> &callingClients, shared_ptr<client> &participant, std::array<char, MAX_IP_PACK_SIZE> msg)
{
    serv = server;
    to = participant;
    prompt = msg;
    from = callingClients;
}
InputText::InputText(shared_ptr<server> &server, shared_ptr<client> &callingClients, shared_ptr<client> &participant, std::array<char, MAX_IP_PACK_SIZE> msg, double tm)
{
    serv = server;
    to = participant;
    prompt = msg;
    from = callingClients;
    timeout = tm;
}
std::string InputText::getResult()
{
    return result.data();
}
void InputText::getAnswer()
{
    std::vector<shared_ptr<client>> v;
    v.push_back(from);
    std::array<char, MAX_IP_PACK_SIZE> ans;
    std::cin >> ans.data();
    std::unique_ptr<LocalMessage> l (new LocalMessage(ans, v, serv));
    l.get()->runRule(from.get()->getPlayerID());
    result = ans.data();
}
void InputText::runRule()
{
    std::vector<shared_ptr<client>> v;
    v.push_back(to);
    if(timeout!=-1.0)
    {
        //first send the prompt
        std::unique_ptr<LocalMessage> l (new LocalMessage(prompt, v, serv));
        l.get()->runRule(to.get()->getPlayerID());
        //afterwards, wait a certain amount of time   
        thread getInput(getAnswer);
        this_thread::sleep_for(std::chrono::seconds((int)timeout));
        if(!result.empty())
        {
            //user put new input here
            return;
        }
    }
    else
    {
        std::unique_ptr<LocalMessage> l (new LocalMessage(prompt, v, serv));
        l.get()->runRule();
    }
}