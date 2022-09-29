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
        
Config::Config getConfig(){
    return this.config;
}
Rules::Rules getRules(){
    return this.rules;
}
PerPlayer::PerPlayer getPerPlayer(){
    return this.perPlayer;
}
PerAudience::PerAudience getPerAudience(){
    return this.perAudience;
}
Constant::Constant getConstant(){
    return this.constant;
}
