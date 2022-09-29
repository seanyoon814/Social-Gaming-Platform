
#include "Game.h"

void setConfig(Config::Config c){
    this.config = c;
}
void setRules(Rules::Rules r){
    this.rules = r;
}
void setPerPlayer(PerPlayer::PerPlayer p){
    this.perPlayer = p;
}
void setPerAudience(PerAudience::PerAudience a){
    this.perAudience = a;
}
void setConstant(Constant::Constant constant){
    this.constant = constant;
}
        
Config::Config config(){
    return this.config;
}
Rules::Rules rules(){
    return this.rules;
}
PerPlayer::PerPlayer perPlayer(){
    return this.perPlayer;
}
PerAudience::PerAudience perAudience(){
    return this.perAudience;
}
Constant::Constant constant(){
    return this.constant;
}
