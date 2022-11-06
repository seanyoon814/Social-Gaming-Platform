#include "DataType.h"

void DataTypes::addToDataMap(std::string type, std::map<Data, Data> map)
{
    dataMap.insert(std::make_pair(type, map));
};
