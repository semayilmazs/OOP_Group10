#include "NotificationManager.h"

void NotificationManager::sendNotification(NotificationType type, const std::string& message) {
    switch (type) {
        case NotificationType::Order:
            std::cout << "[Order Notification]: " << message << "\n";
            break;

        case NotificationType::Stock:
            std::cout << "[Stock Notification]: " << message << "\n";
            break;

        case NotificationType::Promotion:
            std::cout << "[Promotion Notification]: " << message << "\n";
            break;

        default:
            std::cout << "[Unknown Notification]: " << message << "\n";
            break;
    }
}
