#include<vector>
#include<string>
//General rule struct to store various different rule elements 
//(will need to change this to each ruletype)
struct RuleType{
    std::string rulesType;
    //Some rule types use list
    std::vector<std::string> list;
    //Some rules use value
    auto value;
    //Many rule execute the rules list on list elements 
    //Not certain how to operate with This
    std::vector<std::string> rulesList;
}
template <typename T>
class Rules{
    public:
        Rules(void) {};
        ~Rules(void) {};

        std::string ruleSetOperation(std::string rule, T info);
        //A couple of rule setters
        void setRuleOnList(RulesType ruleT, std::string rule);
        void setTimerRule(RulesType ruleT,int duration, std::string mode )
        void setMessageRule(RulesType ruleT,std::string message);
        void setGlobalMessageRule(RulesType ruleT,std::string message);
};