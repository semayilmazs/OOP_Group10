#ifndef WISHLIST_H
#define WISHLIST_H

#include "Product.h"
#include <vector>

/**
 * @brief Represents a wishlist in the e-commerce system.
 */
class Wishlist {
private:
    std::vector<Product> wishlistItems;

public:
    /**
     * @brief Adds a product to the wishlist.
     * @param product The product to add.
     */
    void addItem(const Product& product);

    /**
     * @brief Removes a product from the wishlist by index.
     * @param index The index of the product to remove.
     */
    void removeItem(int index);

    /**
     * @brief Prints all items in the wishlist.
     */
    void printWishlist() const;
};

#endif // WISHLIST_H
