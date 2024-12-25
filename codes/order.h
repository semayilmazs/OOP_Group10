#ifndef ORDER_H
#define ORDER_H

#include <QList>
#include <QString>
#include <QObject>
#include "Product.h"
#include "Customer.h"
#include "Shipment.h"

/**
 * @brief Represents an order in the e-commerce system.
 */
class Order : public QObject {
    Q_OBJECT

private:
    int orderId;
    Customer* customer;
    QList<Product> products;
    Shipment shipment;
    bool isShipped;

public:
    explicit Order(int orderId, Customer* customer, QObject* parent = nullptr);

    void addProduct(const Product& product);
    void removeProduct(int index);
    void confirmOrder();
    void shipOrder();
    bool getShipmentStatus() const;
    void printOrderDetails() const;

signals:
    void orderConfirmed();
    void orderShipped();
    void productAdded(const QString& productName);
    void productRemoved(const QString& productName);
};

#endif // ORDER_H