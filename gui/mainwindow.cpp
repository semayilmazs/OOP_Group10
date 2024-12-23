#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    availableProducts = {
        Product("Laptop", 1000.0, "A high-performance laptop with 16GB RAM and 512GB SSD."),
        Product("Phone", 500.0, "A smartphone with a 6.5-inch display and 128GB storage."),
        Product("Headphones", 150.0, "Noise-cancelling over-ear headphones with excellent sound quality."),
        Product("Smartwatch", 200.0, "A stylish smartwatch with fitness tracking and heart rate monitoring."),
        Product("Tablet", 300.0, "A lightweight tablet with a 10-inch screen and 64GB storage."),
        Product("Keyboard", 50.0, "A mechanical keyboard with RGB backlighting."),
        Product("Mouse", 30.0, "A wireless mouse with adjustable DPI settings."),
        Product("Monitor", 250.0, "A 24-inch Full HD monitor with vibrant colors."),
        Product("Printer", 120.0, "An all-in-one inkjet printer with scanning and copying features."),
        Product("External Hard Drive", 100.0, "A 1TB external hard drive for secure data backup."),
        Product("Gaming Chair", 300.0, "An ergonomic gaming chair with lumbar support and recline functionality."),
        Product("Webcam", 80.0, "A Full HD webcam with autofocus and microphone."),
        Product("Router", 70.0, "A high-speed wireless router with dual-band support."),
        Product("Power Bank", 40.0, "A 10000mAh power bank with fast charging capabilities."),
        Product("USB Flash Drive", 20.0, "A 64GB USB flash drive with high transfer speeds.")
    };

    populateProductList();
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddToCart);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveFromCart);
    connect(ui->applyDiscountButton, &QPushButton::clicked, this, &MainWindow::onApplyDiscount);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::populateProductList() {
    for (const auto& product : availableProducts) {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(QString::fromStdString(product.getName() + " - $" + std::to_string(product.getPrice())));

        ui->productListWidget->addItem(item);
    }
}
void MainWindow::onProductSelected() {
    int currentRow = ui->productListWidget->currentRow();
    if (currentRow >= 0 && currentRow < static_cast<int>(availableProducts.size())) {
        const Product& selectedProduct = availableProducts[currentRow];

        // Update the details section
        QString details = QString::fromStdString(
            "<b>Name:</b> " + selectedProduct.getName() + "<br>" +
            "<b>Price:</b> $" + std::to_string(selectedProduct.getPrice()) + "<br>" +
            "<b>Description:</b> " + selectedProduct.getDescription()
            );
        ui->productDetailsTextEdit->setHtml(details);

        ui->productDetailsTextEdit->setText(details);
    }
}

void MainWindow::onAddToCart() {
    QListWidgetItem *selectedItem = ui->productListWidget->currentItem();
    if (selectedItem) {
        ui->cartListWidget->addItem(selectedItem->text());
        connect(ui->productListWidget, &QListWidget::currentRowChanged, this, &MainWindow::onProductSelected);

        // Extract product name and add it to the cartItems
        QString productName = selectedItem->text().split(" - $")[0];
        for (const auto& product : availableProducts) {
            if (product.getName() == productName.toStdString()) {
                cartItems.push_back(product);
                break;
            }
        }
        updateTotalLabel(); // Update total when adding a product
    }
}

void MainWindow::onRemoveFromCart() {
    QListWidgetItem *selectedItem = ui->cartListWidget->currentItem();
    if (selectedItem) {
        QString productName = selectedItem->text().split(" - $")[0];

        // Remove the product from cartItems
        cartItems.erase(
            std::remove_if(cartItems.begin(), cartItems.end(),
                           [&productName](const Product& product) {
                               return product.getName() == productName.toStdString();
                           }),
            cartItems.end()
            );

        delete selectedItem; // Remove from GUI
        updateTotalLabel();  // Update total when removing a product
    }
}

void MainWindow::onApplyDiscount() {
    QString selectedDiscount = ui->discountComboBox->currentText();
    double total = 0;

    // Calculate the total price
    for (const auto& product : cartItems) {
        total += product.getPrice();
    }

    // Apply the selected discount
    if (selectedDiscount == "%10 discount") {
        total -= total * 0.10; // Apply 10% discount
    } else if (selectedDiscount == "No discount") {
        total /= 2; // Simplified BOGO logic
    }

    // Update the total label
    ui->totalLabel->setText("Total: $" + QString::number(total, 'f', 2));
}

void MainWindow::updateTotalLabel() {
    double total = 0;

    // Calculate the total price
    for (const auto& product : cartItems) {
        total += product.getPrice();
    }

    ui->totalLabel->setText("Total: $" + QString::number(total, 'f', 2));
}

