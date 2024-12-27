#define PRODUCT_H

#include <string>

class Product {
private:
    std::string name;
    double price;
    std::string description;
    int stock;
    std::string imagePath; // Add this line

public:
    Product(const std::string& name, double price, const std::string& description, int stock, const std::string& imagePath);
    std::string getName() const;
    double getPrice() const;
    std::string getDescription() const;
    int getStock() const;
    std::string getImagePath() const; // Add this getter
    void reduceStock(int quantity);
    void increaseStock(int quantity);

};
