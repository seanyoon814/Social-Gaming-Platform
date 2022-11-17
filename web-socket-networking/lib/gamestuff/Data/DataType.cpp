#include "DataType.h"

void DataTypes::addToDataMap(std::string type, std::map<std::string, std::vector<std::map<Data, Data>>> map)
{
    dataMap.insert(std::make_pair(type, map));
};

bool DataTypes::contains(std::map<Data, Data> map, std::string string)
{
    std::map<Data, Data>::iterator it;
    it = map.find(StringObj(string));
    if (it != map.end())
    {
        return true;
    }
    return false;
};

int DataTypes::getSize(std::map<Data, Data> map)
{
    return map.size();
};

// need to make parameter string structs
std::vector<std::map<Data, Data>> DataTypes::elements(std::string type, std::string toSearch)
{
    std::vector<std::map<Data, Data>> elements;
    std::map<std::string, std::map<std::string, std::vector<std::map<Data, Data>>>>::iterator it;
    it = dataMap.find(type);
    if (it == dataMap.end())
    {
        return elements;
    }
    std::map<std::string, std::vector<std::map<Data, Data>>> typeMap = it->second;
    std::map<std::string, std::vector<std::map<Data, Data>>>::iterator iter;
    iter = typeMap.find(toSearch);
    if (iter == typeMap.end())
    {
        return elements;
    }
    elements = iter->second;
    return elements;
};