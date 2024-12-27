#include "User.h"
#include <QRandomGenerator>
#include <QDebug>
#include <QFile>
#include <QTextStream>

User::User(const QString& name, const QString& pwd)
    : username(name), password(pwd) {
    // Automatically generate a unique userID
    QRandomGenerator generator;
    userID = generator.bounded(1000, 10000);  // Generates a number between 1000 and 9999
}

User::~User() {}

bool User::verification(const QString& name, const QString& pwd, const QString& email) const {
    QFile file("customer.txt");
    if (!file.exists()) {
        qDebug() << "File does not exist!";
        return false;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file!";
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        // Check if the name, password, and email match
        if (fields.size() >= 5 && fields[0] == name && fields[1] == pwd && fields[2] == email) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

QString User::getUsername() const {
    return username;
}

void User::setUsername(const QString& name) {
    username = name;
    qDebug() << "Username updated to:" << name;
}

int User::getUserID() const {
    return userID;
}

QString User::getPassword() const {
    return password;
}

void User::setPassword(const QString& pwd) {
    password = pwd;
    qDebug() << "Password updated successfully.";
}

bool User::doesExist(const QString& email) const {
    QFile file("customer.txt");
    if (!file.exists()) {
        qDebug() << "File does not exist!";
        return false;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file!";
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        if (fields.size() >= 3 && fields[2] == email) {  // Assuming email is the 3rd field (index 2)
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}
