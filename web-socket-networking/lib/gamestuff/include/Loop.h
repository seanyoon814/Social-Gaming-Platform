#pragma once
#include "Rules.h"
#include <vector>
/*Place holder condition template*/
template <class T>
struct Condition
{
 static T (*pfunction)();
};

//Currently the loop uses a boolean value as it's condition
//Need to figure out how to pass in an actual condition -- maybe some type of generic function pointer(generic functor?), above template as concept
class Loop: public virtual Rules{
    public:
        Loop(bool &c, std::vector<Rules> r);
        ~Loop();
        void runRule();
        std::vector<Rules> getRules();
    
    private:
        std::vector<Rules> rules;
        bool cond;
        //for future implementation
        Condition c;
    
};
