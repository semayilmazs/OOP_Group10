#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    availableProducts = {
        Product("Laptop", 10000.0, "A high-performance laptop with 16GB RAM and 512GB SSD.",4),
        Product("Phone", 5000.0, "A smartphone with a 6.5-inch display and 128GB storage.",5),
        Product("Headphones", 1500.0, "Noise-cancelling over-ear headphones with excellent sound quality.",12),
        Product("Smartwatch", 2000.0, "A stylish smartwatch with fitness tracking and heart rate monitoring.",4),
        Product("Tablet", 3000.0, "A lightweight tablet with a 10-inch screen and 64GB storage.",30),
        Product("Keyboard", 500.0, "A mechanical keyboard with RGB backlighting.",3),
        Product("Mouse", 300.0, "A wireless mouse with adjustable DPI settings.",2),
        Product("Monitor", 2500.0, "A 24-inch Full HD monitor with vibrant colors.",5),
        Product("Printer", 1200.0, "An all-in-one inkjet printer with scanning and copying features.",3),
        Product("External Hard Drive", 1000.0, "A 1TB external hard drive for secure data backup.",12),
        Product("Gaming Chair", 3000.0, "An ergonomic gaming chair with lumbar support and recline functionality.",20),
        Product("Webcam", 800.0, "A Full HD webcam with autofocus and microphone.",10),
        Product("Router", 700.0, "A high-speed wireless router with dual-band support.",3),
        Product("Power Bank", 400.0, "A 10000mAh power bank with fast charging capabilities.",4),
        Product("USB Flash Drive", 200.0, "A 64GB USB flash drive with high transfer speeds.",5)
    };

    populateProductList();
    connect(ui->productListWidget, &QListWidget::currentRowChanged, this, &MainWindow::onProductSelected);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveFromCart);
    connect(ui->applyDiscountButton, &QPushButton::clicked, this, &MainWindow::onApplyDiscount);
    connect(ui->giftWrapping, &QCheckBox::toggled, this, &MainWindow::onGiftWrappingToggled);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::populateProductList() {
    for (const auto& product : availableProducts) {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(QString::fromStdString(
            product.getName() + " - $" + std::to_string(product.getPrice()) +
            " (Stock: " + std::to_string(product.getStock()) + ")"
            ));
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

    }
}
void MainWindow::updateTotalLabel() {
    double total = 0;

    // Calculate the total price
    for (const auto& product : cartItems) {
        total += product.getPrice();
    }

    ui->totalLabel->setText("Total: $" + QString::number(total, 'f', 2));
}
void MainWindow::on_addButton_clicked() {
    int currentRow = ui->productListWidget->currentRow();
    if (currentRow >= 0 && currentRow < static_cast<int>(availableProducts.size())) {
        Product& selectedProduct = availableProducts[currentRow];

        // Check if stock is available
        if (selectedProduct.getStock() > 0) {
            selectedProduct.reduceStock(1); // Reduce stock by 1
            ui->cartListWidget->addItem(QString::fromStdString(selectedProduct.getName() + " - $" + std::to_string(selectedProduct.getPrice())));

            // Update product list with new stock
            QListWidgetItem* item = ui->productListWidget->item(currentRow);
            item->setText(QString::fromStdString(
                selectedProduct.getName() + " - $" + std::to_string(selectedProduct.getPrice()) +
                " (Stock: " + std::to_string(selectedProduct.getStock()) + ")"
                ));

            cartItems.push_back(selectedProduct); // Add to cartItems vector
            updateTotalLabel(); // Call this to update total after adding an item

            // Notify user
            ui->cartNotification->append(QString::fromStdString(selectedProduct.getName()) + " is added to the cart.");
        } else {
            QMessageBox::warning(this, "Out of Stock", "This product is out of stock!");
        }
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

        // Notify user
        ui->cartNotification->append(productName + " is removed from the cart.");
    }
}

void MainWindow::onApplyDiscount() {
    QString selectedDiscount = ui->discountComboBox->currentText();
    double total = 0;

    // Calculate the total price
    for (const auto& product : cartItems) {
        total += product.getPrice();
    }

    double discountAmount = 0.0;
    // Apply the selected discount
    if (selectedDiscount == "%10 discount") {
        discountAmount = total * 0.10; // Calculate 10% discount
        total -= discountAmount;
    }

    // Update the total label
    ui->totalLabel->setText("Total: $" + QString::number(total, 'f', 2));

    // Update the discount notification
    if (discountAmount > 0) {
        ui->discountNotification->append("Discount applied: $" + QString::number(discountAmount, 'f', 2));
    }
}

void MainWindow::onGiftWrappingToggled() {
    double total = 0;

    // Calculate the total price of cart items
    for (const auto& product : cartItems) {
        total += product.getPrice();
    }

    // Add gift-wrapping cost if selected
    if (ui->giftWrapping->isChecked()) {
        total += 50.0; // Add $50 for gift wrapping
        ui->discountNotification->append("Gift wrapping added: $50.00");
    } else {
        ui->discountNotification->append("Gift wrapping removed.");
    }

    // Update the total label
    ui->totalLabel->setText("Total: $" + QString::number(total, 'f', 2));
}

void MainWindow::on_confirmOrder_clicked() {

}
