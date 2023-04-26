#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <map>
#include <functional>
#include "user.h"
#include <iostream>
#include <fstream>
#include <QFile>
#include <QTextStream>
#include <vector>

class Utility
{
public:
    std::vector<User> static getUserList() {
        std::vector<User> userList;
        QFile file(":/images/userData.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return userList;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("FirstName,LastName,UserName,DateOfBirth")) {
                continue; // Skip header line
            }
            QStringList parts = line.split(",");
            if (parts.size() == 4) {
                std::string firstName = parts[0].toStdString();
                std::string lastName = parts[1].toStdString();
                std::string userName = parts[2].toStdString();
                std::string dateofBirth = parts[3].toStdString();
                User newUser = User(firstName, lastName, userName, dateofBirth);
                userList.push_back(newUser);
            }
        }
        file.close();
        return userList;
    }

    std::vector<User> static getUserScoreList()
    {
        std::vector<User> scoreList;
        QFile file(":/images/leaderboard.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            // Handle error (e.g., show an error message)
            return scoreList;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("UserName,HighScore,Ranking,Score0,Score1,Score2,Score3,Score4")) {
                continue; // Skip header line
            }
            QStringList parts = line.split(",");
            if (parts.size() == 7) {
                            User user(parts[0].toStdString());
                            user.highScore = parts[1].toInt();
                            user.ranking = parts[2].toInt();
                            user.scoreHistory[0] = parts[3].toInt();
                            user.scoreHistory[0] = parts[4].toInt();
                            user.scoreHistory[0] = parts[5].toInt();
                            user.scoreHistory[0] = parts[6].toInt();
                            user.scoreHistory[0] = parts[7].toInt();

                            scoreList.push_back(user);
            }
        }
        file.close();
        return scoreList;
    }

    std::tuple<size_t, size_t> static Encrypt(User user, std::string password) {
        std::string userString = user.firstName + user.lastName + user.userName + user.dateOfBirth + password;
        std::hash<std::string> stdHash;
        size_t userPassHash = stdHash(userString);
        size_t passHash = stdHash(password);

        return {userPassHash, passHash};
    }

    bool static AuthenticateUser(User user, std::string password, bool addUser) {
        //get user details
        std::vector<User> userList = getUserList();

        if (addUser) {
            for (User userData: userList) {
                if (userData.userName == user.userName) {
                    //username already exist
                    return true;
                }
            }
            return false;
        }
        else {
            bool userPresent = false;
            for (User userData: userList) {
                if (user.userName == userData.userName) {
                    user.firstName = userData.firstName;
                    user.lastName = userData.lastName;
                    user.dateOfBirth = userData.dateOfBirth;
                    userPresent = true;
                    break;
                }
            }
            if (!userPresent) return false;
        }

        //Reading all values from the password database
        size_t hashTable[10000][2];

        QFile file(":/images/passwordMap.txt");
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            return false;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line.startsWith("UserHash,UserPassHash,PasswordHash")) {
                continue; // Skip header line
            }
            QStringList parts = line.split(",");
            if (parts.size() == 3) {
                size_t hashIndex = parts[0].toULongLong(); //user hash
                size_t hash1Value = parts[1].toULongLong(); //user + pass hash
                size_t hash2Value = parts[2].toULongLong(); //password hash
                hashTable[hashIndex][0] = hash1Value;
                hashTable[hashIndex][1] = hash2Value;
            }
        }
        file.close();

        //checking if the password is correct
        std::hash<std::string> stdHash;
        size_t userHash = stdHash(user.firstName + user.lastName + user.userName + user.dateOfBirth) % 10000;

        auto encrypt = Encrypt(user, password);
        size_t userPassHash = std::get<0>(encrypt);
        size_t passHash = std::get<1>(encrypt);
        if (hashTable[userHash][0] == userPassHash && hashTable[userHash][1] == passHash) {
            return true;
        }
        return false;
    }

    bool static AddUser(User user, std::string password) {
        if (AuthenticateUser(user, password, true)) {
            //user already exist
            return false;
        }

        AddToMap(user, password);

        std::ofstream file(":/images/userData.txt", std::ios_base::app);
        file << user.firstName << "," << user.lastName << "," << user.userName << "," << user.dateOfBirth << "\n";
        file.close();
        return true;
    }

    void static AddToMap(User user, std::string password) {
        std::hash<std::string> stdHash;
        size_t userHash = stdHash(user.firstName + user.lastName + user.userName + user.dateOfBirth) % 10000;

        auto encrypt = Encrypt(user, password);
        size_t userPassHash = std::get<0>(encrypt);
        size_t passHash = std::get<1>(encrypt);

        std::ofstream file;
        file.open(":/images/passwordMap.txt", std::ios_base::app);
        file << userHash << "," << userPassHash << "," << passHash << "\n";

        file.close();
    }
};



#endif // UTILITY_H
