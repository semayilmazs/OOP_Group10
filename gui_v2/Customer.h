#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <QVector>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

/**
 * @class Customer
 * @brief Derived class representing a customer in the system.
 *
 * The Customer class extends the User class, adding specific
 * attributes and methods related to customer functionality,
 * such as managing card information and address details.
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
     *
     * Retrieves the current card information stored for the customer.
     *
     * @return The card information as a QString.
     */
    QString getCardInfo() const;

    /**
     * @brief Sets new card information for the customer.
     *
     * Updates the customer's card information with the provided value.
     *
     * @param newInfo The new card information to set.
     */
    void setCardInfo(const QString& newInfo);

    /**
     * @brief Gets the customer's address.
     *
     * Retrieves the address stored for the customer.
     *
     * @return The address as a QString.
     */
    QString getAddress() const;

    /**
     * @brief Sets the customer's address.
     *
     * Updates the address information for the customer.
     *
     * @param add The new address to set.
     */
    void setAddress(const QString& add);
    /**
     * @brief Displays the customer's information.
     *
     * Logs the customer's username and address details to the console.
     */
    void displayInfo() const;

   /**
     * @brief Signs up a new customer.
     *
     * Checks if the username and password already exist in the system.
     * If not, adds the new customer's details to the storage.
     *
     * @override
     */
    void signup() override;

    /**
     * @brief Logs in an existing customer.
     *
     * Verifies the customer's credentials against the stored data.
     *
     * @override
     */
    void login() override;
};

#endif // CUSTOMER_H
