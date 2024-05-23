#include "Customer.h"

// Add a new customer
void Customer::addCustomer(int id, const std::string& name, const std::string& email) {
    customers[id] = {name, email};
    std::cout << "Customer with ID " << id << " added." << std::endl;
}

// Find a customer by ID
bool Customer::findCustomer(int id, CustomerData& customer) {
    auto it = customers.find(id);
    if (it != customers.end()) {
        customer = it->second;
        return true;
    }
    return false;
}

// Remove a customer by ID
bool Customer::removeCustomer(int id) {
    if (customers.erase(id)) {
        std::cout << "Customer with ID " << id << " removed." << std::endl;
        return true;
    }
    return false;
}

// Display all customers
void Customer::displayCustomers() {
    for (const auto& pair : customers) {
        std::cout << "Customer ID: " << pair.first
                  << ", Name: " << pair.second.name
                  << ", Email: " << pair.second.email << std::endl;
    }
}
