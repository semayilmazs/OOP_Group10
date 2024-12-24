#include "Product.h"

Product::Product(const std::string& name, double price, const std::string& description, int stock)
    : name(name), price(price), description(description), stock(stock) {}

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}

std::string Product::getDescription() const {
    return description;
}
int Product::getStock() const {
    return stock;
}

void Product::reduceStock(int quantity) {
    if (stock >= quantity) {
        stock -= quantity;
    }
}

void Product::increaseStock(int quantity) {
    stock += quantity;
}
