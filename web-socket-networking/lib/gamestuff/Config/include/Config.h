#include <vector>
#include <string>
#include <map>
#include <cassert>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
// #include "Parser.h"
#include "nlohmann/json.hpp"
#define defaultRounds 10;
using json = nlohmann::json;
struct GameSetup{
    //number of rounds
    int rounds = defaultRounds;

    //FOR QUIZ GAME

    //Assume that every input for question will result in an input for answers
    //Also assume questions and answers will share the same index, i.e., question 1 will be 
    //located at questions[0], and the correpsonding answer will be at answers[0]
    std::vector<std::string> questions;
    std::vector<std::string> answers;
};

class Config{
    public:
        //Config constructor
        Config(json j);
        //Create the game setup. Not creating game setup will result in default rounds of 10.
        void setGameSetup();
        //Change the min number of players
        void setMin() noexcept;
        //Change the max number of players
        void setMax() noexcept;
        //change the name of the game
        void setName() noexcept;
        void setAudience() noexcept;
        void setJSON(json j);
        json getJSON() const;
        //return game setup struct
        GameSetup getSetup()noexcept;
        //Assert the things in the json
        bool assertJSON();
        //set values from JSON file into Config class
        void setVariables();
        //set setup
        void setSetup();
        int getMin();
        std::string getName();
        bool checkSetupParameters();
    private:
        //Name of the game
        std::vector<std::string> attributes = {"name", "player count", "audience", "setup", "min", "max", "audience"};
        std::string name;
        //Minimum number of players
        int min;
        //Maximum number of players
        int max;
        //If an audience is allowed
        bool audience;
        //Setup struct that contains rounds, quiz questions + answers, etc.
        //Will need to adjust this struct later according to type of game in a later iteration
        GameSetup setup;
        bool hasSetup;
        json jsonMap;
        //to get config
};

