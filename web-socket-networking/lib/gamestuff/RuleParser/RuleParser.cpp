#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
// #include "../include/Rules.h"
// #include "../include/Foreach.h"
using namespace std;


std::ifstream test("../../../data/config1.json");
//Rules parser outline, currently only prints out the rule data/elements
//Eventually will create and return a vector of rules
void parseRules(Json::Value val)
{
    string ruleName = val["rule"].asString();
    if (ruleName == "foreach")
    {
        cout << "list: " << val["list"] << endl;
        cout << "element: " << val["element"] << endl;
        for(auto rule:val["rules"])
        {
            parseRules(rule);
        }
    } else if (ruleName == "global-message")
    {
        cout << "value: " << val["value"] << endl;
    } else if (ruleName == "scores")
    {
        cout << "score: " << val["score"] << endl;
        cout << "ascending: " << val["ascending"] << endl;
    } else if (ruleName == "parallelfor")
    {
        cout << "list: " << val["list"] << endl;
        cout << "element: " << val["element"] << endl;
        for(auto rule:val["rules"])
        {
            parseRules(rule);
        }
    } else if (ruleName == "loop")
    {
        if (val["until"] != nullptr)
        {
            cout << "until: " << val["until"] << endl;
        } else
        {
            cout << "while: " << val["while"] << endl;
        }
        for(auto rule:val["rules"])
        {
            parseRules(rule);
        }
    } else if (ruleName == "inparallel")
    {
        for(auto rule:val["rules"])
        {
            parseRules(rule);
        }
    } else if (ruleName == "switch")
    {
        cout << "value: " << val["value"] << endl;
        for(auto cases: val["cases"])
        {
            cout << "condition: " << cases["condition"] << endl;
            parseRules(cases["rules"]);
        }
    } else if (ruleName == "when")
    {
        for(auto cases: val["cases"])
        {
            cout << "condition: " << cases["condition"] << endl;
            for(auto rule: cases["rules"])
            {
                parseRules(rule);
            }
        }
    } else if (ruleName == "extend")
    {
        cout << "target: " << val["target"] << endl;
        cout << "list: " << val["list"] << endl;
    } else if (ruleName == "reverse")
    {
        cout << "list: " << val["list"] << endl;
    } else if (ruleName == "shuffle")
    {
        cout << "list: " << val["list"] << endl;
    } else if (ruleName == "sort")
    {
        if (val["key"] != nullptr)
        {
            cout << "key: " << endl;
        }
        cout << "list: " << val["list"] << endl;
    } else if (ruleName == "deal")
    {
        cout << "from: " << val["from"] << endl;
        cout << "to: " << val["to"] << endl;
        cout << "count: " << val["count"] << endl;
    } else if (ruleName == "add")
    {
        cout << "to: " << val["to"] << endl;
        cout << "value: " << val["value"] << endl;
    } else if (ruleName == "discard")
    {
        cout << "from: " << val["from"] << endl;
        cout << "count: " << val["count"] << endl;
    } else if (ruleName == "timer")
    {
        cout << "duration: " << val["duration"] << endl;
        cout << "mode: " << val["mode"] << endl;
        for(auto rule:val["rules"])
        {
            parseRules(rule);
        }
    } else if (ruleName == "input-choice")
    {
        cout << "to: " << val["to"] << endl;
        cout << "prompt: " << val["prompt"] << endl;
        cout << "choices: " << val["choices"] << endl;
        cout << "result: " << val["result"] << endl;
    
        
    } else if (ruleName == "input-text")
    {
        cout << "to: " << val["to"] << endl;
        cout << "prompt: " << val["prompt"] << endl;
        cout << "choices: " << val["choices"] << endl;
        cout << "result: " << val["result"] << endl;
        if (val["timeout"] != nullptr)
        {
            cout << "timeout: " << val["timeout"] << endl;
        }
    } else if (ruleName == "input-vote")
    {
        cout << "to: " << val["to"] << endl;
        cout << "prompt: " << val["prompt"] << endl;
        cout << "choices: " << val["choices"] << endl;
        cout << "result: " << val["result"] << endl;
        if (val["timeout"] != nullptr)
        {
            cout << "timeout: " << val["timeout"] << endl;
        }
    } else if (ruleName == "message")
    {
        cout << "to: " << val["to"] << endl;
        cout << "value: " << val["value"] << endl;
    } else
    {
        cout << "I either missed something or the rules were wrong" << endl;
    }    
}

int main(int argc, char const *argv[])
{
    //read json file
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(test, actualJson);
    //do thing based on string rule
    Json::Value rules = actualJson["rules"];
    //WorryMindYou where tf is my parser :concon:
    for(auto rule: rules)
    {
        parseRules(rule);
    }

    return 0;
}
