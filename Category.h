#ifndef CATEGORY_H
#define CATEGORY_H

#include "Product.h"
#include <string>
#include <vector>

/**
 * @brief Represents a category in the e-commerce system.
 */
class Category {
private:
    std::string name;
    std::vector<Product*> products;

public:
    /**
     * @brief Constructor for the Category class.
     * @param name The name of the category.
     */
    explicit Category(const std::string& name);

    /**
     * @brief Adds a product to the category.
     * @param product Pointer to the product to add.
     */
    void addProduct(Product* product);

    /**
     * @brief Removes a product from the category by index.
     * @param index The index of the product to remove.
     */
    void removeProduct(int index);

    /**
     * @brief Prints all products in the category.
     */
    void printProducts() const;

    /**
     * @brief Gets the name of the category.
     * @return The category name as a string.
     */
    std::string getName() const;
};

#endif // CATEGORY_H
