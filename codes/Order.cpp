#include "Order.h"
#include <iostream>
#include <iomanip>
#include <random>

Order::Order(const std::vector<Product>& list)
        : orderedProducts(list), totalAmount(0.0), isConfirmed(false), isWrapped(false) {
    // Automatically generate a unique orderID
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

bool Order::confirmOrder(bool confirmed) {
    isConfirmed = confirmed;
    std::cout << "Order " << (isConfirmed ? "confirmed" : "not confirmed") << ".\n";
    return isConfirmed;
}

void Order::printInvoice() const {
    std::cout << "---------------------------------------\n";
    std::cout << "Invoice for Order ID: " << orderID << "\n";
    std::cout << "---------------------------------------\n";
    for (const auto& product : orderedProducts) {
        std::cout << product.getName() << " - $" << std::fixed << std::setprecision(2) << product.getPrice() << "\n";
    }
    std::cout << "---------------------------------------\n";
    std::cout << "Total Amount: $" << std::fixed << std::setprecision(2) << totalAmount << "\n";
    std::cout << "Shipment Method: " << shipment.getMethod() << "\n";
    std::cout << (isWrapped ? "Gift Wrapped: Yes" : "Gift Wrapped: No") << "\n";
    std::cout << "---------------------------------------\n";
}

void Order::selectPayment() const {
    std::cout << "Select a payment method:\n";
    std::cout << "1. Credit Card\n";
    std::cout << "2. PayPal\n";
    std::cout << "3. Cash on Delivery\n";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Payment selected: Credit Card\n";
            break;
        case 2:
            std::cout << "Payment selected: PayPal\n";
            break;
        case 3:
            std::cout << "Payment selected: Cash on Delivery\n";
            break;
        default:
            std::cout << "Invalid selection. Please try again.\n";
            break;
    }
}
