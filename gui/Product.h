#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    double price;
    std::string description; // New field for product description
    int stock;

public:
    Product(const std::string& name, double price, const std::string& description, int stock);
    std::string getName() const;
    double getPrice() const;
    std::string getDescription() const; // Getter for description
    int getStock() const;
    void reduceStock(int quantity);
    void increaseStock(int quantity);
};

#endif // PRODUCT_H
