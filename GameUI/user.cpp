#include "user.h"
#include <fstream>

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
    std::ofstream file("/Users/junmingjin/MSD/CS6015/QTG/QtGame/GameUI/score.txt", std::ios_base::app);
    file << this->userName << "," << this->highScore << ",";
    for (int i = 0; i < this->scoreHistory.size(); ++i) {
        file << this->scoreHistory[i];
        if (i < this->scoreHistory.size() - 1) {
            file << ",";
        }
    }
    file << "\n";
    file.close();
}

