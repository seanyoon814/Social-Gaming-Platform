// #include "include/Config.h"
#include "Config.h"
namespace std{

Config::Config(Json::Value json)
{
    setJSON(json);
}
void Config::setJSON(Json::Value j)
{
    val = j;
}
void Config::setGameSetup()
{
    json["setup"]["Rounds"] = val["setup"]["Rounds"];
    setup.rounds = json["setup"]["Rounds"].asInt();
}
void Config::setMin() noexcept
{
    json["player count"]["min"] = val["player count"]["min"];
    min = val["player count"]["min"].asInt();
}
void Config::setMax() noexcept
{
    json["player count"]["max"] = val["player count"]["max"];
    max = json["player count"]["max"].asInt();
}
void Config::setName() noexcept
{
    json["name"] = val["name"];
    name = json["name"].asString();
}
void Config::setAudience() noexcept
{
    json["audience"] = val["audience"];
    audience = json["audience"].asBool();
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
string Config::getName()
{
    return name;
}
//these two must run 
bool Config::assertJSON()
{
    //checking if the keys actually exist in the JSON config
    for (auto const& val : json)
    {
        //if the key exists in JSON file
        if(count(attributes.begin(), attributes.end(), val.first) == 0)
        {
            return false;
        }
    }
    if(json["name"].asString() != "" 
    && json["player count"]["max"].asInt() >= 0
    && json["player count"]["min"].asInt() >= 0
    && json["player count"]["min"].asInt() <= json["player count"]["max"].asInt()
    && (json["audience"].asBool() == true 
    || json["audience"].asBool() == false))
    {
        return true;
    }
    return false;
    //since setup does not need to have any attributes
}

void Config::setVariables()
{
    setMin();
    setMax();
    setName();
    setAudience();
    setGameSetup();
}
}
