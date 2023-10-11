/*
 *  unit_tests.cpp
 *  Krystal Morales
 *  October 11, 2023
 *
 *
 *  The purpose of this file is to create unit tests for Passenger class
 *
 */

#include "Passenger.h"
#include "PassengerQueue.h"
#include <cassert>
#include <iostream>
#include <sstream>


// Test print method for Passenger.h
void test_print_passenger() {
    Passenger passenger1(1,4,5);

    std::stringstream output;
    passenger1.print(std::cout);

}

// Test front() method for PassengerQueue
void test_front() {
    PassengerQueue passQueue;
    
    Passenger passenger1(1, 4, 5);
    Passenger passenger2(2,2,4);
    Passenger passenger3(3,1,3);

    passQueue.enqueue(passenger1);
    passQueue.enqueue(passenger2);
    passQueue.enqueue(passenger3);

    Passenger frontPassenger = passQueue.front();

    assert(frontPassenger.id == 1);
    assert(frontPassenger.from == 4);
    assert(frontPassenger.to == 5);
}

// Test enqueue works properly 
void test_enqueue() {
    PassengerQueue passQueue;
    
    Passenger passenger1(1, 4, 5);
    Passenger passenger2(2,2,4);
    Passenger passenger3(3,1,3);

    passQueue.enqueue(passenger1);
    passQueue.enqueue(passenger2);
    passQueue.enqueue(passenger3);
    
    assert(passQueue.front().id == 1);
    assert(passQueue.front().from == 4);
    assert(passQueue.front().to == 5);

    assert(passQueue.size() == 3);

    std::ostringstream outputStream;
    passQueue.print(outputStream);
}

// Test dequeue works properly
void test_dequeue() {
    PassengerQueue passQueue;
    
    Passenger passenger1(1,4,5);
    Passenger passenger2(2,2,4);
    Passenger passenger3(3,1,3);

    passQueue.enqueue(passenger1);
    passQueue.enqueue(passenger2);
    passQueue.enqueue(passenger3);

    assert(passQueue.size() == 3);
    passQueue.dequeue();

    assert(passQueue.size() == 2);
    assert(passQueue.front().id == 2);

}

//Test print works properly
void test_print() {
    PassengerQueue passQueue;
    
    Passenger passenger1(1,4,5);
    Passenger passenger2(2,2,4);
    Passenger passenger3(3,1,3);

    passQueue.enqueue(passenger1);
    passQueue.enqueue(passenger2);
    passQueue.enqueue(passenger3);

    std::stringstream debugOutput;
    passQueue.print(debugOutput);
    std::cout << "Contents of the queue: " << debugOutput.str();   
}

int main() {
   //test_print_passenger();
   // test_enqueue();
   // test_front();
   //test_print();
   test_dequeue();
    return 0;
}