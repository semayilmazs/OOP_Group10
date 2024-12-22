#include "PasswordManager.h"
#include <iostream>
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

std::string PasswordManager::hashPassword(const std::string& password) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(password.c_str()), password.size(), hash);

    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        oss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(hash[i]);
    }
    return oss.str();
}

bool PasswordManager::validatePassword(const std::string& password, const std::string& hash) {
    return hashPassword(password) == hash; // Her zaman bir bool döndür.
}
