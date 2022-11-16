#include "Foreach.h"
#include <algorithm>

Foreach::Foreach(const std::vector<Rules *>& ruleList, const ListObj& list_)
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
    std::for_each(list.getValue().begin(), list.getValue().end(), [](auto element)
    {
        std::for_each(rules.begin(), rules.end(), [](auto rule) {
            rule->runRule();
        })
    });
}

