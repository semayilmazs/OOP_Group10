/**
 * @file Customer.cpp
 * @brief Implementation of the Customer class.
 *
 * The Customer class extends the User class to add functionality specific to customers,
 * such as managing card information, address, and performing signup and login operations.
 */
#include "Customer.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
/**
 * @brief Constructor for the Customer class.
 *
 * Initializes a Customer object with the given username and password.
 *
 * @param name Username of the customer.
 * @param pwd Password of the customer.
 */
Customer::Customer(const QString& name, const QString& pwd)
    : User(name, pwd) {}
/**
 * @brief Gets the card information of the customer.
 *
 * @return The card information as a QString.
 */
QString Customer::getCardInfo() const {
    return cardInfo;
}
/**
 * @brief Sets the card information for the customer.
 *
 * Updates the card information and logs the change.
 *
 * @param newInfo The new card information to set.
 */
void Customer::setCardInfo(const QString& newInfo) {
    cardInfo = newInfo;
    qDebug() << "Card information updated.";
}
/**
 * @brief Gets the address of the customer.
 *
 * @return The address as a QString.
 */
QString Customer::getAddress() const {
    return address;
}
/**
 * @brief Sets the address for the customer.
 *
 * Updates the address and logs the change.
 *
 * @param add The new address to set.
 */
void Customer::setAddress(const QString& add) {
    address = add;
    qDebug() << "Address updated.";
}
/**
 * @brief Displays the customer's information.
 *
 * Logs the customer's username and address details to the console.
 */
void Customer::displayInfo() const {
    qDebug() << "Customer Info:";
    qDebug() << "Username:" << username;
    qDebug() << "Address:" << address;
}
/**
 * @brief Registers a new customer.
 *
 * Checks if the username and password already exist in the "customer.txt" file.
 * If not, appends the new customer's details to the file.
 */
void Customer::signup() {
    QFile file("customer.txt");
    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;
        bool userExists = false;

        // Check if the username and password exist in the file
        while (!in.atEnd()) {
            line = in.readLine();
            QStringList userInfo = line.split(',');

            if (userInfo.size() >= 2 && userInfo[0] == username && userInfo[1] == password) {
                userExists = true;
                break;
            }
        }

        // If user exists, print message (could also return false or handle differently)
        if (userExists) {
            qDebug() << "User already exists. Please choose a different username or password.";
        } else {
            // If user doesn't exist, append to the file
            in.seek(0); // Move the file pointer to the beginning
            QTextStream out(&file);
            out << username << "," << password << "," << cardInfo << "," << address << "\n";
            qDebug() << "New user successfully signed up!";
        }

        file.close();
    } else {
        qDebug() << "Failed to open customer.txt for reading and writing.";
    }
}
/**
 * @brief Logs in an existing customer.
 *
 * Verifies the username and password against the entries in the "customer.txt" file.
 */

// Implementation of the login function
void Customer::login() {
    QFile file("customer.txt");

    // Check if the file exists and is readable
    if (!file.exists()) {
        qDebug() << "File does not exist!";
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open customer.txt for reading.";
        return;
    }

    QTextStream in(&file);
    QString line;
    bool userFound = false;

    // Check if the username and password match any entry in the file
    while (!in.atEnd()) {
        line = in.readLine();
        QStringList userInfo = line.split(',');

        if (userInfo.size() >= 2 && userInfo[0] == username && userInfo[1] == password) {
            userFound = true;
            break;
        }
    }

    if (userFound) {
        qDebug() << "Login successful!";
    } else {
        qDebug() << "Invalid username or password!";
    }

    file.close();
}
