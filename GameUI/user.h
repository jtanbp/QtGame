#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User
{
public:
    User(std::string fName, std::string lName, std::string username, std::string dob);
    User(std::string username);
    std::string firstName;
    std::string lastName;
    std::string userName;
    std::string dateOfBirth;
    int highScore = 0;
    int ranking = 0;
    std::vector<int> scoreHistory {0, 0, 0, 0, 0};
//    Score getHighScore();
//    void updateHighScore(Score score);
//    void updateRanking();
//    std::vector<Score> getScoreHistory();
};

#endif // USER_H
