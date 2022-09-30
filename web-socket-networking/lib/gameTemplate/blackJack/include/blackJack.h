#include <vector>
#include "Game.h"
#include "Config.h"
#include "Rules.h"
#include "PerPlayer.h"
#include "PerAudience.h"
#include "Constant.h"

class BlackJack : public Game{
public:
    struct Card{
        string suit;
        string number;
    }

    BlackJack();
    BlackJack(int customPoints);

    int dealCards();

private:
    void initCards();
    std::vector<string> shuffledCards;
}