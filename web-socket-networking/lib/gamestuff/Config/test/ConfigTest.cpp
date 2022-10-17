#include "Config.h"
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    std::ifstream file("config1.json");
    Json::Value actualJson;
    Json::Reader reader;

    reader.parse(file, actualJson);

    std::map<std::string, Json::Value> configurations;
    auto config = actualJson["configuration"];

    configurations["audience"] = config["audience"];
    configurations["name"] = config["name"];
    configurations["player_count"] = config["player count"];
    configurations["setup"] = config["setup"];
    auto config = actualJson["configuration"];

    Config c{configurations};
    c.assertJSON();
    c.setVariables();
    return 0;
}
