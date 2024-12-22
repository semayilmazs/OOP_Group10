#include "SessionManager.h"
#include <iostream>
#include <random>

std::string SessionManager::generateSessionID() const {
    static const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string sessionID;
    for (int i = 0; i < 16; ++i) {
        sessionID += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return sessionID; // Her durumda bir session ID döndür.
}


std::string SessionManager::loginUser(User* user) {
    std::string sessionID = generateSessionID();
    activeSessions[sessionID] = user;
    std::cout << "User " << user->getUsername() << " logged in with session ID: " << sessionID << "\n";
    return sessionID;
}

void SessionManager::logoutUser(const std::string& sessionID) {
    if (activeSessions.erase(sessionID) > 0) {
        std::cout << "Session " << sessionID << " logged out successfully.\n";
    } else {
        std::cout << "Invalid session ID: " << sessionID << "\n";
    }
}

bool SessionManager::isSessionActive(const std::string& sessionID) const {
    return activeSessions.find(sessionID) != activeSessions.end();
}
