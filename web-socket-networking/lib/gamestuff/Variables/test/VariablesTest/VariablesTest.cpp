#include <gtest/gtest.h>

// Variables.h
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

TEST(VariablesTest, DifferentTypes)
{
    StringObj a{"test"};
    IntObj b{1};
    FloatObj c{1.0};
    std::map<std::string, Data> temp;
    temp.insert(std::pair<std::string, Data>("int", b));
    temp.insert(std::pair<std::string, Data>("string", a));
    temp.insert(std::pair<std::string, Data>("float", c));
    Variables test(temp);
    ASSERT_NE(nullptr, test);
}

TEST(VariablesTest, getVariable)
{
    std::map<std::string, Data> temp;
    std::string testName("string");
    IntObj b{1};
    temp.insert(std::pair<std::string, Data>("int", b));
    StringObj a{"test"};
    temp.insert(std::pair<std::string, Data>(testName, a));
    Variables test(temp);
    Data result;
    result = test.getVariable(testName);
    std::cout << "getVariable(): text = ";
    std::cout << result << std::endl;
    ASSERT_TRUE(true);
}

TEST(VariablesTest, getSize)
{
    StringObj a{"test"};
    IntObj b{1};
    FloatObj c{1.0};
    std::map<std::string, Data> temp;
    temp.insert(std::pair<std::string, Data>("int", b));
    temp.insert(std::pair<std::string, Data>("string", a));
    temp.insert(std::pair<std::string, Data>("float", c));
    Variables test(temp);
    ASSERT_EQ(test.getSize(), 3);
}

TEST(VariablesTest, addVariable)
{
    StringObj a{"test"};
    IntObj b{1};
    FloatObj c{1.0};
    std::map<std::string, Data> temp;
    temp.insert(std::pair<std::string, Data>("int", b));
    temp.insert(std::pair<std::string, Data>("string", a));
    temp.insert(std::pair<std::string, Data>("float", c));
    Variables test(temp);
    std::cout << "Before addVariable(): 3 = ";
    std::cout << test.getSize() << std::endl;
    StringObj d("test2");
    test.addVariable("string2", d);
    std::cout << "After addVariable(): 4 = ";
    std::cout << test.getSize() << std::endl;
    ASSERT_TRUE(true);
}

TEST(VariablesTest, addVariable)
{
    StringObj a{"test"};
    IntObj b{1};
    FloatObj c{1.0};
    std::map<std::string, Data> temp;
    temp.insert(std::pair<std::string, Data>("int", b));
    temp.insert(std::pair<std::string, Data>("string", a));
    temp.insert(std::pair<std::string, Data>("float", c));
    Variables test(temp);
    std::cout << "Before removeVariable(): 3 = ";
    std::cout << test.getSize() << std::endl;
    test.removeVariable("int");
    std::cout << "After removeVariable(): 2 = ";
    std::cout << test.getSize() << std::endl;
    ASSERT_TRUE(true);
}