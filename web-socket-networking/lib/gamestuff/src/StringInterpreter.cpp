#include <string>
#include <vector>
#include "nlohmann/json.hpp"
#include "../include/Parser.h"

using json = nlohmann::json;

//Note: need to fix bugs with rules that take in integer values in the parameters
//Also a few rules implementations are unfinished

std::vector<std::pair<std::string, std::vector<std::string>>> StringInterpreter::interpet(json rules) {

    std::vector<std::pair<std::string, std::vector<std::string>>> results;

    Parser parser;
    auto data = parser.parseRules(rules);
    
    if (parser.validateRule(data)) {
        std::string ruleType = data["rule"];
        //Foreach
        if (ruleType == "foreach") {
            std::vector<std::string> list = data["list"];
            results.push_back(make_pair("list", list));

            std::vector<std::string> element = data["element"];
            results.push_back(make_pair("element", element));

            std::vector<std::string> rulesVector = data["rules"];
            results.push_back(make_pair("rules", rulesVector));

        }

        //Loop
        if (ruleType == "loop") {
            if (data.contains("until")) {
                std::vector<std::string> until = data["until"];
                results.push_back(make_pair("until", until));
            }
            else {
                std::vector<std::string> while = data["while"];
                results.push_back(make_pair("while", while));
            }

            std::vector<std::string> rulesVector = data["rules"];
            results.push_back(make_pair("rules", rulesVector));

        }

        //Inparallel
        if (ruleType == "inparallel") {
            std::vector<std::string> rulesVector = data["rules"];
            results.push_back(make_pair("rules", rulesVector));
        }

        //Parallelfor
        if (ruleType == "parallelfor") {
            std::vector<std::string> list = data["list"];
            results.push_back(make_pair("list", list));

            std::vector<std::string> element = data["element"];
            results.push_back(make_pair("element", element));

            std::vector<std::string> rulesVector = data["rules"];
            results.push_back(make_pair("rules", rulesVector));
        }

        //Switch
        if (ruleType == "switch") {
            //implement
        }

        //When
        if (ruleType == "when") {
            //implement
        }

        //Extend
        if (ruleType == "extend") {
            std::vector<std::string> target = data["target"];
            results.push_back(make_pair("target", target));

            std::vector<std::string> list = data["list"];
            results.push_back(make_pair("list", list));
        }

        //Reverse
        if (ruleType == "reverse") {
            std::vector<std::string> list = data["list"];
            results.push_back(make_pair("list", list));
        }

        //Shuffle
        if (ruleType == "shuffle") {
            std::vector<std::string> list = data["list"];
            results.push_back(make_pair("list", list));
        }

        //Sort
        if (ruleType == "sort") {
            std::vector<std::string> list = data["list"];
            results.push_back(make_pair("list", list));

            if (data.contains("key")) {
                std::vector<std::string> key = data["key"];
                results.push_back(make_pair("key", key));
            }
        }

        //Deal
        if (ruleType == "deal") {
            std::vector<std::string> from = data["from"];
            results.push_back(make_pair("from", from));

            std::vector<std::string> to = data["to"];
            results.push_back(make_pair("to", to));

            std::vector<std::string> count = data["count"];
            results.push_back(make_pair("count", count));
        }

        //Discard
        if (ruleType == "discard") {
            std::vector<std::string> from = data["from"];
            results.push_back(make_pair("from", from));

            std::vector<std::string> count = data["count"];
            results.push_back(make_pair("count", count));
        }
        
        //Add
        if (ruleType == "add") {
            std::vector<std::string> to = data["to"];
            results.push_back(make_pair("to", to));

            std::vector<std::string> value = data["value"];
            results.push_back(make_pair("value", value));
        }

        //Timer
        if (ruleType == "timer") {
            std::vector<std::string> duration = data["duration"];
            results.push_back(make_pair("duration", duration));

            std::vector<std::string> mode = data["mode"];
            results.push_back(make_pair("mode", mode));

            std::vector<std::string> rulesVector = data["rules"];
            results.push_back(make_pair("rules", rulesVector));

            //implement flag?
        }

        //Input-Choice
        if (ruleType == "input-choice") {
            std::vector<std::string> to = data["to"];
            results.push_back(make_pair("to", to));

            std::vector<std::string> prompt = data["prompt"];
            results.push_back(make_pair("prompt", prompt));

            std::vector<std::string> choices = data["choices"];
            results.push_back(make_pair("choices", choices));

            std::vector<std::string> result = data["result"];
            results.push_back(make_pair("result", result));

            if (data.contains("timeout")) {
                std::vector<std::string> timeout = data["timeout"];
                results.push_back(make_pair("timeout", timeout));
            }
        }

        //Input-Text
        if (ruleType == "input-text") {
            std::vector<std::string> to = data["to"];
            results.push_back(make_pair("to", to));

            std::vector<std::string> prompt = data["prompt"];
            results.push_back(make_pair("prompt", prompt));

            std::vector<std::string> choices = data["choices"];
            results.push_back(make_pair("choices", choices));

            std::vector<std::string> result = data["result"];
            results.push_back(make_pair("result", result));

            if (data.contains("timeout")) {
                std::vector<std::string> timeout = data["timeout"];
                results.push_back(make_pair("timeout", timeout));
            }
        }
        
        //Input-Vote
        if (ruleType == "input-vote") {
            std::vector<std::string> to = data["to"];
            results.push_back(make_pair("to", to));

            std::vector<std::string> prompt = data["prompt"];
            results.push_back(make_pair("prompt", prompt));

            std::vector<std::string> choices = data["choices"];
            results.push_back(make_pair("choices", choices));

            std::vector<std::string> result = data["result"];
            results.push_back(make_pair("result", result));

            if (data.contains("timeout")) {
                std::vector<std::string> timeout = data["timeout"];
                results.push_back(make_pair("timeout", timeout));
            }
        }

        //Message
        if (ruleType == "message") {
            std::vector<std::string> to = data["to"];
            results.push_back(make_pair("to", to));

            std::vector<std::string> value = data["value"];
            results.push_back(make_pair("value", value));
        }

        //Global-Message
        if (ruleType == "global-message") {
            std::vector<std::string> value = data["value"];
            results.push_back(make_pair("value", value));
        }

        //Scores
        if (ruleType == "scores") {
            std::vector<std::string> score = data["score"];
            results.push_back(make_pair("score", score));

            std::vector<std::string> ascending = data["ascending"];
            results.push_back(make_pair("ascending", ascending));
        }


    }

    return results;
}
