#include <map>
#include <string>
using namespace std;

class PerPlayer {

public:
    PerPlayer(map<int, string>, pair<int, string>);

    //~PerPlayer();

    void removePlayer();

    int getPlayerID();

    string getPlayerName();

    void setCurrentScore(int currentScore);

    int getCurrentScore();

    void setHighScore(int highScore);

    int getHighscore();

private:
    int ID = 0;
    string name;
    int score = 0;
    int highscore = 0;
    map<int, string> players;
};