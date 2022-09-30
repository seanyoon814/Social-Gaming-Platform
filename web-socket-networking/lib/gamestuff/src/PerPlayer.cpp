#include <map>
#include <string>
using namespace std;

#include "PerPlayer.h"

PerPlayer::PerPlayer(map<int, string> players, pair<int, string> player) {
    this->ID = player.first;
    this->name = player.second;
    players.insert(player);
}

PerPlayer::~PerPlayer() {
    delete this;
}

void PerPlayer::removePlayer() {
    this->players.erase(players.find(ID));
}

int PerPlayer::getPlayerID() {
    return ID;
}

string PerPlayer::getPlayerName() {
    return name;
}

int PerPlayer::getScore() {
    return score;
}