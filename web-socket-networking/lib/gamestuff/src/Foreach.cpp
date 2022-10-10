#include "Foreach.h"

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
        for(auto const& rule: rules)
        {
            rule->runRule();
        }
    }
    */
    for(auto const& rule: rules)
    {
        rule->runRule();
    }
}

