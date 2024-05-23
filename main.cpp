// Imports
#include "customer.h"
#include "queue.h"
#include "transaction.h"
#include <iostream>

int main() {
    // Variable For The Queue
    Queue carWashQueue;
    // Choice of Command
    int choice;
    // Car License Plate
    std::string licensePlate;
    // Transaction Amount
    double amount;
    // Search Transaction Id
    int transactionId;
    // Next Transaction Id - Incremanted
    int nextTransactionId = 0;
    // Transaction Hash Table Variable
    TransactionHashTable transactionHashTable = TransactionHashTable(100);
    // Customer Data Variable
    Customer::CustomerData customer;
    // Transaction Data Variable
    Transaction transaction(0, "", 0.0, customer);
    // Customers Map Database
    Customer customers;
    // Next Customer Id - Incremanted
    int newCustomerId = -1;
    // Customer Id - Input
    int customerId;
    // Find Customer Result
    bool customer_check;

    while (true) {

        // Displays Command Message & Takes Choice
        std::cout << std::endl << "Car Wash Queue System" << std::endl;
        std::cout << "1. Add car to queue" << std::endl;
        std::cout << "2. Add customer to system" << std::endl;
        std::cout << "3. Process next car" << std::endl;
        std::cout << "4. View next car" << std::endl;
        std::cout << "5. Find Transaction Info" << std::endl;
        std::cout << "6. Display all cars in queue" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        // Add Car To Queue
        case 1:
            // Finds Customer from ID
            std::cout << "Enter Customer ID: ";
            std::cin >> customerId;
            customer_check = customers.findCustomer(customerId, customer);

            // Checks if customer exists
            if (!customer_check) {
                    std::cout << "Customer not found" << std::endl;
                    break;
            }

            // Take Car & Transaction Info                
            std::cout << "Enter car license plate: ";
            std::cin >> licensePlate;
            std::cout << "Enter transaction amount: ";
            std::cin >> amount;

            // Add Transaction to Hash Table and Car to Queue
            transactionHashTable.addTransaction(Transaction(++nextTransactionId, "Transaction For License Plate: " + licensePlate, amount, customer));           
            carWashQueue.enqueue(licensePlate);
            break;
        // Adds Customer to System
        case 2:
            // Takes New Customer Info
            std::cout << "Enter Customer Name: ";
            std::cin >> customer.name;
            std::cout << "Enter Customer Email: ";
            std::cin >> customer.email;
            // Adds New Customer to Map Database
            customers.addCustomer(++newCustomerId, customer.name, customer.email);
            break;
        // Process the Car
        case 3:
            // Removes the first car from the queue to show its be processed
            carWashQueue.dequeue();
            break;
        // Shows the next car in line
        case 4:
            std::cout << "Next car in queue: " << carWashQueue.peek() << std::endl;
            break;
        // Finds the Transaction Info
        case 5:
            std::cout << "Enter transaction ID: ";
            std::cin >> transactionId;
            // Searches Transaction Hash Table and prints apporiate Message            
            if (transactionHashTable.findTransaction(transactionId, transaction)) {
                std::cout << "Transaction found: ID = " << transaction.id
                          << ", Customer email = " << transaction.customer.email
                          << ", Description = " << transaction.description
                          << ", Amount = " << transaction.amount << std::endl;
            } else {
                std::cout << "Transaction with ID " << transactionId << " not found." << std::endl;
            }
        break;
        // Shows the cars in queue
        case 6:
            carWashQueue.displayQueue();
            break;
        // Shows the customers in the map    
        case 7:
            customers.displayCustomers();
            break;
        // Exits the program
        case 8:
            std::cout << "Exiting the system." << std::endl;
            return 0;
        // Default Message
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
}
