#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
//parser, rules, data header for creating each rule
#include "../include/Parser.h"
#include "../include/Rules.h"
#include "../Data/include/Data.h"
//headers of different rules
#include "../include/Arithmetic.h"
#include "../include/Foreach.h"
#include "../include/InParallel.h"
#include "../include/Input.h"
#include "../include/Loop.h"
#include "../include/Messages.h"
#include "../include/Parallelfor.h"
#include "../include/Switch.h"
#include "../include/Timer.h"
#include "../include/When.h"
#include "../ListOperations/include/ListOps.h"


using namespace std;
using json = nlohmann::json;

//Rules parser outline, currently only prints out the rule data/elements
//TODO: replace each print statements with rule constructors (requires said rule to be done)
vector<Rules*> parseRules(json rules)
{
    vector<Rules*> ruleList;
    for(auto rule: rules)
    {
        string ruleName = rule["rule"];
        if (ruleName == "foreach")
        {
            cout << "list: " << rule["list"] << endl;
            cout << "element: " << rule["element"] << endl;
            parseRules(rule["rules"]);
        } else if (ruleName == "global-message")
        {
            string messageValue = rule["value"].dump();
            Rules* newRule = new Globalmessage(messageValue);
            ruleList.push_back(newRule);
        } else if (ruleName == "scores")
        {
            cout << "score: " << rule["score"] << endl;
            cout << "ascending: " << rule["ascending"] << endl;
        } else if (ruleName == "parallelfor")
        {
            cout << "list: " << rule["list"] << endl;
            cout << "element: " << rule["element"] << endl;
            parseRules(rule["rules"]);
        } else if (ruleName == "loop")
        {
            if (rule["until"] != nullptr)
            {
                cout << "until: " << rule["until"] << endl;
            } else
            {
                cout << "while: " << rule["while"] << endl;
            }
            for(auto rule:rule["rules"])
            {
                parseRules(rule);
            }
        } else if (ruleName == "inparallel")
        {
            parseRules(rule["rules"]);
        } else if (ruleName == "switch")
        {
            cout << "value: " << rule["value"] << endl;
            for(auto cases: rule["cases"])
            {
                cout << "condition: " << cases["condition"] << endl;
                parseRules(cases["rules"]);
            }
        } else if (ruleName == "when")
        {
            for(auto cases: rule["cases"])
            {
                cout << "condition: " << cases["condition"] << endl;
                parseRules(cases["rules"]);
            }
        } else if (ruleName == "extend")
        {
            cout << "target: " << rule["target"] << endl;
            cout << "list: " << rule["list"] << endl;
        } else if (ruleName == "reverse")
        {
            cout << "list: " << rule["list"] << endl;
        } else if (ruleName == "shuffle")
        {
            cout << "list: " << rule["list"] << endl;
        } else if (ruleName == "sort")
        {
            if (rule.contains("key"))
            {
                cout << "key: " << rule["key"] << endl;
            }
            cout << "list: " << rule["list"] << endl;
        } else if (ruleName == "deal")
        {
            cout << "from: " << rule["from"] << endl;
            cout << "to: " << rule["to"] << endl;
            cout << "count: " << rule["count"] << endl;
        } else if (ruleName == "add")
        {
            cout << "to: " << rule["to"] << endl;
            cout << "value: " << rule["value"] << endl;
        } else if (ruleName == "discard")
        {
            cout << "from: " << rule["from"] << endl;
            cout << "count: " << rule["count"] << endl;
        } else if (ruleName == "timer")
        {
            cout << "duration: " << rule["duration"] << endl;
            cout << "mode: " << rule["mode"] << endl;
            parseRules(rule["rules"]);
        } else if (ruleName == "input-choice")
        {
            cout << "to: " << rule["to"] << endl;
            cout << "prompt: " << rule["prompt"] << endl;
            cout << "choices: " << rule["choices"] << endl;
            cout << "result: " << rule["result"] << endl;
        
            
        } else if (ruleName == "input-text")
        {
            cout << "to: " << rule["to"] << endl;
            cout << "prompt: " << rule["prompt"] << endl;
            cout << "choices: " << rule["choices"] << endl;
            cout << "result: " << rule["result"] << endl;
            if (rule.contains("timeout"))
            {
                cout << "timeout: " << rule["timeout"] << endl;
            }
        } else if (ruleName == "input-vote")
        {
            cout << "to: " << rule["to"] << endl;
            cout << "prompt: " << rule["prompt"] << endl;
            cout << "choices: " << rule["choices"] << endl;
            cout << "result: " << rule["result"] << endl;
            if (rule.contains("timeout"))
            {
                cout << "timeout: " << rule["timeout"] << endl;
            }
        } else if (ruleName == "message")
        {
            cout << "to: " << rule["to"] << endl;
            cout << "value: " << rule["value"] << endl;
        } else
        {
            cout << "I either missed something or the rules were wrong" << endl;
        }
    }

    return ruleList;
}

int main(int argc, char const *argv[])
{
    //read json file
    string testFileSource = "../../../data/config1.json";
    //do thing based on string rule
    Parser parser;
    json file = parser.parseJson(testFileSource);
    json rules = parser.parseRules(file);
    //WorryMindYou where tf is my parser :concon:
    auto ruleList = parseRules(rules);
    for(auto rule: ruleList)
    {
        rule->runRule();
    }
    return 0;
}
