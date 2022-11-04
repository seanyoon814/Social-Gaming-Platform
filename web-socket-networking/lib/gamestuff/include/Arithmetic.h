#include "Rules.h"
#include "Variables.h"
#include "../Data/include/Data.h"
class Add: public virtual Rules{
    public:
        std::vector<Variables> getVariables();
        void add(std::string name, int value);
    private:
        std::vector<Variables> variables;
};

class Numerical: public virtual Rules{
    public:
        Numerical(int n);
        std::vector<Variables> upfrom(int n);
        std::vector<Variables> getRules(); 
    private:
        int start;
        std::vector<Variables> list;
};