// Transaction.cpp
#include "Transaction.h"
#include "customer.h"
#include <iostream>

// Transaction constructor
Transaction::Transaction(int id, const std::string& description, double amount, Customer::CustomerData customer)
    : id(id), description(description), customer(customer), amount(amount) {}

// TransactionHashTable constructor
TransactionHashTable::TransactionHashTable(int size) : table(size, nullptr) {}

// TransactionHashTable destructor
TransactionHashTable::~TransactionHashTable() {
    // Loops through the table deleting them
    for (auto& head : table) {
        while (head) {
            HashNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

// Hash function
int TransactionHashTable::hashFunction(int id) {
    return id % table.size();
}

// Add transaction
void TransactionHashTable::addTransaction(const Transaction& transaction) {
    // Calculate the hash index for the transaction ID
    int index = hashFunction(transaction.id);
    
    // Create a new node to store the transaction
    HashNode* newNode = new HashNode(transaction);

    // Set the next pointer of the new node to the current head of the linked list
    // at the calculated index in the hash table
    newNode->next = table[index];
    
    // Update the head of the linked list at the calculated index to point to the new node
    table[index] = newNode;
    
    std::cout << "Transaction with ID " << transaction.id << " added." << std::endl;
}
// Find transaction
bool TransactionHashTable::findTransaction(int id, Transaction& transaction) {
    // Calculate the hash index for the transaction ID
    int index = hashFunction(id);
    
    // Initialize a pointer to the current node in the linked list at the calculated index
    HashNode* current = table[index];
    
    // Traverse the linked list
    while (current) {
        // If the ID of the transaction in the current node matches the target ID
        if (current->transaction.id == id) {
            // Copy the transaction details to the provided reference parameter
            transaction = current->transaction;
            return true; // Transaction found
        }
        // Move to the next node in the linked list
        current = current->next;
    }
    return false; // Transaction not found
}

// Remove transaction
bool TransactionHashTable::removeTransaction(int id) {
    // Calculate the hash index for the transaction ID
    int index = hashFunction(id);
    
    // Initialize pointers to the current and previous nodes in the linked list at the calculated index
    HashNode* current = table[index];
    HashNode* prev = nullptr;

    // Traverse the linked list
    while (current) {
        // If the ID of the transaction in the current node matches the target ID
        if (current->transaction.id == id) {
            // If the previous node exists, update its next pointer to skip the current node
            if (prev) {
                prev->next = current->next;
            } else { // If the current node is the head of the linked list, update the head
                table[index] = current->next;
            }
            // Delete the current node
            delete current;
            std::cout << "Transaction with ID " << id << " removed." << std::endl;
            return true; // Transaction removed
        }
        // Move to the next node in the linked list
        prev = current;
        current = current->next;
    }
    return false; // Transaction not found
}
