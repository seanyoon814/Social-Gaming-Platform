#include "Rules.h"


class when: public virtual Rules
{
    private:
        //Pair of condition and list of rules
        //Might need to change bool arg to a custom Condition class based off prof recommendation
        std::pair<bool, std::vector<Rules*>> rules;
    public:
        when(std::pair<bool, std::vector<Rules*>> rules_);
        ~when();

        virtual void runRule();
};