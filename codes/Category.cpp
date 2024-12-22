#include "Category.h"
#include <iostream>

Category::Category(const std::string& name) : name(name) {}

void Category::addProduct(Product* product) {
    products.push_back(product);
    std::cout << "Product added to category \"" << name << "\": " << product->getName() << "\n";
}

void Category::removeProduct(int index) {
    if (index >= 0 && index < products.size()) {
        std::cout << "Product removed from category \"" << name << "\": " << products[index]->getName() << "\n";
        products.erase(products.begin() + index);
    } else {
        std::cout << "Invalid index. Unable to remove product.\n";
    }
}

void Category::printProducts() const {
    std::cout << "Products in category \"" << name << "\":\n";
    if (products.empty()) {
        std::cout << "No products in this category.\n";
        return;
    }
    for (size_t i = 0; i < products.size(); ++i) {
        std::cout << i + 1 << ". " << products[i]->getName() << " - $" << products[i]->getPrice() << "\n";
    }
}

std::string Category::getName() const {
    return name;
}
