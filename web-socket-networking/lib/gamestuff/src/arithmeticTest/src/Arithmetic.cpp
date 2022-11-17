#include "Arithmetic.h"
std::vector<Vars> Add::getVariables()
{
    return variables;
}

void Add::add(Vars name, int value)
{
    std::vector<Vars> v = getVariables();

    for(auto rule : v)
    {
        name.numb = name.numb + value;
        //This is not how add functions VVV  
        // if(rule.getVariable(name) == name)
        // {
        //     //rule.addVariable(name, value);
        //     rule.getVariable(name) = 
        // }
    }
}
std::vector<Vars> Numerical::getRules()
{
    return list;
}
Numerical::Numerical(int n)
{
    start = n;
}
std::vector<int> Numerical::upfrom(int n)
{
    std::vector<int> v;
    if(n >start)
    {
        return v;
    }
    for(int i = n; i<=start; i++)
    {
        v.push_back(i);
        //std::map<std::string, Data> map;
        //Data d;
        //Need to figure out how to set data to correct val? Constructor requires a data object but all attributes are inherited from Data.h?
        
        // map[std::to_string(i)] = d;
        // Vars v(map);
        // v.push_back(v);
    }
    return v;
}