#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Cart.h"
#include "Wishlist.h"
#include "Order.h"
#include <vector>
#include <string>

/**
 * @brief Derived class representing a customer in the system.
 */
class Customer : public User {
private:
    std::string cardInfo;
    std::string address;
    Cart cart;
    Wishlist wishlist;
    std::vector<Order> orderHistory;

public:
    /**
     * @brief Constructor for the Customer class.
     * @param name Username for the customer.
     * @param pwd Password for the customer.
     */
    Customer(const std::string& name, const std::string& pwd);

    /**
     * @brief Views the customer's order history.
     * @return A list of orders.
     */
    std::vector<Order> viewOrderHistory() const;

    /**
     * @brief Adds an order to the customer's order history.
     * @param lastOrder The most recent order to add.
     */
    void addToOrderHistory(const Order& lastOrder);

    /**
     * @brief Gets the customer's card information.
     * @return The card information as a string.
     */
    std::string getCardInfo() const;

    /**
     * @brief Sets new card information for the customer.
     * @param newInfo The new card information to set.
     */
    void setCardInfo(const std::string& newInfo);

    /**
     * @brief Gets the customer's shopping cart.
     * @return A reference to the cart.
     */
    Cart& getCart();

    /**
     * @brief Gets the customer's wishlist.
     * @return A reference to the wishlist.
     */
    Wishlist& getWishlist();

    /**
     * @brief Gets the customer's address.
     * @return The address as a string.
     */
    std::string getAddress() const;

    /**
     * @brief Sets the customer's address.
     * @param add The new address to set.
     */
    void setAddress(const std::string& add);

    /**
     * @brief Displays customer-specific information.
     */
    bool login(const std::string& inputPassword) override;

    /**
     * @brief Overrides the logout method for Customer-specific logic.
     */
    void logout() override;
    void displayInfo() const override;
};

#endif // CUSTOMER_H
