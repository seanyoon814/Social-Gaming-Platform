#include "Foreach.h"
#include <algorithm>

Foreach::Foreach(std::vector<Rules *> ruleList)
{
    rules = ruleList;
}

Foreach::~Foreach()
{
}

std::vector<Rules*> Foreach::getRules()
{
    return rules;
}

void Foreach::runRule()
{
    //Eventually for each variable/list tp iterate over
    /*
    for(auto item:items)
    {
        std::for_each(rules.begin(), rules.end(), [](auto rule) {
            rule->runRule();
        });
    }
    */
    std::for_each(rules.begin(), rules.end(), [](auto rule) {
        rule->runRule();
    });
}

