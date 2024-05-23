// Transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "customer.h"
#include <string>
#include <vector>

// Transaction class
class Transaction {
public:
    int id;
    std::string description;
    Customer::CustomerData customer;
    double amount;

    Transaction(int id, const std::string& description, double amount, Customer::CustomerData customer);
};

// TransactionHashTable class
class TransactionHashTable {
private:
    struct HashNode {
        // Transaction in the current node
        Transaction transaction;
        // Next Node in the Table
        HashNode* next;

        // Constructor
        HashNode(const Transaction& transaction) : transaction(transaction), next(nullptr) {}
    };

    // Vector Containing Pointers to Each Node in the Table
    std::vector<HashNode*> table;
    // Calculates the Hash Value for a given transaction id
    int hashFunction(int id);

public:
    // Constructor
    TransactionHashTable(int size);
    // Destructor
    ~TransactionHashTable();
    // Adds a transaction
    void addTransaction(const Transaction& transaction);
    // Finds a transaction
    bool findTransaction(int id, Transaction& transaction);
    // Removes a transaction
    bool removeTransaction(int id);
    // Displays all transactions
    void displayTransactions();
};

#endif // TRANSACTION_H
