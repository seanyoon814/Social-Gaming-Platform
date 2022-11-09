#include <string>
#include <vector>
#include "nlohmann/json.hpp"


using json = nlohmann::json;

class StringInterpreter {

    public:
        StringInterpreter();
        std::vector<std::pair<std::string, std::vector<std::string>>> interpet(json Rule);

};