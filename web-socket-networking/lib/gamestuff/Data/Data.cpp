#include <map>
#include <string>
#include <ostream>
#include <list>
#include <unordered_map>
#include "Data.h"

//// Data
//std::ostream &operator<<(std::ostream &out, const Data &data)
//{
//    return data.output(out);
//}
//
//// String
StringObj::StringObj(const std::string &value) : value(value) {}

std::string StringObj::getValue() const
{
    return value;
}

//std::ostream &StringObj::output(std::ostream &out) const
//{
//    return Data::output(out) << "\tValue: " << getValue() << "], ";
//}

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
MapObj::MapObj(std::unordered_map<string, shared_ptr<Data>> value) : value(std::move(value)) {}

unordered_map<string, shared_ptr<Data>> MapObj::getValue() const
{
    return value;
}

// List
VectorObj::VectorObj(std::vector<shared_ptr<Data>> value) : value(value) {}

std::vector<shared_ptr<Data>> VectorObj::getValue() const
{
    return value;
}
