#include "Wishlist.h"
#include <iostream>

void Wishlist::addItem(const Product& product) {
    wishlistItems.push_back(product);
    std::cout << "Added to wishlist: " << product.getName() << "\n";
}

void Wishlist::removeItem(int index) {
    if (index >= 0 && index < wishlistItems.size()) {
        std::cout << "Removed from wishlist: " << wishlistItems[index].getName() << "\n";
        wishlistItems.erase(wishlistItems.begin() + index);
    } else {
        std::cout << "Invalid index. Unable to remove item.\n";
    }
}

void Wishlist::printWishlist() const {
    std::cout << "Wishlist Contents:\n";
    if (wishlistItems.empty()) {
        std::cout << "Your wishlist is empty.\n";
        return;
    }
    for (size_t i = 0; i < wishlistItems.size(); ++i) {
        std::cout << i + 1 << ". " << wishlistItems[i].getName()
                  << " - $" << wishlistItems[i].getPrice() << "\n";
    }
}
