#include "Quiz.h"

Quiz::Quiz(std::vector<std::string> q, std::vector<std::string> a, int playerCount) : playerScores(playerCount,0)
{
    questions = q;
    answers = a;
}

Quiz::~Quiz()
{
}

bool Quiz::checkAnswer(std::string selectedAnswer)
{
    return answers.front() == selectedAnswer;
}

std::string Quiz::getNextQuestion()
{
    //Removes the current question and correct answer from vectors
    questions.erase(questions.begin());
    answers.erase(answers.begin());

    //Returns next question
    return questions.front();
}

void Quiz::updatePlayerScore(int player)
{
    playerScores[player - 1] += 1;
}

std::vector<std::string> Quiz::getQuestionList()
{
    return questions;
}
std::vector<std::string> Quiz::getAnswersList()
{
    return answers;
}
std::vector<int> Quiz::getplayerScores()
{
    return playerScores;
}