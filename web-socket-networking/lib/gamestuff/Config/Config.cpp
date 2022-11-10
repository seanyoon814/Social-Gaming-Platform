#include "Config.h"
#include "nlohmann/json.hpp"
#include <iostream>
// #include "Parser.h"
using json = nlohmann::json;
Config::Config(json j)
{
    setJSON(j);
}
void Config::setJSON(json j)
{
    jsonMap = j;
}
void Config::setGameSetup()
{
    int numRounds = jsonMap["setup"]["Rounds"].get<int>();
    setup.rounds = numRounds;
}
void Config::setMin() noexcept
{
    int minPlayers = jsonMap["player count"]["min"].get<int>();
    min = minPlayers;
}
void Config::setMax() noexcept
{
    int maxPlayers = jsonMap["player count"]["max"].get<int>();
    max = maxPlayers;
}
void Config::setName() noexcept
{
    std::string gameName = jsonMap["name"].get<std::string>();
    name = gameName;
}
void Config::setAudience() noexcept
{
    bool hasAudience = jsonMap["audience"].get<bool>();
    audience = hasAudience;
}
GameSetup Config::getSetup() noexcept
{
    return setup;
}
json Config::getJSON() const
{
    return jsonMap;
}
std::string Config::getName()
{
    return name;
}
// //these two must run 
bool Config::assertJSON()
{
    //checking if the keys actually exist in the JSON config
    if(!jsonMap.contains("name") 
    || !jsonMap.contains("player count") 
    || !jsonMap.contains("audience") 
    || !jsonMap.contains("setup")) 
    {
        return false;
    }
    json playerCount = jsonMap["player count"];
    if(!playerCount.contains("max") || !playerCount.contains("min"))
    {
        return false;
    }
    if(jsonMap["name"].get<std::string>() != "" 
    && jsonMap["player count"]["max"].get<int>() >= 0
    && jsonMap["player count"]["min"].get<int>() >= 0
    && jsonMap["player count"]["min"].get<int>() <= jsonMap["player count"]["max"].get<int>()
    && (jsonMap["audience"].get<bool>() == true 
    || jsonMap["audience"].get<bool>()  == false))
    {
        return true;
    }
    return false;
    //since setup does not need to have any attributes
}
bool Config::checkSetupParameters()
{
    return jsonMap["setup"].empty();
}
void Config::setVariables()
{
    setMin();
    setMax();
    setName();
    setAudience();
    if(!checkSetupParameters())
    {
        setGameSetup();
    }
}

