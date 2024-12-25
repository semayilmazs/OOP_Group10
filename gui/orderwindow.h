#ifndef ORDERWINDOW_H
#define ORDERWINDOW_H

#include <QWidget>
#include "Order.h"

namespace Ui {
class OrderWindow;
}

class OrderWindow : public QWidget {
    Q_OBJECT

public:
    explicit OrderWindow(Order* order, QWidget *parent = nullptr);
    ~OrderWindow();

private slots:
    void on_confirmButton_clicked();
    void on_paymentButton_clicked();

private:
    Ui::OrderWindow *ui;
    Order* order;

    void updateOrderDetails();
};

#endif // ORDERWINDOW_H