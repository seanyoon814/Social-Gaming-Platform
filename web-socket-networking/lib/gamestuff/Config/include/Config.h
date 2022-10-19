#include <vector>
#include <string>
#include <map>
#include <cassert>
#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>

#define defaultRounds 10;

namespace std{

    struct GameSetup{
        //number of rounds
        int rounds = defaultRounds;
    };

    class Config{
    public:
        //Config constructor
        Config(Json::Value json);
        //Create the game setup. Not creating game setup will result in default rounds of 10.
        void setGameSetup();
        //Change the min number of players
        void setMin() noexcept;
        //Change the max number of players
        void setMax() noexcept;
        //change the name of the game
        void setName() noexcept;
        void setAudience() noexcept;
        void setJSON(Json::Value j);
        map<string, Json::Value> getJSON() const;
        //return game setup struct
        GameSetup getSetup()noexcept;
        //Assert the things in the json
        bool assertJSON();
        //set values from JSON file into Config class
        void setVariables();
        //set setup bool variable
        void setSetup(bool n);
        int getMin();
        map<string, Json::Value> json;
        string getName();
    private:
        //Name of the game
        vector<string> attributes = {"name", "player count", "audience", "setup", "min", "max", "audience"};
        string name;
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
        //to get config
        Json::Value val;
};
}
