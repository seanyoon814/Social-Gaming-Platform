#include "../include/Config.h"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
using namespace std;
std::ifstream file("config1.json");
Json::Value actualJson;
Json::Reader reader;


TEST(ConfigJSONTest, RockPaperScissors){
    reader.parse(file, actualJson);
    std::map<std::string, Json::Value> configurations;
    auto config = actualJson["configuration"];

    configurations["audience"] = config["audience"];
    configurations["name"] = config["name"];
    configurations["player count"] = config["player count"];
    configurations["setup"] = config["setup"];

    ASSERT_EQ(true, configurations["audience"].asBool());
    ASSERT_EQ("Rock, Paper, Scissors", configurations["name"].asString());
    ASSERT_EQ(2, configurations["player count"]["min"].asInt());
    ASSERT_EQ(4, configurations["player count"]["min"].asInt());
    ASSERT_EQ(10, configurations["setup"]["Rounds"].asInt());
}
// int main(int argc, char const *argv[])
// {
//     std::ifstream file("config1.json");
//     Json::Value actualJson;
//     Json::Reader reader;

//     reader.parse(file, actualJson);

//     std::map<std::string, Json::Value> configurations;
//     auto config = actualJson["configuration"];

//     configurations["audience"] = config["audience"];
//     configurations["name"] = config["name"];
//     configurations["player count"] = config["player count"];
//     configurations["setup"] = config["setup"];

//     Config c{configurations};
//     if(c.assertJSON())
//     {
//         cout << "Passed test case" << endl;
//     }
//     else
//     {
//         cout << "Did not pass test case" << endl;
//     }
//     c.setVariables();
//     std::map<std::string, Json::Value> m = c.getJSON();
//     cout << m["name"].asString() << endl;
//     auto playerCount = m["player count"];
//     cout << m["player count"]["min"].asInt() << endl;
//     cout << m["player count"]["max"].asInt() << endl;
//     cout << m["audience"].asBool() << endl;
//     return 0;
// }
