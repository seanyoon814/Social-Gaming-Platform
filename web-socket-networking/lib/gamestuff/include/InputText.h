#include "LocalMessages.h"
#include <thread>
class InputText : public Rules{
    public:
        InputText(shared_ptr<server> &serv, shared_ptr<client> &callingClient, shared_ptr<client> &client, std::array<char, MAX_IP_PACK_SIZE> msg);
        InputText(shared_ptr<server> &serv, shared_ptr<client> &callingClient, shared_ptr<client> &client, std::array<char, MAX_IP_PACK_SIZE> msg, double duration);
        std::string getResult();
        virtual void runRule();
    private:
        void getAnswer();
        std::shared_ptr<server> serv;
        std::shared_ptr<client> to;
        std::shared_ptr<client> from;
        std::array<char, MAX_IP_PACK_SIZE> prompt;
        std::string result;
        double timeout = -1.0;
};

class InputChoice: public Rules{

};

class InputVote: public Rules{

};