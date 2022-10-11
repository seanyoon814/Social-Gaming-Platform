#include <vector>
#include <string>
#include <map>
#include <cassert>
#include <algorithm>
#include <stdlib.h>
#define defaultRounds 10;

namespace std{

    struct GameSetup{
        //number of rounds
        int rounds = defaultRounds;
    };

    class Config{
    public:
        //Config constructor
        Config(map<string, string> json_values);
        //Destructor
        ~Config();
        //Create the game setup. Not creating game setup will result in default rounds of 10.
        void createGameSetup(GameSetup gameSetup, int numRounds);
        //Change the min number of players
        void changeMin(int newMin) noexcept;
        //Change the max number of players
        void changeMax(int newMax) noexcept;
        //change the name of the game
        void changeName(string newName) noexcept;
        void changeAudience(bool newAudience) noexcept;
        void setJSON(map<string, string> json_values);
        map<string, string> getJSON() const;
        //return game setup struct
        GameSetup getSetup()noexcept;
        //Assert the things in the json
        bool assertJSON() const;
        //set values from JSON file into Config class
        void setVariables();
        //set setup bool variable
        void setSetup(bool n);
    private:
        //Name of the game
        map<string, string> json;
        //
        vector<string> attributes = {"name", "player count", "audience", "setup", "min", "max", "audience", "setup"};

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
};
}