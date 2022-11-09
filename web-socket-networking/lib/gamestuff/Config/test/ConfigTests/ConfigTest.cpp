#include "Config.h"
// #include "Config.h"
#include "nlohmann/json.hpp"
#include <gtest/gtest.h>
#include <fstream>
#include <iostream>
using json = nlohmann::json;
using namespace std;
std::ifstream RPS("RPS.json");
std::ifstream defaultV("default.json");
std::ifstream brokenV("wrongVal.json");
std::ifstream brokenK("wrongKey.json");
std::ifstream minGreater("mingreatermax.json");
json j = json::parse(RPS);
TEST(ConfigJSONTest, DefaultValues)
{
    json j = json::parse(defaultV);
    json config = j["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(true, c.assertJSON());
}
TEST(ConfigJSONTest, AssertFunctionRightValues){
    json config = j["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(true, c.assertJSON());
}
TEST(ConfigJSONTest, AssertFunctionWrongValues){
    json j = json::parse(brokenV);
    json config = j["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(false, c.assertJSON());
}
TEST(ConfigJSONTest, AssertFunctionWrongKeys){
    json j = json::parse(brokenK);
    json config = j["configuration"];
    Config c{config};
    // c.setVariables();
    ASSERT_EQ(false, c.assertJSON());
}
TEST(ConfigJSONTest, MinPlayersMoreThanMax){
    json j = json::parse(minGreater);
    json config = j["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(false, c.assertJSON());
}
TEST(ConfigJSONTest, RockPaperScissors){
    json config = j["configuration"];
    Config c{config};
    c.setVariables();
    ASSERT_EQ(true, c.assertJSON());
    json rpsConfig = c.getJSON();
    ASSERT_EQ(false, config["audience"].get<bool>());
    ASSERT_EQ("Rock, Paper, Scissors", config["name"].get<std::string>());
    ASSERT_EQ(2, config["player count"]["min"].get<int>());
    ASSERT_EQ(4, config["player count"]["max"].get<int>());
    ASSERT_EQ(10, config["setup"]["Rounds"].get<int>());
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
    return 0;
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
