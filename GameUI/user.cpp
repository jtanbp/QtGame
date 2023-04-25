#include "user.h"

User::User(std::string fName, std::string lName, std::string username, std::string dob)
{
    this -> firstName = fName;
    this -> lastName = lName;
    this -> userName = username;
    this -> dateOfBirth = dob;
}

std::string User::getDoB() {
    return this -> dateOfBirth;
}

int User::getRanking() {
    return this -> ranking;
}

Score User::getHighScore() {
    return this -> highScore;
}

void User::updateHighScore(Score score) {
    this -> highScore = score;
}

void User::updateRanking() {

}

std::vector<Score> User::getScoreHistory() {
    return this -> scoreHistory;
}