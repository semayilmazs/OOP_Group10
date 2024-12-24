#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QMessageBox>
#include "Product.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void onAddToCart();
    void onRemoveFromCart(); // Slot for Remove from Cart button
    void onApplyDiscount();
    void updateTotalLabel();
    void onProductSelected();

private:
    Ui::MainWindow *ui;

    std::vector<Product> availableProducts; // Store available products
    std::vector<Product> cartItems;
    void populateProductList(); // Function to populate the product list

};

#endif // MAINWINDOW_H
