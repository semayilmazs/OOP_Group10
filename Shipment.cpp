#include "Shipment.h"
#include <iostream>

Shipment::Shipment(const std::string& defaultMethod) : shippingCost(0.0) {
    // Initialize with a default shipping method
    shippingMethods.push_back(defaultMethod);
    shippingMethods.push_back("Express");
    shippingMethods.push_back("Overnight");
}

float Shipment::calculateShippingCost(const std::string& selectedMethod) {
    if (selectedMethod == "Standard") {
        shippingCost = 5.0;
    } else if (selectedMethod == "Express") {
        shippingCost = 10.0;
    } else if (selectedMethod == "Overnight") {
        shippingCost = 20.0;
    } else {
        std::cout << "Invalid shipping method selected. Defaulting to Standard.\n";
        shippingCost = 5.0;
    }
    return shippingCost;
}

float Shipment::getShippingCost() const {
    return shippingCost;
}
