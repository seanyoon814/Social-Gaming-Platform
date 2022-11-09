#include "InParallel.h"

Inparallel::Inparallel(std::vector<Rules> ruleList) {
    rules = rules;
}

std::vector<Rules> Inparallel::getRules() {
    return rules;
}

void Inparallel::runRule() {
    for (auto rule: rules) {
        rule.runRule();
    }
}