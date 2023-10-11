/*
 * By: Krystal Morales
 * October 11, 2023
 * The purpose of this file is to define the methods 
 * for the PassangerQueue class
 */

#include <iostream>
#include <string>
#include <list>
#include "PassengerQueue.h"


/*
* name: front
* purpose: return first passenger
* arguments: none
* return: first passenger 
* effects: none
*/ 
Passenger PassengerQueue::front() {
    if(passengers.empty()) {
        throw std::runtime_error("Empty Queue");
    }
    return passengers.front();
}

/*
* name: enqueue
* purpose: insert new passenger end of queue
* arguments: const Passenger &passenger
* return: none 
* effects: inserts new passenger at end of queue
*/ 
void PassengerQueue::enqueue(const Passenger &passenger) {
    passengers.push_back(passenger);
}

/*
* name: dequeue
* purpose: Removes the element at the front of the queue
* arguments: none
* return: none 
* effects: Removes the element at the front of the queue
*/ 
void PassengerQueue::dequeue() {
    if(passengers.empty()) {
        throw std::runtime_error("Empty Queue");
    } else {
        passengers.pop_front();
    }
}

/*
* name: size
* purpose: Returns the number of elements in the queue
* arguments: none
* return: Returns the number of elements in the queue
* effects: none
*/ 
int PassengerQueue::size() {
    return passengers.size();
}

/*
* name: print
* purpose: Prints each Passenger in the PassengerQueue to the 
            given output stream from front to back
* arguments: std::ostream &output
* return: none
* effects: none
*/ 
void PassengerQueue::print(std::ostream &output) {
    for (Passenger &p: passengers) {
        p.print(output);
    }
}