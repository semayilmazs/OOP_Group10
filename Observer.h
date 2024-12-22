#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

/**
 * @brief Observer interface for notification systems.
 */
class Observer {
public:
    virtual ~Observer() = default;

    /**
     * @brief Sends a notification to the observer.
     * @param message The message to send.
     */
    virtual void update(const std::string& message) = 0;
};

#endif // OBSERVER_H
