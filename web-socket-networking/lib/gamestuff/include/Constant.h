#include <map>
#include <string>
#include "Data.h"

class Constant
{
public:
    // constructor
    Constant(std::map<std::string, Data> constant);
    // Get a specific constant values
    Data getConstant(std::string name);
    // Add a constant
    void addConstant(std::string name, Data value);
    // Get size of constant map
    int getSize();

private:
    std::map<std::string, Data> constant;
};