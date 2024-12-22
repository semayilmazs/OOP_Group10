#ifndef ORDER_H
#define ORDER_H

#include "Product.h"
#include "Shipment.h"
#include <vector>

/**
 * @brief Represents an order in the e-commerce system.
 */
class Order {
private:
    int orderID;
    std::vector<Product> orderedProducts;
    float totalAmount;
    Shipment shipment;
    bool isConfirmed;
    bool isWrapped;

    /**
     * @brief Calculates the total amount of the order.
     */
    void calculateTotal();

public:
    /**
     * @brief Constructor for the Order class.
     * @param list The list of ordered products.
     */
    Order(const std::vector<Product>& list);

    /**
     * @brief Confirms the order.
     * @param confirmed Indicates whether the order is confirmed or not.
     * @return The confirmation status.
     */
    bool confirmOrder(bool confirmed);

    /**
     * @brief Prints an invoice for the order.
     */
    void printInvoice() const;

    /**
     * @brief Selects a payment method for the order.
     */
    void selectPayment() const;
};

#endif // ORDER_H
