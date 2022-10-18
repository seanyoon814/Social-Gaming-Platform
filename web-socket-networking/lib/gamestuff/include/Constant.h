#include <map>
#include <string>
#include <any>

// using type std::any to hold any type for the map
class Constant
{
public:
    // constructor
    Constant(std::map<std::string, std::any> constant);
    // Get a specific constant values
    std::any getConstant(std::string name);
    // Add a constant
    void addConstant(std::string name, std::any value);
    // Get size of constant map
    int getSize();

private:
    std::map<std::string, std::any> constant;
};