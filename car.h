#include <iostream>
#include <string>
#include "transaction.h"

// Car Struct
struct Car {
    // License Plate of current Car
    std::string licensePlate;
    // Pointer to Transaction Information
    Transaction* transaction;
    // Pointer to Next Car
    Car* next;
};
