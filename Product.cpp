#include "Product.h"
#include <iostream>
#include <sstream>
#include <random>

Product::Product(const std::string& nm, int stck, float prc, Category* ctgry)
        : name(nm), stock(stck), price(prc), category(ctgry) {
    // Automatically generate a unique productID
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10000, 99999);
    productID = dis(gen);
}

std::string Product::displayProductInfo() const {
    std::ostringstream info;
    info << "Product ID: " << productID << "\n"
         << "Name: " << name << "\n"
         << "Explanation: " << explanation << "\n"
         << "Price: $" << price << "\n"
         << "Stock: " << stock << "\n"
         << "Category: " << (category ? category->getName() : "None") << "\n";
    return info.str();
}

void Product::setExplanation(const std::string& newExp) {
    explanation = newExp;
    std::cout << "Explanation updated.\n";
}

std::string Product::getExplanation() const {
    return explanation;
}

void Product::setPrice(float newPrice) {
    price = newPrice;
    std::cout << "Price updated to: $" << price << "\n";
}

float Product::getPrice() const {
    return price;
}

void Product::setName(const std::string& newName) {
    name = newName;
    std::cout << "Name updated to: " << name << "\n";
}

std::string Product::getName() const {
    return name;
}

void Product::setStock(int newStock) {
    stock = newStock;
    std::cout << "Stock updated to: " << stock << "\n";
}

int Product::getStock() const {
    return stock;
}

void Product::setCategory(Category* newCategory) {
    category = newCategory;
    std::cout << "Category updated to: " << (category ? category->getName() : "None") << "\n";
}

Category* Product::getCategory() const {
    return category;
}
