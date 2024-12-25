#include "Order.h"
#include <random>

Order::Order(const std::vector<Product>& list)
    : orderedProducts(list), totalAmount(0.0), isConfirmed(false), isWrapped(false), shipment("Standard") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10000, 99999);
    orderID = dis(gen);

    calculateTotal();
}

void Order::calculateTotal() {
    totalAmount = 0.0;
    for (const auto& product : orderedProducts) {
        totalAmount += product.getPrice();
    }
}

int Order::getOrderID() const {
    return orderID;
}

float Order::getTotalAmount() const {
    return totalAmount;
}

Shipment& Order::getShipment() {
    return shipment;
}

bool Order::confirmOrder(bool confirmed) {
    isConfirmed = confirmed;
    return isConfirmed;
}