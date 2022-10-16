#include "Input_choice.h"

Input_choice::Input_choice(int p, std::string s, std::vector<std::string> c, int t=0){
    playerID = p;
    prompt = s;
    choices = c;
    timeout =t;
}
void Input_choice::runRule(){
            //Currently displays the message in stdout, 
            //need to update later once server/client is implemented to send message to correct user
            std::cout << "Sending Message to player " << playerID << endl << prompt << endl;
            for(std::size_t i=0; i<choices.size(); i++){
                std::printf("[%lu] ",i+1);
                std::cout<< choices[i] << endl;
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
                std::cout << "Timed out\n";
                return;
            }
            try{
                if(std::stoi(result) < 1 || std::stoi(result)>choices.size()){
                    std::cout<<"Invalid: choice out of range\n";
                    return;
                }
            }catch(exception e){std::cout <<"Invalid input\n"; return;}
           
        }
