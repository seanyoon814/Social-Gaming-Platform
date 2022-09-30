#include <map>
#include <string>
using namespace std;

#include "Constant.h"

Constant::Constant(map<string, Questions> constant)
{
    this->constant = constant;
    // getting the first value which is the Questions struct
    questions = constant.begin()->second;
    questions.length = questions.questionsAnswers.size();
}

Constant::~Constant()
{
    delete this;
}

void Constant::addQuestionAnswer(string question, string answer)
{
    questions.questionsAnswers.insert({question, answer});
    questions.length++;
}

Questions Constant::getQuestions()
{
    return questions;
}

string Constant::getAnswer(string question){
    map <string,string>::iterator itr;
    itr = questions.questionsAnswers.find(question);
    return itr->second;
}

int Constant::getNumOfQuestions()
{
    return questions.length;
}