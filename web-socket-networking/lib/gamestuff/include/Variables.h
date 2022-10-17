#include <map>
#include <string>
#include "Data.h"

class Variables
{
public:
    // Constructor
    Variables(std::map<std::string, Data> variables);
    // Get a specific variable value
    Data getVariable(std::string name);
    // Add a variable
    void addVariable(std::string name, Data value);
    // Remove a variable
    void removeVariable(std::string name);
    // Get size of variable map
    int getSize();

private:
    std::map<std::string, Data> variables;
};