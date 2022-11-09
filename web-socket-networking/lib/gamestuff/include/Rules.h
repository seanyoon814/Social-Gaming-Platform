#ifndef RULES_H
#define RULES_H
#include<vector>
#include<string>

class Rules{
    public:
        virtual void runRule() = 0;
        Rules(void) {};
        ~Rules(void) {};

        // std::string ruleSetOperation(std::string rule, T info);
        // //A couple of rule setters
        // void setRuleOnList(RulesType ruleT, std::string rule);
        // void setTimerRule(RulesType ruleT,int duration, std::string mode )
        // void setMessageRule(RulesType ruleT,std::string message);
        // void setGlobalMessageRule(RulesType ruleT,std::string message);
};
#endif