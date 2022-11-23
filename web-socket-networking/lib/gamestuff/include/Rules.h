#include<vector>
#include<string>

class Rules{
    public:
        virtual void runRule() = 0;
        Rules(void) {};
        ~Rules(void) {};

        std::string ruleSetOperation(std::string rule, std::string info);
        //A couple of rule setters
        void setRuleOnList(std::string rule);
        void setTimerRule(int duration, std::string mode );
        void setMessageRule(std::string message);
        void setGlobalMessageRule(std::string message);
};
