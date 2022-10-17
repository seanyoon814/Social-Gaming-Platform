#include <map>
#include <string>
#include "Variables.h"

Variable::Variable(std::map<std::string, std::any> variables)
{
    this->variables = variables;
}

std::any Variable::getVariable(std::string name)
{
    typename std::map<std::string, std::any>::iterator itr;
    itr = variables.find(name);
    return itr->second;
}

void Variable::addVariable(std::string name, std::any value)
{
    variables.insert({name, value});
}

void Variable::removeVariable(std::string name)
{
    variables.erase(name);
}

int Variable::getSize()
{
    return variables.size();
}
