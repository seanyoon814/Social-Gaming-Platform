#include <any>
#include <map>
#include <string>

class Variable
{
public:
    // Constructor
    Variable(std::map<std::string, std::any> variables);
    // Get a specific variable value
    std::any getVariable(std::string name);
    // Add a variable
    void addVariable(std::string name, std::any value);
    // Remove a variable
    void removeVariable(std::string name);
    // Get size of variable map
    int getSize();

private:
    std::map<std::string, std::any> variables;
};