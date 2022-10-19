#include <stdio.h>
#include <map>
#include "Constant.h"
#include <iostream>

// Tests different types of values inside the constant map.
void differentTypesTest()
{
    std::map<std::string, std::any> temp;
    temp.insert(std::pair<std::string, std::any>("int", 1));
    temp.insert(std::pair<std::string, std::any>("string", "text"));
    temp.insert(std::pair<std::string, std::any>("float", 1.0));
    std::map<std::string, std::string> temp1;
    temp.insert(std::pair<std::string, std::any>("map", temp1));
    Constant test(temp);
}
// Tests the getConstant method
void getConstantTest()
{
    std::map<std::string, std::any> temp;
    std::string testName("string");
    temp.insert(std::pair<std::string, std::any>("int", 1));
    std::string testValue("text");
    temp.insert(std::pair<std::string, std::any>(testName, testValue));
    Constant test(temp);
    std::any result;
    result = test.getConstant(testName);
    std::cout << "getConstant(): text = ";
    std::cout << std::any_cast<std::string>(result) << std::endl;
}
// Tests the getSize method
void getSizeTest()
{
    std::map<std::string, std::any> temp;
    temp.insert(std::pair<std::string, std::any>("int", 1));
    temp.insert(std::pair<std::string, std::any>("string", "text"));
    temp.insert(std::pair<std::string, std::any>("float", 1.0));
    std::map<std::string, std::string> temp1;
    temp.insert(std::pair<std::string, std::any>("map", temp1));
    Constant test(temp);
    std::cout << "getSize(): 4 = ";
    std::cout << test.getSize() << std::endl;
}
// Tests the addConstant method
void addConstantTest()
{
    std::map<std::string, std::any> temp;
    temp.insert(std::pair<std::string, std::any>("int", 1));
    temp.insert(std::pair<std::string, std::any>("string", "text"));
    temp.insert(std::pair<std::string, std::any>("float", 1.0));
    Constant test(temp);
    std::cout << "Before addConstant(): 3 = ";
    std::cout << test.getSize() << std::endl;
    std::map<std::string, std::string> temp1;
    std::string valueName("map");
    test.addConstant(valueName, temp1);
    std::cout << "After addConstant(): 4 = ";
    std::cout << test.getSize() << std::endl;
}

int main()
{
    // Tests different types
    differentTypesTest();
    // Tests getConstant method
    getConstantTest();
    // Tests getNumConstants method
    getSizeTest();
    // Tests addConstant method
    addConstantTest();

    return 0;
}
