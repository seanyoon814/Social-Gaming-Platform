#include "include/Config.h"
namespace std{

Config::Config(map<string, Json::Value> json_values)
{
    setJSON(json_values);
}
Config::~Config()
{
    delete this;
}
void Config::createGameSetup(GameSetup gameSetup, int numRounds)
{
    setup.rounds = numRounds;
}
void Config::setJSON(map<string, Json::Value> json_values)
{
    json = json_values;
}
void Config::changeMin(int newMin) noexcept
{
    min = newMin;
}
void Config::changeMax(int newMax) noexcept
{
    max = newMax;
}
void Config::changeName(string newName) noexcept
{
    name = newName;
}
void Config::changeAudience(bool newAudience) noexcept
{
    audience = newAudience;
}
GameSetup Config::getSetup() noexcept
{
    return setup;
}
void Config::setSetup(bool n)
{
    hasSetup = n;
}
map<string, Json::Value> Config::getJSON() const
{
    return json;
}
//these two must run 
bool Config::assertJSON() const
{
    map<string, Json::Value> json_values = getJSON();
    // for (auto const& val : json_values)
    // {
    //     //if the key exists in JSON file
    //     if(count(attributes.begin(), attributes.end(), val.first) == 0)
    //     {
    //         return false;
    //     }
    // }
    assert(json_values["name"].asString() != "");
    assert(json_values["player count"]["min"].asInt() >= 0);
    assert(json_values["player count"]["max"].asInt() >= 0);
    assert(json_values["player count"]["min"].asInt() <= json_values["player count"]["max"].asInt());
    assert(json_values["audience"].asBool() == false || json_values["audience"].asBool() == true);
    return true;
    //since setup does not need to have any attributes
}

void Config::setVariables()
{
    map<string, Json::Value> json_values = getJSON(); 
    changeName(json_values["name"].asString());
    changeMin(json_values["player count"]["min"].asInt());
    changeMax(json_values["player count"]["max"].asInt());
    changeAudience(json_values["audience"].asBool());
    // if(hasSetup == true)
    // {
    //     setup.rounds = stoi(json_values["Rounds"]);
    // }
}
}