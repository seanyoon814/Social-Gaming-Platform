#include<vector>
#include<string>
#include <map>
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>
using namespace std;

class Rules{
    public:
        virtual void runRule() = 0;
};


//Per Player
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

//Messages
class Message : public Rules {
    private:
        //list of players
        std::vector<PerPlayer> players;
        //Value
        std::string val;
    public:
        Message(std::vector<PerPlayer> playersList, std::string value);
        ~Message();
        virtual void runRule();
};
Message::Message(std::vector<PerPlayer> playersList, std::string value)
{
    players = playersList;
    val = value;
}

Message::~Message(){}

void Message::runRule()
{
    //Eventually sends to each players screen
    for(auto player: players)
    {
        std::cout << "Message for player: " << player.getPlayerName() << " Message: " << val << std::endl;
    }
}

class Globalmessage : public Rules {
    private:
    //Value
    std::string val;
    public:
        Globalmessage(std::string value);
        ~Globalmessage();
        virtual void runRule();
};

Globalmessage::Globalmessage(std::string value)
{
    val = value;
}

Globalmessage::~Globalmessage(){}

void Globalmessage::runRule()
{
    //Eventually sends to main screen for everyone to see
    cout << "Message for Everyone: " << val << endl;
}
//For each
class Foreach: public virtual Rules {
    private:
        //List

        //Element
        //List of rules
        std::vector<Rules*> rules;
    public:
        Foreach(/* smt for Lists, smt for element, */ std::vector<Rules*> ruleList);
        ~Foreach();
        
        virtual void runRule();
};

Foreach::Foreach(std::vector<Rules *> ruleList)
{
    rules = ruleList;
}

Foreach::~Foreach()
{
}

void Foreach::runRule()
{
    //Eventually for each variable/list tp iterate over
    std::for_each(rules.begin(), rules.end(), [](auto rule) {
        rule->runRule();
    });
}
//when
class when: public virtual Rules
{
    private:
        std::pair<bool, std::vector<Rules*>> rules;
    public:
        when(std::pair<bool, std::vector<Rules*>> rules_);
        ~when();

        virtual void runRule();
};

when::when(std::pair<bool, std::vector<Rules*>> rules_)
{
    rules = rules_;
}

when::~when()
{
}
//test
void when::runRule()
{
    if (rules.first == true)
    {
        std::for_each(rules.second.begin(), rules.second.end(), [](auto rule) {
            rule->runRule();
        });
    }
    
}

void messageNestedForEachTest()
{
    std::vector<Rules*> rules;
    rules.push_back(new Globalmessage("From Inner ForEach"));
    rules.push_back(new Globalmessage("From Inner ForEach 2"));
    rules.push_back(new Globalmessage("From Inner ForEach 3"));
    
    std::vector<Rules*> rules3;
    rules3.push_back(new Globalmessage("From Inner2 ForEach Pog"));
    rules3.push_back(new Globalmessage("From Inner2 ForEach Poggers"));
    Foreach* inner2 = new Foreach(rules3);
    rules.push_back(inner2);
    rules.push_back(new Globalmessage("From Inner ForEach 4"));
    Foreach* inner = new Foreach(rules);
    std::vector<Rules*> rules2;
    rules2.push_back(new Globalmessage("From Parent forEach"));
    rules2.push_back(inner);
    rules2.push_back(new Globalmessage("From parent forEach 2"));
    Foreach parent = Foreach(rules2);
    parent.runRule();
}

void whenRuleTest()
{
    std::vector<Rules*> testWhen;
    testWhen.push_back(new Globalmessage("Condition is True"));
    std::vector<int> x{2,4}; 
    std::vector<int>& xref = x;
    auto allEven = std::all_of(xref.begin(), xref.end(), [](auto num) {
        std::cout<< "num: " << num << std::endl;
        return num%2 == 0;
    });
    std::pair<bool&, std::vector<Rules*>> getPair{allEven, testWhen};
    when whenRule = when(getPair);
    whenRule.runRule();
    //Should do nothing. Need to find a way to reevaluate condition
    x.push_back(5);
    whenRule.runRule();
}

int main(int argc, char const *argv[])
{
    //Messages testing with multiple forEach rules nested together
    messageNestedForEachTest();
    //when clause
    whenRuleTest();
    
    return 0;
}

