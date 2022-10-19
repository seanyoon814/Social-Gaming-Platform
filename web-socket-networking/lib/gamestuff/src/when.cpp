#include "when.h"
#include <algorithm>


when::when(std::pair<bool, std::vector<Rules*>> rules_)
{
    rules = rules_;
}

when::~when()
{
}

void when::runRule()
{
    //if rules.first.evalcond()?
    if (rules.first)
    {
        std::for_each(rules.second.begin(), rules.second.end(), [](auto rule) {
            rule->runRule();
        });
    }
    
}