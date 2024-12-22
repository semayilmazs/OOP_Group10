#ifndef DISCOUNT_H
#define DISCOUNT_H

#include <string>
#include <vector>

/**
 * @brief Represents a discount applied to a cart or product.
 */
class Discount {
private:
    std::vector<std::string> discountType;
    float discountPercentage;

public:
    /**
     * @brief Constructor for the Discount class.
     * Initializes with common discount types and a default percentage.
     */
    Discount();

    /**
     * @brief Applies the discount to a given amount.
     * @param totalPrice The original price to which the discount will be applied.
     * @return The price after the discount is applied.
     */
    float applyDiscount(float totalPrice) const;

    /**
     * @brief Gets the current discount percentage.
     * @return The discount percentage as a float.
     */
    float getDiscountPercentage() const;

    /**
     * @brief Sets a new discount percentage.
     * @param newPer The new discount percentage to set.
     */
    void setDiscountPercentage(float newPer);
};

#endif // DISCOUNT_H
