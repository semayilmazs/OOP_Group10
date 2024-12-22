#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include "Category.h"

/**
 * @brief Represents a product in the e-commerce system.
 */
class Product {
private:
    int productID;
    std::string name;
    std::string explanation;
    int stock;
    float price;
    Category* category;

public:
    /**
     * @brief Constructor for the Product class.
     * @param nm Name of the product.
     * @param stck Stock quantity.
     * @param prc Price of the product.
     * @param ctgry Pointer to the product's category.
     */
    Product(const std::string& nm, int stck, float prc, Category* ctgry);

    /**
     * @brief Displays the product's information.
     * @return A string containing product details.
     */
    std::string displayProductInfo() const;

    /**
     * @brief Sets a new explanation for the product.
     * @param newExp The new explanation.
     */
    void setExplanation(const std::string& newExp);

    /**
     * @brief Gets the product's explanation.
     * @return The explanation as a string.
     */
    std::string getExplanation() const;

    /**
     * @brief Sets a new price for the product.
     * @param newPrice The new price.
     */
    void setPrice(float newPrice);

    /**
     * @brief Gets the product's price.
     * @return The price as a float.
     */
    float getPrice() const;

    /**
     * @brief Sets a new name for the product.
     * @param newName The new name.
     */
    void setName(const std::string& newName);

    /**
     * @brief Gets the product's name.
     * @return The name as a string.
     */
    std::string getName() const;

    /**
     * @brief Sets a new stock quantity for the product.
     * @param newStock The new stock quantity.
     */
    void setStock(int newStock);

    /**
     * @brief Gets the product's stock quantity.
     * @return The stock as an integer.
     */
    int getStock() const;

    /**
     * @brief Sets a new category for the product.
     * @param newCategory Pointer to the new category.
     */
    void setCategory(Category* newCategory);

    /**
     * @brief Gets the product's category.
     * @return Pointer to the product's category.
     */
    Category* getCategory() const;
};

#endif // PRODUCT_H
