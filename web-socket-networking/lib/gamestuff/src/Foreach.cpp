#include "Foreach.h"
#include <algorithm>

Foreach::Foreach(const std::vector<Rules *>& ruleList, const std::vector<Data*> list_)
{
    rules = ruleList;
    list = list_;
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

