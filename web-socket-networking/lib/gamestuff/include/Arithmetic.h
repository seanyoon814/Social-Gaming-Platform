#include "Rules.h"

class Add: public virtual Rules{
    public:
        std::vector<Rules> getRules();
        void add(std::string to, int value);
    private:
        std::vector<Rules> rules;
};

class Numerical: public virtual Rules{
    public:
        void upfrom(int n);
        std::vector<Rules> getRules(); 
    private:
        std::vector<Rules> list;
};