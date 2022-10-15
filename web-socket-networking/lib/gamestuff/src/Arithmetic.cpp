#include "Arithmetic.h"

std::vector<Rules> Add:getRules()
{
    return rules;
}

void Add::add(std::string to, int value)
{
    std::vector<Rules> r = getRules();
    for(auto rule : r)
    {
        //TODO: how to get rule name and rule value? 

        // if(rule.name == to)
        // {
        //     rule.value+=value;
        // }
    }
}

std::vector<Rules> Numerical::getRules()
{
    return list;
}

void Numerical::upfrom(int n)
{

}

