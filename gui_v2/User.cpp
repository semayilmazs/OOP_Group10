#include "User.h"
#include <QRandomGenerator>
#include <QDebug>

User::User(const QString& name, const QString& pwd)
    : username(name), password(pwd) {
    // Automatically generate a unique userID
    QRandomGenerator generator;
    userID = generator.bounded(1000, 10000);  // Generates a number between 1000 and 9999
}

User::~User() {}

bool User::verification(const QString& name, const QString& pwd) const {
    return (username == name && password == pwd);
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
