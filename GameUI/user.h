#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

struct Score {
    int score;
    std::string date;
    int count;
};

class User
{
public:
    User(std::string fName, std::string lName, std::string username, std::string dob);
    std::string firstName;
    std::string lastName;
    std::string userName;
    std::string getDoB();
    int getRanking();
    Score getHighScore();
    void updateHighScore(Score score);
    void updateRanking();
    std::vector<Score> getScoreHistory();

private:
    std::string dateOfBirth;
    Score highScore;
    int ranking;
    std::vector<Score> scoreHistory;
};

#endif // USER_H
