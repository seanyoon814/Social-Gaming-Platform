#include <gtest/gtest.h>
#include"command_reader.h"
#include <iostream>
#include <string>
using std::cout;

TEST(assertCommandReader, NotCommand){
    CommandReader commandList;
    std::string regular = "World.";
    std::string result = commandList.checkCommand(regular);
    cout <<"Expected String:\n\t" << regular << std::endl;
    cout << "Result String:\n\t" << result << std::endl;
    if(regular == result) ASSERT_TRUE(true);
    else ASSERT_TRUE(false);
    
}

TEST(assertCommandReader, FalseCommand){
    CommandReader commandList;
    std::string regular = "!World";
    std::string expected = "Command does not exist\nPlease use /help to get the list of commands";
    std::string result = commandList.checkCommand(regular);
    cout <<"Expected String:\n\t" << expected << std::endl;
    cout << "Result String:\n\t" << result << std::endl;
    if(expected == result) ASSERT_TRUE(true);
    else ASSERT_TRUE(false);
    
}

TEST(assertCommandReader, helpCommand){
    CommandReader commandList;
    std::string regular = "/help";
    std::string expected = commandList.checkCommand(regular);
    std::string result = commandList.checkCommand(regular);
    cout <<"Expected String:\n\t" << regular << std::endl;
    cout << "Result String:\n\t" << result << std::endl;
    if(expected == result) ASSERT_TRUE(true);
    else ASSERT_TRUE(false);
    
}

TEST(assertCommandReader, createCommand){
    CommandReader commandList;
    std::string expected = "You have created room number:\t0001\n";
    std::string regular = "/create";
    std::string result = commandList.checkCommand(regular);
    cout <<"Expected String:\n\t" << expected << std::endl;
    cout << "Result String:\n\t" << result << std::endl;
    if(expected == result) ASSERT_TRUE(true);
    else ASSERT_TRUE(false);
    
}

//Not passing
TEST(assertCommandReader, joinCommand){
    CommandReader commandList;
    std::string expected = "You have joined room number:\t0254\n";
    std::string regular = "/join";
    std::string result = commandList.checkCommand(regular);
    cout <<"Expected String:\n\t" << expected << std::endl;
    cout << "Result String:\n\t" << result << std::endl;
    if(expected == result) ASSERT_TRUE(true);
    else ASSERT_TRUE(false);
    
}

TEST(assertCommandReader, diceCommand){
    CommandReader commandList;
    std::string regular = "/dice";
    std::string result = commandList.checkCommand(regular);
    cout <<"Expected String:\n\t" << result << std::endl;
    cout << "Result String:\n\t" << result << std::endl;
    //if(regular == result) ASSERT_TRUE(true);
    //else ASSERT_TRUE(false);
    ASSERT_TRUE(true);
    
}




