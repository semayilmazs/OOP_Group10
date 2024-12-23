#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    double price;
    std::string description; // New field for product description

public:
    Product(const std::string& name, double price, const std::string& description = "");
    std::string getName() const;
    double getPrice() const;
    std::string getDescription() const; // Getter for description
};

#endif // PRODUCT_H
