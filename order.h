#ifndef ORDER_H
#define ORDER_H

#include "Product.h"
#include "Shipment.h"
#include <vector>

class Order {
private:
    int orderID;
    std::vector<Product> orderedProducts;
    float totalAmount;
    Shipment shipment;
    bool isConfirmed;
    bool isWrapped;

    void calculateTotal();

public:
    Order(const std::vector<Product>& list);
    int getOrderID() const;
    float getTotalAmount() const;
    Shipment& getShipment();
    bool confirmOrder(bool confirmed);
};

#endif // ORDER_H