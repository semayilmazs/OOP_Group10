#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name, const std::string& pwd)
        : User(name, pwd) {}

std::vector<Order> Customer::viewOrderHistory() const {
    return orderHistory;
}

void Customer::addToOrderHistory(const Order& lastOrder) {
    orderHistory.push_back(lastOrder);
    std::cout << "Order added to history.\n";
}

std::string Customer::getCardInfo() const {
    return cardInfo;
}

void Customer::setCardInfo(const std::string& newInfo) {
    cardInfo = newInfo;
    std::cout << "Card information updated.\n";
}

Cart& Customer::getCart() {
    return cart;
}

Wishlist& Customer::getWishlist() {
    return wishlist;
}

std::string Customer::getAddress() const {
    return address;
}

void Customer::setAddress(const std::string& add) {
    address = add;
    std::cout << "Address updated.\n";
}

void Customer::displayInfo() const {
    std::cout << "Customer Info:\n";
    std::cout << "Username: " << username << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Number of Orders: " << orderHistory.size() << "\n";
}
#include "Customer.h"
#include <iostream>

Customer::Customer(const std::string& name, const std::string& pwd)
        : User(name, pwd) {}

std::vector<Order> Customer::viewOrderHistory() const {
    return orderHistory;
}

void Customer::addToOrderHistory(const Order& lastOrder) {
    orderHistory.push_back(lastOrder);
    std::cout << "Order added to history.\n";
}

std::string Customer::getCardInfo() const {
    return cardInfo;
}

void Customer::setCardInfo(const std::string& newInfo) {
    cardInfo = newInfo;
    std::cout << "Card information updated.\n";
}

Cart& Customer::getCart() {
    return cart;
}

Wishlist& Customer::getWishlist() {
    return wishlist;
}

std::string Customer::getAddress() const {
    return address;
}

void Customer::setAddress(const std::string& add) {
    address = add;
    std::cout << "Address updated.\n";
}

void Customer::displayInfo() const {
    std::cout << "Customer Info:\n";
    std::cout << "Username: " << username << "\n";
    std::cout << "Address: " << address << "\n";
    std::cout << "Number of Orders: " << orderHistory.size() << "\n";
}
