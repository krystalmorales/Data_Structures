# Design Implementation

## Visual Description
### Metro System
    └── Trains
        ├── Train 1
            ├── PassengerQueue (Lechmere)
            ├── PassengerQueue (Science Park)
            ├── PassengerQueue (North Station)
        
    └── Stations
        ├── Lechmere
        │   └── PassengerQueue (Boarding, Departing)
        ├── Science Park
        │   └── PassengerQueue (Boarding, Departing)
        └── North Station
            └── PassengerQueue (Boarding, Departing)


## Passenger class
* id
* starting station
* ending station

### Methods
* [X] print()
*     [PASSENGER_ID, ARRIVAL->DEPARTURE]
*     PASSENGER_ID is the Passenger’s ID (each Passenger receives a unique consecutive id number, starting at 1).
*     ARRIVAL and DEPARTURE are the station numbers of the arrival and departure stations, respectively.    

## PassengerQueues (implement from scratch)
* Passengers waiting to board or depart from trains
* use std::list to store passengers in a queue-like structure

### Methods
* [X] Passenger PassengerQueue::front()
*     Returns, but does not remove, the element at the front of the queue. You may throw an error if this function is called on an empty queue, but you are not required to do so.
 * [X] void PassengerQueue::dequeue()s
*       Removes the element at the front of the queue. You may throw an error if this function is called on an empty queue, but you are not required to do so.
 * [X] void PassengerQueue::enqueue(const Passenger &passenger)
*     Inserts a new passenger at the end of the queue.
 * [X] int PassengerQueue::size()
*     Returns the number of elements in the queue.
 * [X] void PassengerQueue::print(std::ostream &output)
*     Prints each Passenger in the PassengerQueue to the given output stream from front to back, with no spaces in between and no trailing newline.

## Train 
* (a list of PassengerQueue objects, where each PassengerQueue represents a train station)
* passenger_queues 
* list of stations

### Methods
* [ ] boardTrain()
* [ ] depart()


## Edge Cases
* Empty PassengerQueue
* Same start and end points
* Empty train
* Full train
* Boarding and departing at same station
* 

## Schedule
* Thursday October 12
*      [X] Design Check off
*      [X] Implement print method for Passenger class
*      [X] Code for PassengerQueue class
* Friday October 13 - Sunday October 15
*      [ ] Code for Station class: implement list of stations
*      [ ] test methods for station class
*      [ ] Code for Train class: track station, boarding, departing
*      [ ] test methods for train class
* Monday October 16 - Tuesday October 17
* [ ] main.cpp:
*     Main file should be short and handle simple driver functions such as reading in files.

* [ ] MetroSim.cpp:
*     Implementation of MetroSim class.  Main functionality of running the Metro Simulation, should be able to move trains and deal with passengers going on/off the train.
* Wednesday October 18
* [ ] Finish README file