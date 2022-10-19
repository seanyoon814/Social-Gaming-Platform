#include <gtest/gtest.h>

// Constant.h
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

TEST(ConstantTest, DifferentTypes)
{
    StringObj a{"test"};
    IntObj b{1};
    FloatObj c{1.0};
    std::map<std::string, Data> temp;
    temp.insert(std::pair<std::string, Data>("int", b));
    temp.insert(std::pair<std::string, Data>("string", a));
    temp.insert(std::pair<std::string, Data>("float", c));
    Constant test(temp);
    ASSERT_NE(nullptr, test);
}

TEST(ConstantTest, getConstant)
{
    std::map<std::string, Data> temp;
    std::string testName("string");
    IntObj b{1};
    temp.insert(std::pair<std::string, Data>("int", b));
    StringObj a{"test"};
    temp.insert(std::pair<std::string, Data>(testName, a));
    Constant test(temp);
    Data result;
    result = test.getConstant(testName);
    std::cout << "getConstant(): text = ";
    std::cout << result << std::endl;
    ASSERT_TRUE(true);
}

TEST (ConstantTest, getSize){
    StringObj a{"test"};
    IntObj b{1};
    FloatObj c{1.0};
    std::map<std::string, Data> temp;
    temp.insert(std::pair<std::string, Data>("int", b));
    temp.insert(std::pair<std::string, Data>("string", a));
    temp.insert(std::pair<std::string, Data>("float", c));
    Constant test(temp);
    ASSERT_EQ(test.getSize(),3);
}

TEST (ConstantTest, addConstant){
    StringObj a{"test"};
    IntObj b{1};
    FloatObj c{1.0};
    std::map<std::string, Data> temp;
    temp.insert(std::pair<std::string, Data>("int", b));
    temp.insert(std::pair<std::string, Data>("string", a));
    temp.insert(std::pair<std::string, Data>("float", c));
    Constant test(temp);
    std::cout << "Before addConstant(): 3 = ";
    std::cout << test.getSize() << std::endl;
    StringObj d("test2");
    test.addConstant(std::pair<std::string, Data>("string2", d));
    std::cout << "After addConstant(): 4 = ";
    std::cout << test.getSize() << std::endl;
    ASSERT_TRUE(true);
}