#include "Cart.h"
#include <iostream>
#include <iomanip>

Cart::Cart() : totalPrice(0.0) {}

void Cart::addItem(const Product& newItem) {
    items.push_back(newItem);
    updateTotalPrice();
    std::cout << "Added item to cart: " << newItem.getName() << " - $" << newItem.getPrice() << "\n";
}

void Cart::removeItem(int index) {
    if (index >= 0 && index < items.size()) {
        std::cout << "Removed item from cart: " << items[index].getName() << "\n";
        items.erase(items.begin() + index);
        updateTotalPrice();
    } else {
        std::cout << "Invalid index. Unable to remove item.\n";
    }
}

void Cart::emptyCart() {
    items.clear();
    totalPrice = 0.0;
    std::cout << "Cart emptied.\n";
}

float Cart::calculateTotal(const Discount& discount, float price) {
    float discountedPrice = discount.applyDiscount(price);
    std::cout << "Discount applied. Total after discount: $" << std::fixed << std::setprecision(2) << discountedPrice << "\n";
    return discountedPrice;
}

void Cart::printCartContents() const {
    std::cout << "Cart Contents:\n";
    if (items.empty()) {
        std::cout << "Your cart is empty.\n";
        return;
    }
    for (const auto& item : items) {
        std::cout << "- " << item.getName() << " - $" << std::fixed << std::setprecision(2) << item.getPrice() << "\n";
    }
    std::cout << "Total Price: $" << std::fixed << std::setprecision(2) << totalPrice << "\n";
}

void Cart::printItems() const {
    std::cout << "Items in cart:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.getName() << "\n";
    }
}

float Cart::getTotalPrice() const {
    return totalPrice;
}

void Cart::updateTotalPrice() {
    totalPrice = 0.0;
    for (const auto& item : items) {
        totalPrice += item.getPrice();
    }
}
