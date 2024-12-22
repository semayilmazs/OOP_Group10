#ifndef AUTHENTICATIONMANAGER_H
#define AUTHENTICATIONMANAGER_H

#include "User.h"
#include <vector>

/**
 * @brief Manages user authentication, including signup and login.
 */
class AuthenticationManager {
private:
    std::vector<User*> registeredUsers;

public:
    /**
     * @brief Registers a new user.
     * @param user Pointer to the user object.
     * @return True if the registration is successful, false otherwise.
     */
    bool registerUser(User* user);

    /**
     * @brief Finds a user by username.
     * @param username The username to search for.
     * @return Pointer to the User if found, nullptr otherwise.
     */
    User* findUserByUsername(const std::string& username) const;
};

#endif // AUTHENTICATIONMANAGER_H
