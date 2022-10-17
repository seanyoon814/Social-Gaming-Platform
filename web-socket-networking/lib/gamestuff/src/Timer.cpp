#include "Timer.h"


void Timer::setDuration(double time) {
    duration = time;
}

double Timer::getDuration() {
    return duration;
}

void Timer::setMode(Mode timeMode) {
    mode = timeMode;
}

Mode Timer::getMode() {
    return mode;
}

void Timer::setRules(std::vector<std::string_view> ruleList) {
    rules = ruleList;
}

std::vector<std::string_view> Timer::getRules() {
    return rules;
}

std::future_status Timer::start(std::future<std::string> input) {
    if(mode == Mode::AT_MOST) {
        std::chrono::system_clock::time_point time_passed = std::chrono::system_clock::now() + std::chrono::seconds(duration);
        std::future_status status = input.wait_until(time_passed);
        return status;
    }  
}
