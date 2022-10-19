#include <map>
#include <string>
#include "Variables.h"

Variables::Variables(std::map<std::string, Data> variables)
{
    this->variables = variables;
}

Data Variables::getVariable(std::string name)
{
    typename std::map<std::string, Data>::iterator itr;
    itr = variables.find(name);
    return itr->second;
}

void Variables::addVariable(std::string name, Data value)
{
    variables.insert({name, value});
}

void Variables::removeVariable(std::string name)
{
    variables.erase(name);
}

int Variables::getSize()
{
    return variables.size();
}
