#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include <unordered_map>
#include <functional>
#include "user.h"

class Utility
{
public:
    std::unordered_map<size_t, size_t> passwordMap;

    std::tuple<size_t, size_t> Encrypt(User user, std::string password) {
        std::string userString = user.firstName + user.lastName + user.userName + user.getDoB() + password;
        std::hash<std::string> stdHash;
        size_t userHash = stdHash(userString);
        size_t passHash = stdHash(password);

        return {userHash, passHash};
    }

    bool AuthenticateUser(User user, std::string password) {
        auto encrypt = Encrypt(user, password);
        size_t userHash = std::get<0>(encrypt);
        size_t passHash = std::get<1>(encrypt);
        if (passwordMap.find(userHash) == passwordMap.end()) return false;
        return passwordMap[userHash] == passHash;
    }

    bool AddUser(User user, std::string password) {
        return false;
    }

    bool AddToMap(User user, std::string password) {
        auto encrypt = Encrypt(user, password);
        size_t userHash = std::get<0>(encrypt);
        size_t passHash = std::get<1>(encrypt);
        if (passwordMap.find(userHash) == passwordMap.end()) {
            passwordMap.insert(userHash, passHash);
            return true;
        }
        return false;
    }
};

#endif // UTILITY_H
