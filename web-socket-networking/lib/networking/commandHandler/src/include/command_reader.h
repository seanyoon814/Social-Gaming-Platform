#pragma once
#include<unordered_map>
#include<vector>
#include<string.h>
//#include<string.h>
class CommandReader {
public:
    // Optional implementation if I implement the search for a command via undordered_map
    CommandReader();
    //Read in the user's cpmmand
    std::string checkCommand(std::string );
    //Will contain the conditional function calls
    std::string callCommand(std::string);
    //Help command gives a list of commands
    std::string helpCommand();
    //Join command calls code from server to join room
    std::string joinCommand(int roomID);
    //Create command calls code from server to create the room
    std::string createCommand();
    //Dice command will return a dice roll between 1-6
    std::string diceCommand();
    //Quit will exit the server
    void quitCommand();
private:
    std::vector<std::string> commandslist;
};