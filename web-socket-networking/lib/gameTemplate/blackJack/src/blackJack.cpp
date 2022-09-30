#include <iostream>
#include <random>
#include <vector>
#include <string>
#include "Game.h"
#include "Config.h"
#include "Rules.h"
#include "PerPlayer.h"
#include "PerAudience.h"
#include "Constant.h"

class BlackJack : public Game{
public:
    BlackJack(){
        this.setConstant(Constant::Constant{"winPoints": 21});
        this.setRules(Rules::Rules{userPoints >= this.getConstant().getValue(winPoints)});

    }
    BlackJack(int customPoints){
        this.setConstant(Constant::Constant{"winPoints": customPoints});
        this.setRules(Rules::Rules{userPoints >= this.getConstant().getValue(winPoints)});
    }

    void initCards(){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(0,51);

        const string suits[] {"Spades", "Hearts", "Diamonds", "Club"};
        const string numbers[] {"2","3","4","5","6","7","8","9","10","11","J","Q","K","A"};

        std::vector<Card> cards;

        for(string suit: suits){
            for(string number : numbers){
                cards.push_back(Card{suit:suit, number:number});
            }
        }

        std::shuffle(std::begin(cards), std::end(cards), std::default_random_engine());
    }
}