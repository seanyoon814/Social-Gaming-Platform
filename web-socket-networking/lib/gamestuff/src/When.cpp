#include "When.h"
#include <algorithm>


When::When(std::vector<Cases> caseList_)
{
    caseList = caseList_;
}

When::~When()
{
}

void When::runRule()
{
    for(auto cases: caseList)
    {
        if (cases.condition->getValue())
        {
            for(auto rule: cases.rules)
            {
                rule->runRule();
            }
            break;
        }
        
    }
    
}