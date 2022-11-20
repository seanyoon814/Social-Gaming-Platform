#include "LocalMessages.h"
#include <sstream>
#include <thread>
struct choices{
    std::vector<std::string> choices;
};
enum InputStatus{
    INPUT,
    FINISHED
};
enum MessageResult{
    SUCCESS,
    FAILURE,
    TIMEOUT
};
class InputInterface: public Rules{
    public:
        InputInterface();
        std::string getResult();
        virtual void runRule();
    protected:
        void getAnswer();
        //calling client
        std::shared_ptr<participant> callingClient;
        //id of the client you want to call
        uint8_t id;
        std::array<char, MAX_IP_PACK_SIZE> prompt;
        std::string result;
        std::shared_ptr<server> serv;
        int timeout = -1;
        InputStatus status;
        std::shared_ptr<participant> findCallingParticipant(std::string name);
};
class InputChoice: public InputInterface{
    public:
        InputChoice(std::string msg, std::string name, uint8_t id, std::string &result, choices c, std::shared_ptr<server> s);
        InputChoice(std::string msg, std::string name, uint8_t id, std::string &result, choices c, unsigned int duration, std::shared_ptr<server> s);
        std::string getResult();
        virtual void runRule();
        std::string formatString();
    private:
        void getAnswer();
        choices choice;
};

class InputText : public InputInterface{
    public:
        //the prompt, name of calling client, id of the client to send the prompt, result to store the string, and pointer to the server
        InputText(std::string msg, std::string name, uint8_t id, std::string &result, std::shared_ptr<server> s);
        InputText(std::string msg, std::string name, uint8_t id, std::string &result, unsigned int duration, std::shared_ptr<server> s);
        std::string getResult();
        virtual void runRule();
    private:
        void getAnswer();
};

class InputVote: public InputInterface{
    public:
        InputVote(std::string msg, std::string name, std::vector<uint8_t> id, std::unordered_map<int, int> &result, choices c, std::shared_ptr<server> s);
        InputVote(std::string msg, std::string name, std::vector<uint8_t> id, std::unordered_map<int, int> &result, choices c, unsigned int duration, std::shared_ptr<server> s);
        std::unordered_map<int, int> getResult();
        std::string formatString();
        virtual void runRule();
    private:
        std::vector<uint8_t> idVector;
        void getAnswer(std::unordered_map<int, int> &result);
        choices choice;
        unordered_map<int, int> values;
};