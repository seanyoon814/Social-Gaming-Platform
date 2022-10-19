#include <map>
#include <string>
#include <ostream>
#include <list>
#include "Data.h"

// Data
std::ostream &operator<<(std::ostream &out, const Data &data)
{
    return data.output(out);
}

// String
StringObj::StringObj(const std::string &value) : value(value) {}

std::string StringObj::getValue() const
{
    return value;
}

std::ostream &StringObj::output(std::ostream &out) const
{
    return Data::output(out) << "\tValue: " << getValue() << "], ";
}

// Integer
IntObj::IntObj(const int &value) : value(value) {}

int IntObj::getValue() const
{
    return value;
}

// std::ostream &IntObj::output(std::ostream &out) const
// {
//     return Data::output(out) << "\tValue: " << getValue() << "], ";
// }

// Float
FloatObj::FloatObj(const float &value) : value(value) {}

float FloatObj::getValue() const
{
    return value;
}

// std::ostream &FloatObj::output(std::ostream &out) const
// {
//     return Data::output(out) << "\tValue: " << getValue() << "], ";
// }

// Boolean
BoolObj::BoolObj(const bool &value) : value(value) {}

bool BoolObj::getValue() const
{
    return value;
}

// std::ostream &BoolObj::output(std::ostream &out) const
// {
//     return Data::output(out) << "\tValue: " << getValue() << "], ";
// }

// Map
MapObj::MapObj(const std::map<Data, Data> &value) : value(value) {}

std::map<Data, Data> MapObj::getValue() const
{
    return value;
}

// List
ListObj::ListObj(const std::list<Data> &value) : value(value) {}

std::list<Data> ListObj::getValue() const
{
    return value;
}
