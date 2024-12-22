#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Customer> DataLoader::loadCustomersFromFile(const std::string& filename) {
    std::vector<Customer> customers;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return customers;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string username, password, cardInfo, address;

        if (std::getline(iss, username, ',') &&
            std::getline(iss, password, ',') &&
            std::getline(iss, cardInfo, ',') &&
            std::getline(iss, address)) {
            Customer customer(username, password);
            customer.setCardInfo(cardInfo);
            customer.setAddress(address);
            customers.push_back(customer);
        }
    }

    return customers;
}

std::vector<Seller> DataLoader::loadSellersFromFile(const std::string& filename) {
    std::vector<Seller> sellers;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << "\n";
        return sellers;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string username, password;
        std::vector<std::string> products;
        std::string product;

        if (std::getline(iss, username, ',') && std::getline(iss, password, ',')) {
            Seller seller(username, password);
            while (std::getline(iss, product, ',')) {
                seller.addProduct(Product(product, 10, 50.0, nullptr)); // Default stock/price for demo
            }
            sellers.push_back(seller);
        }
    }

    return sellers;
}
