#include "Parallelfor.h"
#include <list>

Parallelfor::Parallelfor(std::vector<Rules> ruleList, std::list<int> list) {
    rules = rules;
    list = list;
}

std::vector<Rules> Parallelfor::getRules() {
    return rules;
}

std::list<int> Parallelfor::getList() {
    return list;
}

void Parallelfor::runRule() {
    for (auto element: list) {
        for (auto rule: rules) {
            rule.runRule();
        }
    }
}