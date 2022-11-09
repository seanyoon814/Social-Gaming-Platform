#include "Rules.h"
#include <list>

class Parallelfor: public virtual Rules {
    private:
        std::vector<Rules> rules;
        std::list<int> list;
    public:
        Parallelfor(std::vector<Rules> rules, std::list<int> list);

        std::vector<Rules> getRules();

        std::list<int> getList();

        void runRule();

};