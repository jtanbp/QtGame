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
    int getHighScore(); // Change Score to int
    void updateHighScore(int score); // Change Score to int
    void updateRanking();
    std::vector<int> getScoreHistory(); // Change Score to int
    void updateScoreHistory(int score); // Add this line
    void saveScoreData(); // Add this line
};

#endif // USER_H
