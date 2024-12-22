#ifndef CART_H
#define CART_H

#include "Product.h"
#include "Discount.h"
#include <vector>

/**
 * @brief Represents a shopping cart in the e-commerce system.
 */
class Cart {
private:
    std::vector<Product> items;
    float totalPrice;

    /**
     * @brief Updates the total price of the cart by recalculating all item prices.
     */
    void updateTotalPrice();

public:
    /**
     * @brief Constructor for the Cart class.
     */
    Cart();

    /**
     * @brief Adds a product to the cart.
     * @param newItem The product to add.
     */
    void addItem(const Product& newItem);

    /**
     * @brief Removes a product from the cart by index.
     * @param index The index of the product to remove.
     */
    void removeItem(int index);

    /**
     * @brief Empties all items from the cart.
     */
    void emptyCart();

    /**
     * @brief Calculates the total price of the cart with a discount applied.
     * @param discount The discount object to apply.
     * @param price The current total price of the cart.
     * @return The discounted total price.
     */
    float calculateTotal(const Discount& discount, float price);

    /**
     * @brief Prints the contents of the cart.
     */
    void printCartContents() const;

    /**
     * @brief Prints only the item names in the cart.
     */
    void printItems() const;

    /**
     * @brief Gets the current total price of the cart.
     * @return The total price as a float.
     */
    float getTotalPrice() const;
};

#endif // CART_H
