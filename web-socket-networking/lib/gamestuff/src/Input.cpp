#include "Input.h"

Input::Input(std::string s, double t){
    prompt = s;
    timeout =t;
}

//Input choice
Input_choice::Input_choice(int p, std::string s, std::vector<std::string> c, double t):Input(s,t){
    playerID = p;
    choices = c;
}

Input_choice::~Input_choice(){}

void Input_choice::runRule(){
//Currently displays the message in stdout, 
//need to update later once server/client is implemented to send message to correct user
            std::cout << "Sending Message to player " << playerID << std::endl << prompt << std::endl;
            for(std::size_t i=0; i<choices.size(); i++){
                std::printf("[%lu] ",i+1);
                std::cout<< choices[i] << std::endl;
            }
            
            if(timeout==0){
                //timeout not set
                std::getline(std::cin, result);
            }else{            
                //Set timeout for std::cin -- calls cin in a temporary thread
                time_t start = time(NULL);
                time_t waitTime = timeout;            
                while (time(NULL) < start + waitTime && result.empty())
                {
                    std::thread t1([&]() {std::getline(std::cin, result);});
                    //To prevent 'Resource temporarily unavailable'
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                    t1.detach();
                }
            }
            //Validate input choice
            if (result.empty()){
                std::cerr << "Timed out\n";
                return;
            }
            try{
                if(std::stoi(result) < 1 || std::stoi(result)>choices.size()){
                    std::cerr<<"Invalid: choice out of range\n";
                    return;
                }
            }catch(std::exception e){
                result.clear(); 
                std::cerr <<"Invalid input\n"; 
                return;
                }
           
        }

std::string Input_choice::getResult(){
    return result;
}

//Input text
Input_text::Input_text(int p, std::string s, double t):Input(s,t){
    playerID = p;
}

Input_text::~Input_text(){}

void Input_text::runRule(){
            std::cout << "Sending Message to player " << playerID << std::endl << prompt << std::endl;

            if(timeout==0){
                std::getline(std::cin, result);
            }else{            
                time_t start = time(NULL);
                time_t waitTime = timeout;            
                while (time(NULL) < start + waitTime && result.empty())
                {
                    std::thread t1([&]() {std::getline(std::cin, result);});
                    std::this_thread::sleep_for(std::chrono::milliseconds(20));
                    t1.detach();
                }
            }
            //Check input
            if (result.empty()){
                std::cerr << "Timed out\n";
                return;
            }           
}
std::string Input_text::getResult(){
    return result;
}

//Input vote
Input_vote::Input_vote(std::vector<int> ps, std::string s, std::vector<std::string> c,double t):Input(s,t){
    playerList = ps;
    choices = c;
}

Input_vote::~Input_vote(){}

void Input_vote::runRule(){
    //work in progress
}
