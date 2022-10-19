#include "Rules.h"
#include <list>

class Parallelfor: public virtual Rules {
    private:
        std::vector<Rules> rules;
        std::list<int> list;
    public:
        Parallelfor(std::vector<Rules> rules, List list);

        std::vector<Rules> getRules();

        std::list getList();

        void runRule();

};