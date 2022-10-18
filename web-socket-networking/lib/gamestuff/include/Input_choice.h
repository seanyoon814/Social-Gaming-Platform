#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include <string>
#include <thread>
#include "Rules.h"

class Input_choice: public virtual Rules{
    public:
        Input_choice(int p, std::string s, std::vector<std::string> c,double t=0);
        ~Input_choice();
        void runRule();
        std::string getResult();
        
    private:
        int playerID;
        std::string prompt;
        std::vector<std::string> choices;
        std::string result;
        double timeout;
};
