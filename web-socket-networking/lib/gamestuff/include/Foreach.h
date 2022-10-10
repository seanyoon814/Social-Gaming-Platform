#include "Rules.h"


class Foreach: public virtual Rules {
    private:
        //List or Value to iterate over (still confused by how to do this)

        //Element name for list element object within the rules below (still confused by how to do this)
        //List of rules to run 
        std::vector<Rules*> rules;
    public:
        Foreach(/* smt for Lists, smt for element, */ std::vector<Rules*> ruleList);
        ~Foreach();
        std::vector<Rules*> getRules();
        
        virtual void runRule();
};
