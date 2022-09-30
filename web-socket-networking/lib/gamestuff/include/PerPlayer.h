#include <map>
#include <string>
using namespace std;

class PerPlayer {

public:
    PerPlayer(map<int, string>, pair<int, string>);

    ~PerPlayer();

    void removePlayer();

    int getPlayerID();

    string getPlayerName();

    int getScore();

private:
    int ID;
    string name;
    int score;
    map<int, string> players;
};