#include "Rules.h"
//Use templates to pass in information to certain rule types that may need extra parameters
template <typename T, typename U>
std::string Rules::ruleSetOperation(RulesType ruleT, std::string rule, T info, U extraInfo) {
    ruleT.rulesType = rule;
    switch (rule) {
        case "foreach":
            ruleT.list = info; //info in this case is a list
            setRuleOnList(ruleT,rule);
            break;
        case "parallelfor":
            ruleT.list = info; //info in this case is a list
            setRuleOnList(ruleT,rule);
            break;
        case "timer":
            setTimerRule(ruleT, info, extraInfo) // info would be duration, extra info would be mode
            break;
        case "message"
            setMessageRule(ruleT, info) //info would be message in this case
            break;
        case "global-message"
            setGlobalMessageRule(ruleT,info) //info is global message in this case
            break;
    }
}
//A couple of rule setters
//Check if parallel or foreach, then operates accordingly
void Rules::setRuleOnList(RulesType ruleT, std::string rule) {
    if (rule == "foreach") {
    } else { }
}
void Rules::setTimerRule(RulesType ruleT,int duration, std::string mode);
void Rules::setMessageRule(RulesType ruleT,std::string message);
void Rules::setGlobalMessageRule(RulesType ruleT,std::string message) {
    ruleT.value = message;
}