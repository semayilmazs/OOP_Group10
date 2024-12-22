#include "AuthenticationManager.h"
#include <iostream>

bool AuthenticationManager::registerUser(User* user) {
    if (findUserByUsername(user->getUsername())) {
        std::cout << "Error: Username " << user->getUsername() << " is already taken.\n";
        return false;
    }
    registeredUsers.push_back(user);
    std::cout << "User " << user->getUsername() << " registered successfully.\n";
    return true; // Tüm durumlar için bir return eklenmeli.
}

User* AuthenticationManager::findUserByUsername(const std::string& username) const {
    for (const auto& user : registeredUsers) {
        if (user->getUsername() == username) {
            return user;
        }
    }
    return nullptr; // Eğer kullanıcı bulunamazsa nullptr döndür.
}
