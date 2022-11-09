#include "When.h"
#include <algorithm>


When::When(std::pair<bool, std::vector<Rules*>> rules_)
{
    rules = rules_;
}

When::~When()
{
}

void When::runRule()
{
    //if rules.first.evalcond()?
    if (rules.first)
    {
        std::for_each(rules.second.begin(), rules.second.end(), [](auto rule) {
            rule->runRule();
        });
    }
    
}