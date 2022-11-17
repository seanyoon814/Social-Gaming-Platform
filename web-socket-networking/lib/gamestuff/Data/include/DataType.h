#include "Data.h"
#include <vector>

struct condition{
    std::string cond1;
    std::string cond2;
};

// maybe change to map to string struct for parameters

class DataTypes
{
public:
    void addToDataMap(std::string, std::map<std::string, std::vector<std::map<Data, Data>>>);
    std::vector<std::map<Data, Data>> elements(std::string, std::string);
    bool contains(std::map<Data, Data>, std::string);
    int getSize(std::map<Data, Data>);
    std::vector<std::map<Data, Data>> collect(condition);

private:
    // Main data map (type -> their map)
    std::map<std::string, std::map<std::string, std::vector<std::map<Data, Data>>>> dataMap;

    // Each Data type layout
    // std::map<std::string, std::vector<std::map<Data, Data>>> constants;
    // std::map<std::string, std::vector<std::map<Data, Data>>> variables;
    // std::map<Data, Data> perPlayer;
    // std::map<Data, Data> perAudience;
    // std::vector<std::map<Data, Data>> players;
};