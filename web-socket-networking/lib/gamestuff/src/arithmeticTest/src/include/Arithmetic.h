//#include "Rules.h"
//#include "Variables.h"
//#include "../Data/include/Data.h"
#include<vector>
#include<string>
//temporary variable until joined together with Variable.h
struct Vars {
    int numb;
};
class Add {
    public:
        std::vector<Vars> getVariables();
        //void add(std::string name, int value);
        void add(Vars name, int value);
    private:
        std::vector<Vars> variables;
};

class Numerical {
    public:
        Numerical(int n);
        std::vector<int> upfrom(int n);
        std::vector<Vars> getRules(); 
    private:
        int start;
        std::vector<Vars> list;
};