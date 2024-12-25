#include "Order.h"
#include <QDebug>

Order::Order(int orderId, Customer* customer, QObject* parent)
    : QObject(parent), orderId(orderId), customer(customer), isShipped(false) {}

void Order::addProduct(const Product& product) {
    products.append(product);
    emit productAdded(product.getName());
}

void Order::removeProduct(int index) {
    if (index >= 0 && index < products.size()) {
        emit productRemoved(products[index].getName());
        products.removeAt(index);
    } else {
        qWarning() << "Invalid index. Unable to remove product.";
    }
}

void Order::confirmOrder() {
    emit orderConfirmed();
    qDebug() << "Order confirmed. Ready for shipment.";
}

void Order::shipOrder() {
    isShipped = true;
    emit orderShipped();
    qDebug() << "Order shipped.";
}

bool Order::getShipmentStatus() const {
    return isShipped;
}

void Order::printOrderDetails() const {
    qDebug() << "Order ID:" << orderId;
    if (customer) {
        qDebug() << "Customer:" << customer->getUsername();
    }
    for (const auto& product : products) {
        qDebug() << "- " << product.getName() << " - $" << product.getPrice();
    }
    qDebug() << "Shipment Status:" << (isShipped ? "Shipped" : "Pending");
}