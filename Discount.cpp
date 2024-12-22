#include "Discount.h"
#include <iostream>

Discount::Discount() : discountPercentage(0.0) {
    discountType.push_back("Seasonal");
    discountType.push_back("Clearance");
    discountType.push_back("BuyOneGetOne");
    discountType.push_back("Loyalty");
}

float Discount::applyDiscount(float totalPrice) const {
    float discountedPrice = totalPrice - (totalPrice * discountPercentage / 100);
    std::cout << "Original Price: $" << totalPrice << "\n";
    std::cout << "Discount Applied: " << discountPercentage << "%\n";
    std::cout << "Discounted Price: $" << discountedPrice << "\n";
    return discountedPrice;
}

float Discount::getDiscountPercentage() const {
    return discountPercentage;
}

void Discount::setDiscountPercentage(float newPer) {
    if (newPer < 0.0 || newPer > 100.0) {
        std::cout << "Invalid discount percentage. Please set a value between 0 and 100.\n";
    } else {
        discountPercentage = newPer;
        std::cout << "Discount percentage updated to: " << discountPercentage << "%\n";
    }
}
