#include <iostream>
#include <fstream>
#include <string>
#include <map>
// #include <glog/logging.h>
#include "../include/Parser.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

bool Parser::validateJsonObject(json jsonObject) {
  // Validate # of elements
  if (jsonObject.size() != 6) {
    return false;
  }

  //validate root level elements
  if(!jsonObject.contains("configuration") || !jsonObject.contains("constants") || !jsonObject.contains("variables") || !jsonObject.contains("per-player") || !jsonObject.contains("per-audience") || !jsonObject.contains("rules")) {
    return false;
  }

  return true;
}

json Parser::parseJson(const std::string jsonSource) {
  std::ifstream jsonFile(jsonSource);
  //parse json file
  json jsonObject = json::parse(jsonFile);
  if (jsonObject == nullptr) {
    //LOG(ERROR) << "Failed to read JSON file or filepath is incorrect"<< "formatted: returning nullptr";
    return nullptr;
  }

  if (!validateJsonObject(jsonObject)) {
    //LOG(ERROR) << "Failed to validate JSON object: returning nullptr";
    return nullptr;
  }

  return jsonObject;
}

bool Parser::validateConfigurations(json config) {
    // Validate # of elements
    if (config.size() != 4) {
        return false;
    }

    //validate root level elements
    if(!config.contains("name") || !config.contains("player count") || !config.contains("audience") || !config.contains("setup")) {
        return false;
    }

    //validate palyer count
    json playerCount = config["player count"];
    if(!playerCount.contains("max") || !playerCount.contains("min")){
        return false;
    }

    return true;

}

bool Parser::validateRuleForEach(json rule) {
    //validate # of elements
    if (rule.size() != 4) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("list") || !rule.contains("element") || !rule.contains("rules")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleLoop(json rule) {
    //validate # of elements
    if (rule.size() != 3) {
        return false;
    }

    //validate root level elements
    if(rule.contains("rule") && (rule.contains("until") || rule.contains("while")) && !rule.contains("rules")) {
        return true;
    }

    return false;

}

bool Parser::validateRuleInParallel(json rule) {
    //validate # of elements
    if (rule.size() != 2) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("rules")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleParallelFor(json rule) {
    //validate # of elements
    if (rule.size() != 4) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("list") || !rule.contains("element") || !rule.contains("rules")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleSwitch(json rule) {
    //validate # of elements
    if (rule.size() != 4) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("value") || !rule.contains("list") || !rule.contains("cases")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleWhen(json rule) {
    //validate # of elements
    if (rule.size() != 2) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("cases")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleExtend(json rule) {
    //validate # of elements
    if (rule.size() != 3) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("target") || !rule.contains("list")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleReverse(json rule) {
    //validate # of elements
    if (rule.size() != 2) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("list")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleShuffle(json rule) {
    //validate # of elements
    if (rule.size() != 2) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("list")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleSort(json rule) {
    //validate # of elements
    if (rule.size() != 2 || rule.size() != 3) {
        return false;
    }

    //validate root level elements
    if(rule.size() == 2) {
        if(!rule.contains("rule") || !rule.contains("list")) {
            return false;
        }
    } else {
        if(!rule.contains("rule") || !rule.contains("list") || !rule.contains("key")) {
            return false;
        }
    }
    
    return true;
}

bool Parser::validateRuleDeal(json rule) {
    //validate # of elements
    if (rule.size() != 4) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("from") || !rule.contains("to") || !rule.contains("count")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleDiscard(json rule) {
    //validate # of elements
    if (rule.size() != 3) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("from") || !rule.contains("count")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleAdd(json rule) {
    //validate # of elements
    if (rule.size() != 3) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("to") || !rule.contains("value")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleTimer(json rule) {
    //validate # of elements
    if (rule.size() != 4 || rule.size() != 5) {
        return false;
    }

    //validate root level elements
    if(rule.size() == 4) {
        if(!rule.contains("rule") || !rule.contains("duration") || !rule.contains("mode") || !rule.contains("rules")) {
            return false;
        }
    } else {
        if(!rule.contains("rule") || !rule.contains("duration") || !rule.contains("mode") || !rule.contains("rules") || !rule.contains("flag")) {
            return false;
        }
    }
    
    return true;
}

bool Parser::validateRuleInputChoice(json rule) {
    //validate # of elements
    if (rule.size() != 5 || rule.size() != 6) {
        return false;
    }

    //validate root level elements
    if(rule.size() == 5) {
        if(!rule.contains("rule") || !rule.contains("to") || !rule.contains("prompt") || !rule.contains("choices") || !rule.contains("result")) {
            return false;
        }
    } else {
        if(!rule.contains("rule") || !rule.contains("to") || !rule.contains("prompt") || !rule.contains("choices") || !rule.contains("result") || !rule.contains("timeout")) {
            return false;
        }
    }
    
    return true;
}

bool Parser::validateRuleInputText(json rule) {
    //validate # of elements
    if (rule.size() != 4 || rule.size() != 5) {
        return false;
    }

    //validate root level elements
    if(rule.size() == 4) {
        if(!rule.contains("rule") || !rule.contains("to") || !rule.contains("prompt") || !rule.contains("result")) {
            return false;
        }
    } else {
        if(!rule.contains("rule") || !rule.contains("to") || !rule.contains("prompt") || !rule.contains("result") || !rule.contains("timeout")) {
            return false;
        }
    }
    
    return true;
}

bool Parser::validateRuleInputVote(json rule) {
    //validate # of elements
    if (rule.size() != 5 || rule.size() != 6) {
        return false;
    }

    //validate root level elements
    if(rule.size() == 5) {
        if(!rule.contains("rule") || !rule.contains("to") || !rule.contains("prompt") || !rule.contains("choices") || !rule.contains("result")) {
            return false;
        }
    } else {
        if(!rule.contains("rule") || !rule.contains("to") || !rule.contains("prompt") || !rule.contains("choices") || !rule.contains("result") || !rule.contains("timeout")) {
            return false;
        }
    }
    
    return true;
}

bool Parser::validateRuleMessage(json rule) {
    //validate # of elements
    if (rule.size() != 3) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("to") || !rule.contains("value")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleGlobalMessage(json rule) {
    //validate # of elements
    if (rule.size() != 2) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("value")) {
        return false;
    }

    return true;
}

bool Parser::validateRuleScores(json rule) {
    //validate # of elements
    if (rule.size() != 3) {
        return false;
    }

    //validate root level elements
    if(!rule.contains("rule") || !rule.contains("score") || !rule.contains("ascending")) {
        return false;
    }

    return true;
}

json Parser::parseConfigurations(json data) {
    if(data["configurations"] == nullptr){
        return nullptr;
    }

    json config = data["configurations"];
    bool check = validateConfigurations(config);
    if(!check) {
        return nullptr;
    }

    return config;
}

json Parser::parseConstants(json data) {
    if(data["constants"] == nullptr) {
        return nullptr;
    }

    json constants = data["constants"];
    return constants;
}

json Parser::parseRules(json data) {
    if(data["rules"] == nullptr){
        return nullptr;
    }
    auto rules = data["rules"];
    return rules;
}

bool Parser::validateRule(json data) {
    if(!data.contains("rule")) {
        return false;
    }

    std::string ruleType = data["rule"];
    bool check = false;
    if(ruleType == "foreach") {
        check = validateRuleForEach(data);
        return check;
    } else if(ruleType == "loop") {
        check = validateRuleLoop(data);
        return check;
    } else if(ruleType == "inparallel") {
        check = validateRuleInParallel(data);
        return check;
    } else if(ruleType == "parallelfor") {
        check = validateRuleParallelFor(data);
        return check;
    } else if(ruleType == "switch") {
        check = validateRuleSwitch(data);
        return check;
    } else if(ruleType == "when") {
        check = validateRuleWhen(data);
        return check;
    } else if(ruleType == "extend") {
        check = validateRuleExtend(data);
        return check;
    } else if(ruleType == "reverse") {
        check = validateRuleReverse(data);
        return check;
    } else if(ruleType == "shuffle") {
        check = validateRuleShuffle(data);
        return check;
    } else if(ruleType == "sort") {
        check = validateRuleSort(data);
        return check;
    } else if(ruleType == "deal") {
        check = validateRuleDeal(data);
        return check;
    } else if(ruleType == "discard") {
        check = validateRuleDiscard(data);
        return check;
    } else if(ruleType == "add") {
        check = validateRuleAdd(data);
        return check;
    } else if(ruleType == "timer") {
        check = validateRuleTimer(data);
        return check;
    } else if(ruleType == "input-choice") {
        check = validateRuleInputChoice(data);
        return check;
    } else if(ruleType == "input-text") {
        check = validateRuleInputText(data);
        return check;
    } else if(ruleType == "input-vote") {
        check = validateRuleInputVote(data);
        return check;
    } else if(ruleType == "message") {
        check = validateRuleMessage(data);
        return check;
    } else if(ruleType == "global-message") {
        check = validateRuleGlobalMessage(data);
        return check;
    } else if(ruleType == "scores") {
        check = validateRuleScores(data);
        return check;
    } else {
        return check;
    }
}