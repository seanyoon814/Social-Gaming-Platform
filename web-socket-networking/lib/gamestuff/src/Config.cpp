#include "Config.h"
namespace std{

Config::Config(map<string, string> json_values)
{
    setJSON();
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
//these two must run 
bool Config::assertJSON()
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
    assert(atoi(json_values['min']) != 0);
    assert(atoi(json_values['min']) >= 0);
    assert(atoi(json_values['max']) != 0);
    assert(atoi(json_values['min']) <= atoi(json_values['max']));
    assert(json_values['audience'] == 'false' || json_values['audience'] == 'true');
    //since setup does not need to have any attributes
    try
    {
        assert(atoi(json_values['setup']['Rounds']) !=0);
        hasSetup = true;
        return true;
    }
    catch()
    {
        hasSetup = false;
        return true;
    }
}

void Config::setVariables()
{
    map<string, string> json_values = getJSON();
    changeName(json_values['name']);
    changeMin(json_values['min']);
    changeMax(json_values['max']);
    if(json_values['audience'] == 'true')
    {
        changeAudience(true);
    }
    else
    {
        changeAudience(false);
    }
    if(hasSetup == true)
    {
        setup.rounds = json_values['Rounds'];
    }
}
}