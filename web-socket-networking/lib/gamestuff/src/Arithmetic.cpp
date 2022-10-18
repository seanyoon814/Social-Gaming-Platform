#include "Arithmetic.h"

std::vector<Variables> Add::getVariables()
{
    return variables;
}

void Add::add(std::string name, int value)
{
    std::vector<Variables> v = getVariables();
    for(auto rule : v)
    {
        if(rule.getVariable(name) == name)
        {
            rule.addVariable(name, value);
        }
    }
}
std::vector<Variables> Numerical::getRules()
{
    return list;
}
Numerical::Numerical(int n)
{
    start = n;
}
std::vector<Variables> Numerical::upfrom(int n)
{
    std::vector<Variables> v;
    if(n<= start)
    {
        return;
    }
    for(int i = n; i<start; i++)
    {
        std::map<std::string, Data> map;
        Data d;
        //Need to figure out how to set data to correct val? Constructor requires a data object but all attributes are inherited from Data.h?
        map[std::to_string(i)] = d;
        Variables v(map);
        v.push_back(v);
    }
    return v;
}