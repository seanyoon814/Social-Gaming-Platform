#include "Loop.h"


Loop::Loop(bool &c,std::vector<Rules> r)
{
    cond = c;
    rules =r;
}

void Loop::runRule(){
    while(c){
        //std::cout << "test";
        for(auto rule: rules)
            {
                rule.runRule();
            }
    }
}

std::vector<Rules> getRules(){
    return rules;
}
