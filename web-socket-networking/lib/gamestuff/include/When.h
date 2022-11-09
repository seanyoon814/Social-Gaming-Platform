#include "Rules.h"


class When: public virtual Rules
{
    private:
        //Pair of condition and list of rules
        //Might need to change bool arg to a custom Condition class based off prof recommendation
        std::pair<bool, std::vector<Rules*>> rules;
    public:
        When(std::pair<bool, std::vector<Rules*>> rules_);
        ~When();

        virtual void runRule();
};