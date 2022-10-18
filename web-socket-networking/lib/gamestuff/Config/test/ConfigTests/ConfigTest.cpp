// #include "../include/Config.h"
#include "Config.h"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
using namespace std;
std::ifstream RPS("RPS.json");
std::ifstream defaultV("default.json");
std::ifstream brokenV("wrongVal.json");
std::ifstream brokenK("wrongKey.json");
std::ifstream minGreater("mingreatermax.json");
TEST(ConfigJSONTest, DefaultValues){
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(defaultV, actualJson);
    Json::Value config = actualJson["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(true, c.assertJSON());
}
TEST(ConfigJSONTest, AssertFunctionRightValues){
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(RPS, actualJson);
    Json::Value config = actualJson["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(true, c.assertJSON());
}
TEST(ConfigJSONTest, AssertFunctionWrongValues){
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(brokenV, actualJson);
    Json::Value config = actualJson["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(false, c.assertJSON());
}
TEST(ConfigJSONTest, AssertFunctionWrongKeys){
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(brokenK, actualJson);
    Json::Value config = actualJson["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(false, c.assertJSON());
}
TEST(ConfigJSONTest, MinPlayersMoreThanMax){
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(brokenK, actualJson);
    Json::Value config = actualJson["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(false, c.assertJSON());
}
TEST(ConfigJSONTest, RockPaperScissors){
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(RPS, actualJson);
    Json::Value config = actualJson["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(true, c.assertJSON());
    ASSERT_EQ(false, c.json["audience"].asBool());
    ASSERT_EQ("Rock, Paper, Scissors", c.json["name"].asString());
    ASSERT_EQ(2, c.json["player count"]["min"].asInt());
    ASSERT_EQ(4, c.json["player count"]["max"].asInt());
    ASSERT_EQ(10, c.json["setup"]["Rounds"].asInt());
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
