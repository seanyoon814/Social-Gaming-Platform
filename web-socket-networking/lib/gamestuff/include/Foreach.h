#include "Rules.h"
#include "Data.h"

class Foreach: public virtual Rules {
    private:
        //List or Value to iterate over (still confused by how to do this)
        std::vector<Data*> list;
        //Element name for list element object within the rules below (still confused by how to do this)
        //List of rules to run 
        std::vector<Rules*> rules;
    public:
        Foreach(const std::vector<Rules*>& ruleList, const std::vector<Data*> list_);
        ~Foreach();
        std::vector<Rules*> getRules();
        
        virtual void runRule();
};
