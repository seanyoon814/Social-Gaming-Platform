#include <map>
#include <string>
#include "Constant.h"

Constant::Constant(std::map<std::string, std::any> constant)
{
    this->constant = constant;
}

std::any Constant::getConstant(std::string name)
{
    typename std::map<std::string, std::any>::iterator itr;
    itr = constant.find(name);
    return itr->second;
}

void Constant::addConstant(std::string name, std::any value)
{
    constant.insert({name, value});
}

int Constant::getSize()
{
    return constant.size();
}
