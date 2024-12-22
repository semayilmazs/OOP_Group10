#ifndef DATALOADER_H
#define DATALOADER_H

#include "Customer.h"
#include "Seller.h"
#include <vector>
#include <string>

/**
 * @brief A utility class for loading customer and seller data from files.
 */
class DataLoader {
public:
    /**
     * @brief Loads customers from a file.
     * @param filename The name of the file to load customers from.
     * @return A vector of Customer objects.
     */
    static std::vector<Customer> loadCustomersFromFile(const std::string& filename);

    /**
     * @brief Loads sellers from a file.
     * @param filename The name of the file to load sellers from.
     * @return A vector of Seller objects.
     */
    static std::vector<Seller> loadSellersFromFile(const std::string& filename);
};

#endif // DATALOADER_H
