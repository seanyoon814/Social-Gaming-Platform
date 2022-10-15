#include "Config.h"
namespace std{

Config::Config(map<string, string> json_values)
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
void Config::setJSON(map<string, string> json_values)
{
    json = json_values;
}
void Config::changeMin(int newMin)
{
    min = newMin;
}
void Config::changeMax(int newMax)
{
    max = newMax;
}
void Config::changeAudience(bool newAudience)
{
    audience = newAudience;
}
GameSetup Config::getSetup()
{
    return setup;
}
void Config::setSetup(bool n)
{
    hasSetup = n;
}
//these two must run 
bool Config::assertJSON() const
{
    map<string, string> json_values = getJSON();
    for (auto const& val : json_values)
    {
        //if the key exists in JSON file
        if(count(attributes.begin(), attributes.end(), val.first) == 0)
        {
            return false;
        }
    }
    assert(stoi(json_values["min"]) != 0);
    assert(stoi(json_values["min"]) >= 0);
    assert(stoi(json_values["max"]) != 0);
    assert(stoi(json_values["min"]) <= stoi(json_values["max"]));
    assert(json_values["audience"] == "false" || json_values["audience"] == "true");
    return true;
    //since setup does not need to have any attributes
}

void Config::setVariables()
{
    map<string, string> json_values = getJSON(); 
    changeName(json_values["name"]);
    changeMin(stoi(json_values["min"]));
    changeMax(stoi(json_values["max"]));
    if(json_values["audience"] == "true")
    {
        changeAudience(true);
    }
    else
    {
        changeAudience(false);
    }
    if(hasSetup == true)
    {
        setup.rounds = stoi(json_values["Rounds"]);
    }
}
}