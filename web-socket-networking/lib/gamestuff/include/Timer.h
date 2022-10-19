#pragma once

#include <algorithm>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>
#include <future>
#include <chrono>

enum class Mode : char {
  EXACT, AT_MOST, TRACK
};

class Timer {
    public:
        Timer(double seconds)
            : duration{seconds},
              isFlag{false},
              inProgress{false}
            { }

        void setDuration(double seconds);
        double getDuration();
        void setMode(Mode timerMode);
        Mode getMode();
        void setRules(std::vector<std::string_view> rules);
        std::vector<std::string_view> getRules();
        std::future_status start(std::future<std::string> input);

    private:
        int duration;
        Mode mode;
        std::vector<std::string_view> rules;
        bool isFlag;
        double elapsedTime;
        bool inProgress;
};