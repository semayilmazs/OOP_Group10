#include "Customer.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>

Customer::Customer(const QString& name, const QString& pwd)
    : User(name, pwd) {}

QString Customer::getCardInfo() const {
    return cardInfo;
}

void Customer::setCardInfo(const QString& newInfo) {
    cardInfo = newInfo;
    qDebug() << "Card information updated.";
}

QString Customer::getAddress() const {
    return address;
}

void Customer::setAddress(const QString& add) {
    address = add;
    qDebug() << "Address updated.";
}

void Customer::displayInfo() const {
    qDebug() << "Customer Info:";
    qDebug() << "Username:" << username;
    qDebug() << "Address:" << address;
}

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
