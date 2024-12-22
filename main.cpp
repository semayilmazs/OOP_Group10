#include "SessionManager.h"
#include "NotificationManager.h"
#include "PasswordManager.h"
#include "Customer.h"

int main() {
    // Initialize managers
    SessionManager sessionManager;
    NotificationManager notificationManager;

    // Create a customer
    Customer* user1 = new Customer("john_doe", PasswordManager::hashPassword("password123"));

    // Simulate login
    std::string sessionID = sessionManager.loginUser(user1);

    // Send notifications
    notificationManager.sendNotification(NotificationType::Order, "Your order has been shipped!");
    notificationManager.sendNotification(NotificationType::Stock, "Stock for 'Laptop' is running low!");
    notificationManager.sendNotification(NotificationType::Promotion, "Special promotion: 20% off on all smartphones!");

    // Simulate logout
    sessionManager.logoutUser(sessionID);

    delete user1;

    return 0;
}
