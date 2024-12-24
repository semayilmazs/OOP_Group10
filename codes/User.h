#ifndef USER_H
#define USER_H

#include <string>

/**
 * @brief Base class representing a user in the system.
 */
class User {
protected:
    int userID;
    std::string username;
    std::string password;

public:
    /**
     * @brief Constructor for the User class.
     * @param name Username of the user.
     * @param pwd User's password.
     */
    User(const std::string& name, const std::string& pwd);

    /**
     * @brief Virtual destructor for the User class.
     */
    virtual ~User();

    /**
     * @brief Verifies the user's credentials.
     * @param name Username to verify.
     * @param pwd Password to verify.
     * @return True if credentials match, false otherwise.
     */
    bool verification(const std::string& name, const std::string& pwd) const;

    /**
     * @brief Virtual method for signing up. To be implemented by derived classes.
     */
    virtual void signup() = 0;

    /**
     * @brief Virtual method for logging in. To be implemented by derived classes.
     */
    virtual bool login(const std::string& inputPassword);
    virtual void logout();
    /**
     * @brief Gets the username.
     * @return The username as a string.
     */
    std::string getUsername() const;

    /**
     * @brief Sets the username.
     * @param name New username to set.
     */
    void setUsername(const std::string& name);

    /**
     * @brief Gets the user ID.
     * @return The user ID as an integer.
     */
    int getUserID() const;

    /**
     * @brief Gets the user's password.
     * @return The password as a string.
     */
    std::string getPassword() const;

    /**
     * @brief Sets a new password for the user.
     * @param pwd New password to set.
     */
    void setPassword(const std::string& pwd);
};

#endif // USER_H
