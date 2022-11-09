#include "command_reader.h"
#include <cstring>
#include <string>
#include <algorithm>
//#include <iostream>
//must decouple this into handler and list
//Will map the commands to functions
CommandReader::CommandReader() {
    commandslist.push_back("help");
    commandslist.push_back("create");
    commandslist.push_back("join");
    commandslist.push_back("quit");
    commandslist.push_back("dice");
}

std::string CommandReader::checkCommand(std::string message) {
    std::string outputMsg;
    std::string command;
    if(message[0] == '/' || message[0] == '!') {
        command = message.substr(1, message.size()-1);
        outputMsg = callCommand(command);
        return outputMsg;
    }
    return message;
}

std::string CommandReader::callCommand(std::string command) {
    std::string outMsg;
    //return command;
    if(std::find(commandslist.begin(), commandslist.end(), command) == commandslist.end()) {
        outMsg =  "Command does not exist\nPlease use /help to get the list of commands";
        return outMsg;
    }
    if(command == "help") {
        outMsg = helpCommand();
    } else if(command == "create") {
        outMsg = createCommand();
    } else if(command == "join") {
        outMsg = joinCommand(0254);
    } else if(command == "dice") {
        outMsg = diceCommand();
    } else if(command == "quit") {
        quitCommand();
    }
    return outMsg;
}

std::string CommandReader::helpCommand() {
    std::string outMsg;
    outMsg = "The list of commands:\n";
    for(auto coms : commandslist) {
        outMsg += "\t\t\t";
        outMsg += coms;
        outMsg += "\n";
    }
    return outMsg;
}

std::string CommandReader::joinCommand(int roomID) {
    //Call function to join the server
    //Replace 'You' with user's name/id
    //Need to add room numbers
    std::string joinMsg = "You have joined room number:\t";
    joinMsg += std::to_string(roomID);
    joinMsg += "\n";
    return joinMsg;
}

std::string CommandReader::createCommand() {
    //Call fucntion to create the server
    //Replace 'You' with user's name/id
    std::string joinMsg = "You have created room number:\t0001\n";
    //joinMsg += "0001"; //Will use as message for now
    //joinMsg += "\n";
    return joinMsg;
}

std::string CommandReader::diceCommand() {
    //Roll a dice
    std::string diceMsg;
    int roll = 1 + (std::rand()% 6);

    diceMsg = "You have rolled " + std::to_string(roll) + "\n";
    return diceMsg;
}

void CommandReader::quitCommand() {
    //Calls function to quit server
}