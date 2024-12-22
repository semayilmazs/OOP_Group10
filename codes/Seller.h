#ifndef SELLER_H
#define SELLER_H

#include "User.h"
#include "Product.h"
#include "Order.h"
#include <vector>
#include <string>

/**
 * @brief Derived class representing a seller in the system.
 */
class Seller : public User {
private:
    std::vector<Product> productsForSale;
    std::vector<Order> soldProducts;

public:
    /**
     * @brief Constructor for the Seller class.
     * @param name Username for the seller.
     * @param pwd Password for the seller.
     */
    Seller(const std::string& name, const std::string& pwd);

    /**
     * @brief Adds a product to the seller's catalog.
     * @param product The product to add.
     */
    void addProduct(const Product& product);

    /**
     * @brief Removes a product from the catalog by index.
     * @param index The index of the product to remove.
     */
    void removeProduct(int index);

    /**
     * @brief Prints the sales history of the seller.
     */
    void printSalesHistory() const;

    /**
     * @brief Adds a product to the sold products list.
     * @param order The sold order to add.
     */
    void addToSoldProducts(const Order& order);

    /**
     * @brief Displays seller-specific information.
     */
    void displayInfo() const override;
};

#endif // SELLER_H
