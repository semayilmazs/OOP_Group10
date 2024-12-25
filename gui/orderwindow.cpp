#include "OrderWindow.h"
#include "ui_OrderWindow.h"
#include <QDebug>

OrderWindow::OrderWindow(Order* order, QWidget *parent)
    : QWidget(parent), ui(new Ui::OrderWindow), order(order) {
    ui->setupUi(this);
    updateOrderDetails();
}

OrderWindow::~OrderWindow() {
    delete ui;
}

void OrderWindow::updateOrderDetails() {
    QString details = QString("Order ID: %1\nTotal Amount: $%2\nShipment Method: %3")
                        .arg(order->getOrderID())
                        .arg(order->getTotalAmount(), 0, 'f', 2)
                        .arg(order->getShipment().getMethod());
    ui->orderDetailsTextEdit->setText(details);
}

void OrderWindow::on_confirmButton_clicked() {
    if (order->confirmOrder()) {
        ui->statusLabel->setText("Order confirmed.");
    } else {
        ui->statusLabel->setText("Order could not be confirmed.");
    }
}

void OrderWindow::on_paymentButton_clicked() {
    order->selectPayment();
    qDebug() << "Payment method selected for order ID:" << order->getOrderID();
}