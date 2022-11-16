#include "LocalMessages.h"
#include <chrono>
class InputText : public Rules{
    public:
        InputText(shared_ptr<server> &serv, shared_ptr<participant> &callingClient, shared_ptr<participant> &client, std::array<char, MAX_IP_PACK_SIZE> msg);
        InputText(shared_ptr<server> &serv, shared_ptr<participant> &callingClient, shared_ptr<participant> &client, std::array<char, MAX_IP_PACK_SIZE> msg, double duration);
        std::string getResult();
        virtual void runRule();
    private:
        std::shared_ptr<server> serv;
        std::shared_ptr<participant> client;
        std::shared_ptr<participant> callingClient;
        std::array<char, MAX_IP_PACK_SIZE> prompt;
        std::string result;
        double timeout = -1.0;
};

class InputChoice: public Rules{

};

class InputVote: public Rules{

};