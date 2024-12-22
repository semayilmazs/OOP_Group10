#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <string>
#include <iostream>

/**
 * @brief Enum representing different notification types.
 */
enum class NotificationType {
    Order,
    Stock,
    Promotion
};

/**
 * @brief Manages notifications for various events.
 */
class NotificationManager {
public:
    /**
     * @brief Sends a notification based on its type.
     * @param type The type of the notification.
     * @param message The message to send.
     */
    void sendNotification(NotificationType type, const std::string& message);
};

#endif // NOTIFICATIONMANAGER_H
