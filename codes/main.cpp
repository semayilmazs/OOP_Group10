#include "SessionManager.h"
#include "NotificationManager.h"
#include "AuthenticationManager.h"
#include "UserLoader.h"
#include "Customer.h"
#include "Seller.h"

int main() {
    // Initialize managers
    AuthenticationManager authManager;
    SessionManager sessionManager;
    NotificationManager notificationManager;

    // Load users from file
    auto users = UserLoader::loadUsersFromFile("users.txt");
    for (auto* user : users) {
        authManager.registerUser(user);
    }

    // Simulate login
    std::string username, password;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    User* loggedInUser = authManager.loginUser(username, password);
    if (loggedInUser) {
        // Check user type and provide specific messages
        if (dynamic_cast<Customer*>(loggedInUser)) {
            std::cout << "Customer-specific features available now.\n";
        } else if (dynamic_cast<Seller*>(loggedInUser)) {
            std::cout << "Seller-specific features available now.\n";
        }

        // Start session
        std::string sessionID = sessionManager.loginUser(loggedInUser);

        // Send notifications
        notificationManager.sendNotification(NotificationType::Order, "Your order has been shipped!");
        notificationManager.sendNotification(NotificationType::Stock, "Stock for 'Laptop' is running low!");
        notificationManager.sendNotification(NotificationType::Promotion, "Special promotion: 20% off on all smartphones!");

        // Simulate logout
        sessionManager.logoutUser(sessionID);
        loggedInUser->logout();
    } else {
        std::cout << "Login failed. Please check your credentials.\n";
    }

    // Clean up dynamically allocated users
    for (auto* user : users) {
        delete user;
    }

    return 0;
}
