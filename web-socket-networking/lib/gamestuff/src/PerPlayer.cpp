#include <map>
#include <string>
using namespace std;

#include "PerPlayer.h"

PerPlayer::PerPlayer(map<int, string> players, pair<int, string> player) {
    this->ID = player.first;
    this->name = player.second;
    players.insert(player);
}

/*
PerPlayer::~PerPlayer() {
    delete this;
}
*/

void PerPlayer::removePlayer() {
    players.erase(players.find(ID));
}

int PerPlayer::getPlayerID() {
    return ID;
}

string PerPlayer::getPlayerName() {
    return name;
}

void PerPlayer::setCurrentScore(int currentScore) {
    score = currentScore;
}

int PerPlayer::getCurrentScore() {
    return score;
}

void PerPlayer::setHighScore(int highScore) {
    highscore = highScore;
}

int PerPlayer::getHighscore() {
    return highscore;
}