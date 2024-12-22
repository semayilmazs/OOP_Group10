#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H

#include <string>

/**
 * @brief Handles password security and recovery.
 */
class PasswordManager {
public:
    /**
     * @brief Hashes a password.
     * @param password The password to hash.
     * @return The hashed password.
     */
    static std::string hashPassword(const std::string& password);

    /**
     * @brief Validates a password against a hash.
     * @param password The plain password.
     * @param hash The hashed password.
     * @return True if the password matches the hash, false otherwise.
     */
    static bool validatePassword(const std::string& password, const std::string& hash);
};

#endif // PASSWORDMANAGER_H
