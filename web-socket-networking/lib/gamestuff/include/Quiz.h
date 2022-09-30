#include <vector>
#include <string>

class Quiz
{
    private:
        //Stores a list of questions with their correct answers
        std::vector<std::string> questions;
        std::vector<std::string> answers;
        //Player Scores
        std::vector<int> playerScores;
    public:
        //Constructor/destructors
        Quiz(std::vector<std::string> q, std::vector<std::string> a, int playerCount);
        ~Quiz();
        
        bool checkAnswer(std::string selectedAnswer);
        std::string getNextQuestion();
        void updatePlayerScore(int player);
        //Getters
        std::vector<std::string> getQuestionList();
        std::vector<std::string> getAnswersList();
        std::vector<int> getplayerScores();
};
