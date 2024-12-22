#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include "User.h"
#include <unordered_map>
#include <string>

/**
 * @brief Manages user sessions for the application.
 */
class SessionManager {
private:
    std::unordered_map<std::string, User*> activeSessions; // Maps session IDs to Users

    /**
     * @brief Generates a unique session ID.
     * @return A unique session ID string.
     */
    std::string generateSessionID() const;

public:
    /**
     * @brief Logs in a user and creates a session.
     * @param user Pointer to the user object.
     * @return The generated session ID.
     */
    std::string loginUser(User* user);

    /**
     * @brief Logs out a user and removes the session.
     * @param sessionID The session ID to remove.
     */
    void logoutUser(const std::string& sessionID);

    /**
     * @brief Checks if a session is active.
     * @param sessionID The session ID to check.
     * @return True if the session is active, false otherwise.
     */
    bool isSessionActive(const std::string& sessionID) const;
};

#endif // SESSIONMANAGER_H
