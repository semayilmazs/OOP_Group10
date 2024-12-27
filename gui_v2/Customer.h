#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

/**
 * @brief Derived class representing a customer in the system.
 */
class Customer : public User {
private:
    QString cardInfo;
    QString address;

public:
    /**
     * @brief Constructor for the Customer class.
     * @param name Username for the customer.
     * @param pwd Password for the customer.
     */
    Customer(const QString& name, const QString& pwd);

    /**
     * @brief Gets the customer's card information.
     * @return The card information as a QString.
     */
    QString getCardInfo() const;

    /**
     * @brief Sets new card information for the customer.
     * @param newInfo The new card information to set.
     */
    void setCardInfo(const QString& newInfo);

    /**
     * @brief Gets the customer's address.
     * @return The address as a QString.
     */
    QString getAddress() const;

    /**
     * @brief Sets the customer's address.
     * @param add The new address to set.
     */
    void setAddress(const QString& add);

    void displayInfo() const;

    /**
     * @brief signup function is overriden from User class
     */
    void signup() override;

    /**
     * @brief login function is overriden from User class
     */
    void login() override;
};

#endif // CUSTOMER_H
