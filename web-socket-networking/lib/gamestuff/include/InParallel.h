#include "Rules.h"

class Inparallel: public virtual Rules {
    private:
        //stuff
        std::vector<Rules> rules;
    public:
        Inparallel(std::vector<Rules> rules);

        std::vector<Rules> getRules();

        void runRule();

};