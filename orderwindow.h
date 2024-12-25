#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QWidget>
#include "Order.h"
#include "Customer.h"

namespace Ui {
class OrderWindow;
}

class OrderWindow : public QWidget {
    Q_OBJECT

public:
    explicit OrderWindow(Order* order, Customer* customer, QWidget *parent = nullptr);
    ~OrderWindow();

private slots:
    void on_confirmButton_clicked();
    void on_paymentButton_clicked();

private:
    Ui::OrderWindow *ui;
    Order* order;
    Customer* customer;
};

#endif // ORDERWINDOW_H