#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>
#include <vector>

/**
 * @brief Represents a shipment in the e-commerce system.
 */
class Shipment {
private:
    float shippingCost;
    std::vector<std::string> shippingMethods;

public:
    /**
     * @brief Constructor for the Shipment class.
     * @param defaultMethod The default shipping method to initialize.
     */
    explicit Shipment(const std::string& defaultMethod);

    /**
     * @brief Calculates the shipping cost based on the selected method.
     * @param selectedMethod The selected shipping method.
     * @return The calculated shipping cost.
     */
    float calculateShippingCost(const std::string& selectedMethod);

    /**
     * @brief Gets the current shipping cost.
     * @return The shipping cost as a float.
     */
    float getShippingCost() const;
};

#endif // SHIPMENT_H
