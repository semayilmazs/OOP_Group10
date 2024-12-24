#include "User.h"
#include <iostream>
#include <random>

User::User(const std::string& name, const std::string& pwd)
        : username(name), password(pwd) {
    // Automatically generate a unique userID
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1000, 9999);
    userID = dis(gen);
}

User::~User() {}

bool User::verification(const std::string& name, const std::string& pwd) const {
    return (username == name && password == pwd);
}
bool User::login(const std::string& inputPassword) {
    if (inputPassword == password) {
        std::cout << "User " << username << " logged in successfully.\n";
        return true;
    }
    std::cout << "Invalid password for user: " << username << "\n";
    return false;
}
void User::logout() {
    std::cout << "User " << username << " logged out.\n";
}

std::string User::getUsername() const {
    return username;
}

void User::setUsername(const std::string& name) {
    username = name;
    std::cout << "Username updated to: " << name << std::endl;
}

int User::getUserID() const {
    return userID;
}

std::string User::getPassword() const {
    return password;
}

void User::setPassword(const std::string& pwd) {
    password = pwd;
    std::cout << "Password updated successfully.\n";
}
