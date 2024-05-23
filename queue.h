// Queue.h
#ifndef QUEUE_H
#define QUEUE_H
// Imports
#include <string>
#include "car.h"

class Queue {
private:
    // Pointers of the first and last Car in the linked list
    Car* front;
    Car* rear;

public:
    // Constructor
    Queue();
    // Destructor
    ~Queue();
    // Checks if queue is empty
    bool isEmpty();
    // Adds to Queue
    void enqueue(const std::string& licensePlate);
    // Removes the next car from the array
    void dequeue();
    // Peeks at the next car
    std::string peek();
    // Displays the cars in the queue
    void displayQueue();
};

#endif // QUEUE_H
