#include "Parallelfor.h"
#include <list>

Parallelfor::Parallelfor(std::vector<Rules> ruleList, std::list list) {
    rules = rules;
    list = list;
}

std::vector<Rules> Parallelfor::getRules() {
    return rules;
}

std::list Parallelfor::getList() {
    return list;
}

void Parallelfor::runRule() {
    for (auto element: list) {
        for (auto rule: rules) {
            rule.runRule();
        }
    }
}