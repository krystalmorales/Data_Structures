/*
 * By Krystal Morales
 * October 11, 2023
 * The purpose of this file is to create the interface for PassengerQueue.cpp
 */

#ifndef _PASSENGERQUEUE_H__
#define _PASSENGERQUEUE_H__

#include <iostream>
#include <list>   
#include "Passenger.h"

class PassengerQueue {
public: 
    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(std::ostream &output);

private:
    std::list<Passenger> passengers;
};

#endif