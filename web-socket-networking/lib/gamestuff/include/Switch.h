#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include "Constant.h"
#include "Rules.h"

class Constant{};

template <class T>
class Switch: public virtual Rules{
    public:
        Switch(std::vector<std::pair<T,std::vector<Rules>>> c, std::vector<Constant>* list l);
        ~Switch();
        void runRule();
    private:
        T value;
        //Vector of case to rules
        std::vector<std::pair<T,std::vector<Rules>>> cases;
        //Allowable values validation not yet implemented
        std::vector<Constant>* list;  
};
