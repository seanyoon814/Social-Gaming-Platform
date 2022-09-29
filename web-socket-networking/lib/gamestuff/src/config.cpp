#include "config.h"

Config::Config(std::string gameName, int minPlayers, int maxPlayers, bool hasAudience)
{
    name = gameName;
    min = minPlayers;
    max = maxPlayers;
    hasAudience = audience;
}
Config::~Config()
{
    delete this;
}
void Config::createGameSetup(GameSetup gameSetup, int numRounds, std::vector<std::string> q, std::vector<std::string> a)
{
    gameSetup.rounds = numRounds;
}
void Config::changeMin(int newMin)
{
    min = newMin;
}
void Config::changeMax(int newMax)
{
    max = newMax;
}
void Config::addQuestionAnswer(GameSetup &obj, std::string question, std::string answer)
{
    obj.questions.push_back(question);
    obj.answers.push_back(answer);
}
GameSetup Config::getSetup()
{
    return setup;
}