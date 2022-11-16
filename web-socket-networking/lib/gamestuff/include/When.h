#include "Rules.h"
#include "Data.h"

struct Cases 
{
    BoolObj* condition;
    std::vector<Rules*> rules;
};

class When: public virtual Rules
{
    private:
        //Pair of condition and list of rules
        //Might need to change bool arg to a custom Condition class based off prof recommendation
        std::vector<Cases> caseList;
    public:
        When(std::vector<Cases> caseList);

        virtual void runRule();
};