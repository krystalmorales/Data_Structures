/*
 * By: Krystal Morales
 * October 11, 2023
 * The purpose of this file is to define the methods for the Passanger class
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/*
* name: print
* purpose: print passenger id and arrivial -> departure station numbers
* arguments: std::ostream &output
* return: none 
* effects: none
*/              
void Passenger::print(std::ostream &output)
{
        output << "[" << id << ", " << from << "->" << to << "]";
}
