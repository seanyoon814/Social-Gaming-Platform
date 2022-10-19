#include "Messages.h"


Message::Message(std::vector<PerPlayer> playersList, std::string value)
{
    players = playersList;
    val = value;
}

Message::~Message(){}

std::vector<PerPlayer> Message::getPlayers()
{
    return players;
}

void Message::runRule()
{
    //Curently only prints message to terminal. Eventually will be changed
    //to spend it to each players screen with server implementation
    for(auto player: players)
    {
        std::cout << "Message for player: " << player.getPlayerName() << " Message: " << val << std::endl;
    }
}
//Global Messages
Globalmessage::Globalmessage(std::string value)
{
    val = value;
}

Globalmessage::~Globalmessage(){}

void Globalmessage::runRule()
{
    //Curently only prints message to terminal. Eventually will be changed
    //to spend it to the main screen with server implementation
    cout << "Message for Everyone: " << val << endl;
}