#include "PerAudience.h"

PerAudience::PerAudience(bool requireAudience, int gameID) {
    this->requireAudience = requireAudience;
    this->gameID = gameID;
}

PerAudience::~PerAudience() {
    delete this;
}

void PerAudience::setAudienceSize(int size) {
    this->size = size;
}

int PerAudience::getAudienceSize() {
    return this->size;
}

void PerAudience::setAudieceSide(std::string side) {
    this->side = side;
}

std::string PerAudience::getAudienceSide() {
    return this->side;
}