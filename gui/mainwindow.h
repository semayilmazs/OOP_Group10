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

    /**
     * @brief
     *
     *
     * Also notifies the user when a object is removed to the cart.
     */
    void onRemoveFromCart(); // Slot for Remove from Cart button
    void onApplyDiscount();
    void updateTotalLabel();
    void onProductSelected();

    /**
     * @brief
     *
     *
     * Also notifies the user when a object is added to the cart.
     */
    void on_addButton_clicked();

    /**
     * @brief If gift wrapping option is selected adds 50$ to total cost.
     */
    void onGiftWrappingToggled();

    /**
     * @brief When shopping is finished and customer clicked the Confirm Order
     * button, it directs the customer to the order window.
     */
    void on_confirmOrder_clicked();

private:
    Ui::MainWindow *ui;

    std::vector<Product> availableProducts; // Store available products
    std::vector<Product> cartItems;
    void populateProductList(); // Function to populate the product list

};

#endif // MAINWINDOW_H
