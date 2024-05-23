// Queue.cpp
#include "Queue.h"
#include <iostream>

// Constructor
Queue::Queue() : front(nullptr), rear(nullptr) {}

// Destructor
Queue::~Queue() {
    // Loops till queue is empty
    while (!isEmpty()) {
        dequeue();
    }
}

// Checks if queue is empty
bool Queue::isEmpty() {
    return front == nullptr;
}

// Adds to Queue
void Queue::enqueue(const std::string& licensePlate) {
    Car* newCar = new Car{licensePlate, nullptr};
    // Adds the next to the rear of the queue
    if (rear) {
        rear->next = newCar;
    }
    rear = newCar;
    // If there is no front adds the rear to the front
    if (!front) {
        front = rear;
    }
    std::cout << "Car with license plate " << licensePlate << " added to the queue." << std::endl;
}

// Removes the next car from the list
void Queue::dequeue() {
    // Check if the list is empty
    if (isEmpty()) {
        std::cout << "The queue is empty. No car to process." << std::endl;
        return;
    }

	  // Takes the car from the front
    Car* temp = front;
    // Moves the car to the next one
    front = front->next;
    // if theres no front sent the rear to nullptr
    if (!front) {
        rear = nullptr;
    }
    std::cout << "Car with license plate " << temp->licensePlate << " processed." << std::endl;
    // Deletes the temp value
    delete temp;
}

// Peeks at the next value in the queue and returns it
std::string Queue::peek() {
    if (isEmpty()) {
        return "Queue is empty";
    }
    return front->licensePlate;
}

// Displays each entry in the list by going to each next one
void Queue::displayQueue() {
    if (isEmpty()) {
        std::cout << "The queue is empty." << std::endl;
        return;
    }
    Car* current = front;
    while (current) {
        std::cout << "Car with license plate " << current->licensePlate << " is in the queue." << std::endl;
        current = current->next;
    }
}
