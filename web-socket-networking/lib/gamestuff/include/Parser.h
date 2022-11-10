#include <iostream>
#include <fstream>
#include <string>
#include <map>
// #include <glog/logging.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;


class Parser{
    public:
        Parser();
        bool validateJsonObject(json jsonObject);
        json parseJson(const std::string jsonSource);
        bool validateConfigurations(json config);
        bool validateRuleForEach(json rule);
        bool validateRuleLoop(json rule);
        bool validateRuleInParallel(json rule);
        bool validateRuleParallelFor(json rule);
        bool validateRuleSwitch(json rule);
        bool validateRuleWhen(json rule);
        bool validateRuleExtend(json rule);
        bool validateRuleReverse(json rule);
        bool validateRuleShuffle(json rule);
        bool validateRuleSort(json rule);
        bool validateRuleDeal(json rule);
        bool validateRuleDiscard(json rule);
        bool validateRuleAdd(json rule);
        bool validateRuleTimer(json rule);
        bool validateRuleInputChoice(json rule);
        bool validateRuleInputText(json rule);
        bool validateRuleInputVote(json rule);
        bool validateRuleMessage(json rule);
        bool validateRuleGlobalMessage(json rule);
        bool validateRuleScores(json rule);
        json parseConfigurations(json data);
        json parseConstants(json data);
        json parseRules(json data);
        bool validateRule(json data);

};