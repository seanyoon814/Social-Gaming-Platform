#include <iostream>

#include "Rules.h"
#include "PerPlayer.h"

class Message : public Rules {
    private:
        //list of players
        std::vector<PerPlayer> players;
        //Value
        std::string val;
    public:
        Message(std::vector<PerPlayer> playersList, std::string value);
        ~Message();
        std::vector<PerPlayer> getPlayers();
        virtual void runRule();
};

class Globalmessage : public Rules {
    private:
    //Value
    std::string val;
    public:
        Globalmessage(std::string value);
        ~Globalmessage();
        virtual void runRule();
};