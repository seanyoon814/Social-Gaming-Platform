#include<vector>
#include<string>

#define defaultRounds 10;

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
        Config(std::string gameName, int minPlayers, int maxPlayers, bool hasAudience);
        //Destructor
        ~Config();
        //Create the game setup. Not creating game setup will result in default rounds of 10.
        void createGameSetup(GameSetup gameSetup, int numRounds, std::vector<std::string> q, std::vector<std::string> a);
        //Change the min number of players
        void changeMin(int newMin);
        //Change the max number of players
        void changeMax(int max);
        //add a question and answer to the questions vector and answers vector in GameSetup setup variable.
        void addQuestionAnswer(GameSetup &obj, std::string question, std::string answer);
        //return game setup struct
        GameSetup getSetup();
    private:
        //Name of the game
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
};
