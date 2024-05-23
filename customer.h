#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <map>
#include <iostream>


class Customer {
public:
    // Customer Data Information
    struct CustomerData {
        std::string name;
        std::string email;
    };

private:
    // Map Of Customers using a int id
    std::map<int, CustomerData> customers;

public:
    void addCustomer(int id, const std::string& name, const std::string& email);
    bool findCustomer(int id, CustomerData& customer);
    bool removeCustomer(int id);
    void displayCustomers();
};

#endif // CUSTOMER_H
