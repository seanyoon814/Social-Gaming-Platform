#pragma once
#include <vector>
#include <iostream>
#include <ctime>
#include <string>
#include <thread>
#include <map>
#include "Rules.h"

class Input: public virtual Rules{
    public:
        Input(std::string s, double t=0);

    protected:
        std::string prompt;
        double timeout;
};

class Input_choice: Input{
    public:
        Input_choice(int p, std::string s, std::vector<std::string> c,double t=0);
        ~Input_choice();
        virtual void runRule();
        std::string getResult();
        
    private:
        int playerID;
        std::vector<std::string> choices;
        std::string result;
};

class Input_text: Input{
    public:
        Input_text(int p, std::string s,double t=0);
        ~Input_text();
        virtual void runRule();
        std::string getResult();

    private:
        int playerID;
        std::string result;
};

class Input_vote: Input{
    public:
        Input_vote(std::vector<int> ps, std::string s, std::vector<std::string> c,double t=0);
        ~Input_vote();
        virtual void runRule();
        
    private:
        //need to replace with player objects later, int vector to represent list of playerIDs as placeholder
        std::vector<int> playerList;
        std::vector<std::string> choices;
        std::map<std::string,int> voteResult;

};
