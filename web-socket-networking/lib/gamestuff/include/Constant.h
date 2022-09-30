#include <map>
#include <string>
using namespace std;

// For quiz based game
struct Questions
{
    // map containing question and answers
    map<string, string> questionsAnswers;
    // number of questions
    int length;
};

class Constant
{
public:
    // constructor
    Constant(map<string, Questions> constant);
    // destructor
    ~Constant();
    // Add questions/answers
    void addQuestionAnswer(string question, string answer);
    // Returns questions and answers
    Questions getQuestions();
    // Returns answer to question
    string getAnswer(string question);
    // Returns number of questions
    int getNumOfQuestions();

private:
    // For quiz based games, constant is Questions
    // Which contains a map from questions to answers
    map<string, Questions> constant;

    // Questions struct contains questions
    Questions questions;
};