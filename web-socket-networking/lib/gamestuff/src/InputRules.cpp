#include "InputRules.h"
// INPUT INTERFACE //
std::shared_ptr<participant> InputInterface::findCallingParticipant(std::string name)
{
    return serv.get()->room_.name_table_reverse[name];
}

//INPUT CHOICE //

InputChoice::InputChoice(std::string msg, std::string name, uint8_t id, std::string &result, choices c, std::shared_ptr<server> s)
{
    strcpy(prompt.data(), msg.c_str());
    this->id = id;
    this->result = result;
    serv = s;
    callingClient = findCallingParticipant(name);
    choice = c;
}   
InputChoice::InputChoice(std::string msg, std::string name, uint8_t id, std::string &result, choices c, unsigned int duration, std::shared_ptr<server> s)
{
    strcpy(prompt.data(), msg.c_str());
    this->id = id;
    this->result = result;
    serv = s;
    callingClient = findCallingParticipant(name);
    timeout = duration;
    choice = c;
}
//returns string to be "1. [choice 1] \n 2. [choice 2] etc"
std::string InputChoice::formatString()
{
    int i = 0;
    std::stringstream ss;
    std::string ret;
    for(auto prompt : choice.choices)
    {
        ss << i << ". ";
        ss << prompt << "\n";
    }
    ss << "Please type in an index to configure your answer \n";
    ret = ss.str();
    return ret;
}
std::string InputChoice::getResult()
{
    return result;
}
void InputChoice::getAnswer()
{
    //for now, it asks for input from all users
    //need to figure out how to get input from just specified user
    std::array<char, MAX_IP_PACK_SIZE> ans;
    std::cin >> ans.data();
    result = ans.data();
}
void InputChoice::runRule()
{
    if(timeout!=-1)
    {   
        std::string choice = formatString();
        strcat(prompt.data(), choice.c_str());
        std::stringstream ss;
        ss << timeout;
        strcat(prompt.data(), "\n\nYou have ");
        strcat(prompt.data(), ss.str().c_str());
        strcat(prompt.data(), " seconds to reply");
        std::unique_ptr<LocalMessage> l (new LocalMessage(prompt.data(), callingClient, id, serv));
        l.get()->runRule(id);
        //afterwards, wait a certain amount of time   
        thread getInput(getAnswer);
        this_thread::sleep_for(std::chrono::seconds((int)timeout));
        if(!result.empty())
        {
            return;
        }
    }
    else
    {
        std::unique_ptr<LocalMessage> l (new LocalMessage(prompt.data(), callingClient, id, serv));
        l.get()->runRule(id);
        getAnswer();
    }
}

// INPUT TEXT //

InputText::InputText(std::string msg, std::string name, uint8_t id, std::string &result, std::shared_ptr<server> s)
{
    strcpy(prompt.data(), msg.c_str());
    this->id = id;
    this->result = result;
    serv = s;
    callingClient = findCallingParticipant(name);
}
InputText::InputText(std::string msg, std::string name, uint8_t id, std::string &result, unsigned int tm, std::shared_ptr<server> s)
{
    strcpy(prompt.data(), msg.c_str());
    this->id = id;
    this->result = result;
    serv = s;
    callingClient = findCallingParticipant(name);
    timeout = tm;
}
std::string InputText::getResult()
{
    return result;
}
void InputText::getAnswer()
{
    //for now, it asks for input from all users
    //need to figure out how to get input from just specified user
    std::array<char, MAX_IP_PACK_SIZE> ans;
    std::cin >> ans.data();
    result = ans.data();
}
void InputText::runRule()
{
    //if there is a timeout
    if(timeout!=-1)
    {
        std::stringstream ss;
        ss << timeout;
        strcat(prompt.data(), "\n\nYou have ");
        strcat(prompt.data(), ss.str().c_str());
        strcat(prompt.data(), " seconds to reply");
        //first send the prompt
        std::unique_ptr<LocalMessage> l (new LocalMessage(prompt.data(), callingClient, id, serv));
        l.get()->runRule(id);
        //afterwards, wait a certain amount of time   
        thread getInput(getAnswer);
        this_thread::sleep_for(std::chrono::seconds((int)timeout));
        if(!result.empty())
        {
            return;
        }
    }
    //no timeout
    else
    {
        std::unique_ptr<LocalMessage> l (new LocalMessage(prompt.data(), callingClient, id, serv));
        l.get()->runRule(id);
        getAnswer();
    }
}

// INPUT VOTE // 

InputVote::InputVote(std::string msg, std::string name, std::vector<uint8_t> id, std::unordered_map<int, int> &result, choices c, std::shared_ptr<server> s)
{
    strcpy(prompt.data(), msg.c_str());
    this->idVector = id;
    this->values = result;
    serv = s;
    callingClient = findCallingParticipant(name);
}
InputVote::InputVote(std::string msg, std::string name, std::vector<uint8_t> id, std::unordered_map<int, int> &result, choices c, unsigned int duration, std::shared_ptr<server> s)
{
    strcpy(prompt.data(), msg.c_str());
    this->idVector = id;
    this->values = result;
    serv = s;
    timeout = duration;
    callingClient = findCallingParticipant(name);
}
std::unordered_map<int, int> InputVote::getResult()
{
    return values;
}
void InputVote::getAnswer(std::unordered_map<int, int> &result)
{
    //for now, it asks for input from all users
    //need to figure out how to get input from just specified user
    std::array<char, MAX_IP_PACK_SIZE> ans;
    std::cin >> ans.data();
    int indexNum = stoi(ans.data());
    result[indexNum]++;
}
std::string InputVote::formatString()
{
    int i = 0;
    std::stringstream ss;
    std::string ret;
    for(auto prompt : choice.choices)
    {
        ss << i << ". ";
        ss << prompt << "\n";
    }
    ss << "Please type in an index to configure your answer \n";
    ret = ss.str();
    return ret;
}
void InputVote::runRule()
{
    if(timeout!=-1)
    {   
        std::string choice = formatString();
        strcat(prompt.data(), choice.c_str());
        std::stringstream ss;
        ss << timeout;
        strcat(prompt.data(), "\n\nYou have ");
        strcat(prompt.data(), ss.str().c_str());
        strcat(prompt.data(), " seconds to reply");
        std::unique_ptr<LocalMessage> l (new LocalMessage(prompt.data(), callingClient, idVector, serv));
        l.get()->runRule(id);
        //afterwards, wait a certain amount of time   
        thread getInput(getAnswer, values);
        this_thread::sleep_for(std::chrono::seconds((int)timeout));
        if(!result.empty())
        {
            return;
        }
    }
    //no timeout
    else
    {
        std::unique_ptr<LocalMessage> l (new LocalMessage(prompt.data(), callingClient, idVector, serv));
        l.get()->runRule(id);
        getAnswer(values);
    }
}