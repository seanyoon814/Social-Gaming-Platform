#include <map>
#include <string>
#include "include/Constant.h"

Constant::Constant(std::map<std::string, Data> constant)
{
    this->constant = constant;
}

Data Constant::getConstant(std::string name)
{
    typename std::map<std::string, Data>::iterator itr;
    itr = constant.find(name);
    return itr->second;
}

void Constant::addConstant(std::string name, Data value)
{
    constant.insert({name, value});
}

int Constant::getSize()
{
    return constant.size();
}
