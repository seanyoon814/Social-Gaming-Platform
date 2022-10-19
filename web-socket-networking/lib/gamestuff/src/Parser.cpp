#include <iostream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::ifstream file("data/config2.json");
    Json::Value actualJson;
    Json::Reader reader;

    reader.parse(file, actualJson);

    std::cout<< "Total json data: \n" << actualJson <<std::endl;
    std::cout<< "Configuration: " << actualJson["configuration"] <<std::endl;
    std::cout<< "Contants: " << actualJson["constants"] <<std::endl;
    std::cout<< "Variables: " << actualJson["variables"] <<std::endl;
    std::cout<< "Per-Player: " << actualJson["per-player"] <<std::endl;
    std::cout<< "Per-Audience: " << actualJson["per-audience"] <<std::endl;
    std::cout<< "Per-Audience: " << actualJson["per-audience"] <<std::endl;
    std::cout<< "Rules: " << actualJson["rules"] <<std::endl;

    auto config = actualJson["configuration"];
    std::cout<< "Audience: " << config["audience"] <<std::endl; 
    std::cout<< "Name: " << config["name"] <<std::endl;
    std::cout<< "Player Count: " << config["player count"] <<std::endl;
    std::cout<< "setup: " << config["setup"] <<std::endl;

    bool audience = config["audience"].asBool();

    std::cout<<audience<<std::endl;

    //we can add to a map this way

    std::map<std::string, Json::Value> configurations;
    configurations["audience"] = config["audience"];
    configurations["name"] = config["name"];
    configurations["player_count"] = config["player count"];
    configurations["setup"] = config["setup"];

    for(std::map<std::string, Json::Value>::iterator ii=configurations.begin(); ii!=configurations.end(); ++ii)  
    {  
       std::cout << (*ii).first << ": " << (*ii).second << std::endl;  
    } 

    //then call a config class for example this way

    config::config newConfigurations(configurations);

    //Or I could just parse all the values here in main and call the Config class with the right values

    //Like this

    bool audience = config["audience"].asBool();
    std::string name = config["name"].asString();
    auto player_count = config["player count"];
    int max_player = player_count["max"].asInt();
    int min_player = player_count["min"].asInt();
    std::string setup = player_count["setup"].asString();

    //then call the config class with the values as they are

    config::config newConfigurations(audience, name, max_player, min_player, setup);

    auto constants = actualJson["constants"];

    auto variables = actualJson["variables"];

    auto per_player = actualJson["per-player"];

    auto per_audience = actualJson["per-audience"];

    auto rules = actualJson["rules"];

    Rules::Rules newRules(rules);

    PerPlayer::PerPlayer newPlayerConfig(per_player);

    PerAudience::PerAudience newAudienceConfig(per_audience);

    return 0;
}

