#include "Switch.h"

Switch::Switch(std::vector<std::pair<T,std::vector<Rules>>> c, std::vector<Constant>* list l){
    cases = c;
    list = l;
}
~Switch::Switch(){}
void Switch::runRule(){
    //Loops through cases and execute the set of rules of first match, should function same as a switch
    for(T c:cases){
        if(value==c.first()){
            for(auto r:c.second()){
                std::cout << "Run rules";
                r.runRule();
            }
            break;
        }
    }
}
