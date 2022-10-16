#include <vector>
#include <iostream>
#include <ctime>
#include <string>
#include <thread>

class Input_choice: public virtual Rules{
    public:
        Input_choice(int p, std::string s, std::vector<std::string> c, int t=0);
        ~Input_choice();
        void runRule();
        
    private:
        int playerID;
        std::string prompt;
        std::vector<std::string> choices;
        std::string result;
        int timeout;
};
