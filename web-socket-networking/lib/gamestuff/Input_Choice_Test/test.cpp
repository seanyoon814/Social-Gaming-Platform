#include "gtest/gtest.h"
#include "Input_choice.h"

using namespace testing;

namespace {
    //This test fixture allows std::cerr (or std::cout) to be captured and tested
    //Tests within this namespace will call the SetUp() and TearDown() automatically
    class IO_TestFixture : public ::testing::Test {
    protected:
        IO_TestFixture() : sbuf{nullptr},sbuf2{nullptr} {}
        ~IO_TestFixture() override = default;

        //Setup -- saves the buffer of cerr/(optionally cout) and direct it to a stringstream
        //Also saves the buffer of cin in case input injection is used
        void SetUp() override {
            sbuf = std::cerr.rdbuf();
            std::cerr.rdbuf(buffer.rdbuf());

            sbuf2 = std::cin.rdbuf();
        }

        //Teardown -- undo changes; cerr/(optionally cout) and cin streams goes back to normal 
        void TearDown() override {
            //for output stream
            std::cerr.rdbuf(sbuf);
            sbuf = nullptr;
            //for input stream
            std::cin.rdbuf(sbuf2);
            sbuf2 = nullptr;
        }

        std::stringstream buffer{};
        std::streambuf *sbuf;

        std::streambuf *sbuf2;
    };

    TEST_F(IO_TestFixture, InputChoiceOutofRange) {
        std::istringstream ibuffer("5");
        std::cin.rdbuf(ibuffer.rdbuf());
        std::vector<std::string> choices = {"Choice one","Choice two","Choice three", "Choice four"};
        Input_choice test = Input_choice{1,"Select a choice below",choices};
        test.runRule();
        EXPECT_EQ("5",test.getResult());
        std::string expected{"Invalid: choice out of range\n"};
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    TEST_F(IO_TestFixture, InputChoiceInvalidInput) {
        std::istringstream ibuffer("invalid input string");
        std::cin.rdbuf(ibuffer.rdbuf());
        std::vector<std::string> choices = {"Doesn't matter"};
        Input_choice test = Input_choice{1,"Select a choice below",choices};
        test.runRule();
        EXPECT_EQ("",test.getResult());
        std::string expected{"Invalid input\n"};
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }

    TEST_F(IO_TestFixture, InputChoiceTimeout){
        std::vector<std::string> choices = {"Doesn't matter"};
        Input_choice test = Input_choice{1,"Select a choice below",choices,0.01};
        test.runRule();
        EXPECT_EQ("",test.getResult());
        std::string expected{"Timed out\n"};
        std::string actual{buffer.str()};
        EXPECT_EQ(expected, actual);
    }
}

/*
//Initiail testing code (single file main() )-- ignore
class Rules{
    virtual void runRule() = 0;
};

template <class T>
struct Condition
{
 static T (*pfunction)();
};

class Loop: public virtual Rules{
    public:
        Loop(bool &c){cond = c;}
        void runRule(){
            while(cond){
                //std::cout << "test";
                //rules.runRule();
            }
        }
        std::vector<Rules> getRules();
    
    private:
        std::vector<Rules> rules;
        bool cond;
        bool* (*condition)();
    
};*/

/*
class Input_choice: public virtual Rules{
    public:
        Input_choice(int p, std::string s, std::vector<std::string> c, int t=0){
            playerID = p;
            prompt = s;
            choices = c;
            timeout =t;
        }
        ~Input_choice(){}
        void runRule(){
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
        
    private:
        int playerID;
        std::string prompt;
        std::vector<std::string> choices;
        std::string result;
        int timeout;
};
*/
