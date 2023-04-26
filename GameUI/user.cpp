#include "user.h"
#include <fstream>
#include "Utility.h"

User::User(std::string fName, std::string lName, std::string username, std::string dob)
{
    this -> firstName = fName;
    this -> lastName = lName;
    this -> userName = username;
    this -> dateOfBirth = dob;
}

User::User(std::string username)
{
    this -> userName = username;
}

void User::updateHighScore(int score) {
    if (score > this->highScore) {
        this->highScore = score;
    }
}

void User::updateScoreHistory(int score) {
    this->scoreHistory.push_back(score);
    if (this->scoreHistory.size() > 5) {
        this->scoreHistory.erase(this->scoreHistory.begin());
    }
}

void User::saveScoreData() {
    int oldRanking = 0;
    this -> ranking = 1;

    std::vector<User> scoreList = Utility::getUserScoreList();
    for (User userData: scoreList) {
        if (this->userName == userData.userName) {
            userData.highScore = this->highScore;
            userData.scoreHistory = this -> scoreHistory;
            oldRanking = userData.ranking;
        }
        if (this -> highScore < userData.highScore) {
            this -> ranking++;
        }
    }

    if (oldRanking > 0 && oldRanking != this -> ranking) {
        scoreList.erase(scoreList.begin() + oldRanking - 1);
        scoreList.insert(scoreList.begin() + this -> ranking - 1, *this);
    }
    else {
        scoreList.insert(scoreList.begin() + this -> ranking - 1, *this);
    }

    std::ofstream file(":/images/userData.txt", std::ios_base::app);
    for (User user: scoreList) {
        file << user.userName << "," << user.highScore << "," << user.ranking << "," << user.scoreHistory[0] << "," << user.scoreHistory[1] << "," << user.scoreHistory[2] << "," << user.scoreHistory[3] << "," << user.scoreHistory[4] <<"\n";
    }
    file.close();
}

