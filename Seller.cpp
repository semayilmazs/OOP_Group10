#include "Seller.h"
#include <iostream>

Seller::Seller(const std::string& name, const std::string& pwd)
        : User(name, pwd) {}

void Seller::addProduct(const Product& product) {
    productsForSale.push_back(product);
    std::cout << "Product added: " << product.getName() << "\n";
}

void Seller::removeProduct(int index) {
    if (index >= 0 && index < productsForSale.size()) {
        productsForSale.erase(productsForSale.begin() + index);
        std::cout << "Product removed from catalog.\n";
    } else {
        std::cout << "Invalid index.\n";
    }
}

void Seller::printSalesHistory() const {
    std::cout << "Sales History:\n";
    for (const auto& order : soldProducts) {
        order.displayOrder();
    }
}

void Seller::addToSoldProducts(const Order& order) {
    soldProducts.push_back(order);
    std::cout << "Order added to sales history.\n";
}

void Seller::displayInfo() const {
    std::cout << "Seller Info:\n";
    std::cout << "Username: " << username << "\n";
    std::cout << "Number of Products for Sale: " << productsForSale.size() << "\n";
    std::cout << "Number of Orders Sold: " << soldProducts.size() << "\n";
}
