#include "OrderWindow.h"
#include "ui_OrderWindow.h"

OrderWindow::OrderWindow(Order* order, Customer* customer, QWidget *parent)
    : QWidget(parent), ui(new Ui::OrderWindow), order(order), customer(customer) {
    ui->setupUi(this);

    QString details = QString("Customer: %1\nOrder ID: %2\nTotal Amount: $%3")
                        .arg(customer->getUsername())
                        .arg(order->getOrderID())
                        .arg(order->calculateTotal(), 0, 'f', 2);
    ui->orderDetailsTextEdit->setText(details);

    connect(ui->confirmButton, &QPushButton::clicked, this, &OrderWindow::on_confirmButton_clicked);
    connect(ui->paymentButton, &QPushButton::clicked, this, &OrderWindow::on_paymentButton_clicked);
}

OrderWindow::~OrderWindow() {
    delete ui;
}

void OrderWindow::on_confirmButton_clicked() {
    if (order->confirmOrder(true)) {
        ui->statusLabel->setText("Order confirmed.");
    } else {
        ui->statusLabel->setText("Order not confirmed.");
    }
}

void OrderWindow::on_paymentButton_clicked() {
    order->selectPayment();
}