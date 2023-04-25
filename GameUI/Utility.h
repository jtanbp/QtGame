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
    std::hash<std::string> static stdHash;
    std::map<size_t, size_t> static passwordMap;

    std::vector<User> static getUserList() {
        std::vector<User> userList;
        QFile file("/Users/avishekchoudhury/Desktop/Project/QtGame/GameUI/userData.txt");
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
                std::string firstName = parts[0].trimmed().toStdString();
                std::string lastName = parts[1].trimmed().toStdString();
                std::string userName = parts[2].trimmed().toStdString();
                std::string dateofBirth = parts[3].trimmed().toStdString();
                User newUser = User(firstName, lastName, userName, dateofBirth);
                userList.push_back(newUser);
            }
        }
        file.close();
        return userList;
    }

    std::tuple<size_t, size_t> static Encrypt(User user, std::string password) {
        std::string userString = user.firstName + user.lastName + user.userName + user.dateOfBirth + password;
//        std::hash<std::string> stdHash;
        size_t userHash = stdHash(userString);
        size_t passHash = stdHash(password);

        return {userHash, passHash};
    }

    bool static AuthenticateUser(User user, std::string password, bool addUser) {
        //get user details
        std::vector<User> userList = getUserList();

        if (addUser) {
            for (User userData: userList) {
                if (user.firstName == userData.firstName && user.lastName == userData.lastName && user.userName == user.userName && user.dateOfBirth == user.dateOfBirth) {
                    //user already exist
                    return true;
                }
            }
        }
        else {
            bool userPresent = false;
            for (User userData: userList) {
                if (user.userName == user.userName) {
                    user.firstName = userData.firstName;
                    user.lastName = userData.lastName;
                    user.dateOfBirth = userData.dateOfBirth;
                    userPresent = true;
                    break;
                }
            }
            if (!userPresent) return false;
        }


        size_t hashTable[10000][2];

        size_t userHash = stdHash(user.firstName + user.lastName + user.userName + user.dateOfBirth) % 10000;

        auto encrypt = Encrypt(user, password);
        size_t userPassHash = std::get<0>(encrypt);
        size_t passHash = std::get<1>(encrypt);

        QFile file("/Users/avishekchoudhury/Desktop/Project/QtGame/GameUI/passwordMap.txt");
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
                int hashIndex = parts[0].trimmed().toInt();
                int hash1Value = parts[0].trimmed().toInt();
                int hash2Value = parts[1].trimmed().toInt();
                hashTable[hashIndex][0] = hash1Value;
                hashTable[hashIndex][1] = hash2Value;
            }
        }
        file.close();

        if (hashTable[userHash][0] == userPassHash && hashTable[userHash][1] == passHash) {
            return true;
        }
        return false;
    }

    bool static AddUser(User user, std::string password) {
        if (AuthenticateUser(user, password, true)) {
            //user already present
            return false;
        }

        AddToMap(user, password);

        std::ofstream file("/Users/avishekchoudhury/Desktop/Project/QtGame/GameUI/userData.txt", std::ios_base::app);
        file << user.firstName << "," << user.lastName << "," << user.userName << "," << user.dateOfBirth << "\n";
        file.close();
        return true;
    }

    void static AddToMap(User user, std::string password) {
//        std::hash<std::string> stdHash;
        size_t userHash = stdHash(user.firstName + user.lastName + user.userName + user.dateOfBirth) % 10000;

        auto encrypt = Encrypt(user, password);
        size_t userPassHash = std::get<0>(encrypt);
        size_t passHash = std::get<1>(encrypt);

        std::ofstream file;
        file.open("/Users/avishekchoudhury/Desktop/Project/QtGame/GameUI/passwordMap.txt", std::ios_base::app);
        file << userHash << "," << userPassHash << "," << "," << passHash << "\n";

        file.close();
    }
};

#endif // UTILITY_H
