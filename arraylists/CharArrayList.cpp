/*
 *  CharArrayList.cpp
 *  Krystal Morales
 *  9/24/2023
 *
 *  COMP 15 HW 1 Cheshire ConCATenation
 *
 *  Function definitions for the CharArrayList class
 *
 */

#include "CharArrayList.h"
#include <sstream>

using namespace std;

/*
* name: CharArrayList default constructor
* purpose: initialize an empty CharArrayList
* arguments: none
* return: none 
* effects: numItems to 0 (also updates capacity and data array)
*/
CharArrayList::CharArrayList() {
    numItems = 0;
    capacity = 0;
    data = nullptr;
}

/*
* name: CharArrayList(char c)
* purpose: creates a one element array list consisting of that character
* arguments: a single character 
* return: none
* effects: Initializes a single character array list consisting of that character
*/
CharArrayList::CharArrayList(char c) {
    numItems = 1;
    capacity = 1;
    data = new char[capacity];
    data[0] = c;
}

/*
* name: CharArrayList(char arr[], int size)
* purpose:  create an array list containing the characters in the array
* arguments: takes an array of characters and the integer
length of that array of characters as parameters
* return: none
* effects: Initializes an array list containing the characters in the array
*/
CharArrayList::CharArrayList(char arr[], int size) {
    numItems = 0;
    capacity = size;
    data = new char[capacity];

    for (int i = 0; i < size; i++) {
        data[i] = arr[i];
        numItems++;
    }
}

/*
 * name:      CharArrayList(const CharArrayList &other)
 * purpose:   A copy constructor for the class that makes 
 *            a deep copy of a given instance
 * arguments: a reference to another CharArrayList 
 *            instance to copy from
 * returns:   
 * effects:   Creates a deep copy of the given instance   
 */
CharArrayList::CharArrayList(const CharArrayList &other) {
    capacity = other.capacity;
    data = new char[capacity];

    numItems = other.numItems;
    for (int i = 0; i <numItems; i++) {
        data[i] = other.data[i];
    }
}

/*
 * name:      CharArrayList destructor
 * purpose:   free memory associated with the CharArrayList
 * arguments: none
 * returns:   none
 * effects:   frees memory allocated by CharArraylist instances
 */
CharArrayList::~CharArrayList() {
    if (data != nullptr) {
        delete[] data;
    }

}

/*
 * name:      isEmpty
 * purpose:   determines if the CharArrayList is empty or not
 * arguments: none
 * returns:   true if CharArrayList contains no elements, false otherwise
 * effects:   none
 */
bool CharArrayList::isEmpty() const {
    return numItems == 0;
}

/*
 * name:      clear
 * purpose:   make the instance into an empty array list
 * arguments: none
 * returns:   none
 * effects:   empties the array list
 */
void CharArrayList::clear() {
    numItems = 0;
}

/*
 * name:      size
 * purpose:   determine the number of items in the CharArrayList
 * arguments: none
 * returns:   number of elements currently stored in the CharArrayList
 * effects:   none
 */
int CharArrayList::size() const {
    return this-> numItems;
}

/*
 * name:      first
 * purpose:   returns the first character in the list
 * arguments: none
 * returns:   first character in the list, if list is empty
 *            should return runtime_error exception 
 * effects:   none
 */
char CharArrayList::first() const {
    if (numItems == 0) {
        throw std::runtime_error("cannot get first of"
                                " empty ArrayList");
    }
    return data[0];
}

/*
 * name:      last
 * purpose:   return last char in list
 * arguments: none
 * returns:   returns the last element (char) in the array list
 *             If list is empty it throws std::runtime_error 
 *             exception with the message
 * effects:   none
 */
char CharArrayList::last() const {
    if (numItems == 0) {
        throw std::runtime_error("cannot get last of"
                                " empty ArrayList");
    }
    return data[numItems - 1];
}

/*
 * name:      elementAt
 * purpose:   return element at index provided
 * arguments: takes an integer index 
 * returns:   returns the element (char) in the array 
 *            list at that index
 * effects:   none
 */
char CharArrayList::elementAt(int index) const {
    if (index < 0 || index >= numItems) {
        throw std::range_error("index (" + 
        std::to_string(index) + ") not in range [0.." + 
        std::to_string(numItems) + ")");
    }
    return data[index];
}

/*
 * name:      toString
 * purpose:   turns the array into a string, and returns it
 * arguments: none
 * returns:   a string representation of the array
 * effects:   none
 */
std::string CharArrayList::toString() const {
    std::stringstream ss;
    ss << "[CharArrayList of size " + 
    std::to_string(numItems) + " <<";
    for (int i = 0; i < numItems; i++) {
        ss << data[i];
        if (i < numItems - 1) {
            ss << "";
        }
    }
    ss << ">>]";
    return ss.str();
}

/*
 * name:      toReverseString()
 * purpose:   reverses a string
 * arguments: none
 * returns:   returns a string which contains the characters of the CharArrayList in reverse
 * effects:   reverses a string
 */
std::string CharArrayList::toReverseString() const {
    std::stringstream ss;
    ss << "[CharArrayList of size " + 
    std::to_string(numItems) + " <<";

    for(int i = numItems -1; i >=0; i--) {
        ss << data[i];
        if (i < numItems - 1) {
            ss << "";
        }
    }
     
    ss << ">>]";
    return ss.str();
}

/*
 * name:      pushAtBack
 * purpose:   push the provided integer into the back of the CharArrayList
 * arguments: char to add to the back of the list
 * returns:   none
 * effects:   increases num elements of CharArrayList by 1,
 *            adds element to list
 */
void CharArrayList::pushAtBack(char c) {
    if (numItems == capacity) {
        expand();
    }
    data[numItems++] = c;
}

/*
 * name:      pushAtFront
 * purpose:   push the provided integer into the front of the CharArrayList
 * arguments: char to add to the front of the list
 * returns:   none
 * effects:   increases num elements of CharArrayList by 1,
 *            adds element to list
 */
void CharArrayList::pushAtFront(char c) {
    if (numItems == capacity) {
        expand();
    }
    for (int i = numItems; i > 0; i--) {
        data[i] = data[i - 1];
    }

    data[0] = c;
    numItems++;
}

/*
 * name:      insertAt
 * purpose:   insert element at indicated index 
 * arguments: char, int 
 * returns:   none
 * effects:   Inserts character at specified index
 */
void CharArrayList::insertAt(char c, int index){
    if (index < 0 || index > numItems) {
        throw std::range_error("index (" + 
        std::to_string(index) + ") not in range [0.." + 
        std::to_string(numItems) + "]");
    }

    if (numItems == capacity) {
        expand();
    }
    for (int i = numItems; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = c;
    numItems++;
}

/*
 * name:      insertInOrder
 * purpose:   inserts elt into the array list in ASCII order
 * arguments: char 
 * returns:   none
 * effects:   inserts elt into the array list in ASCII order
 */
void CharArrayList::insertInOrder(char c) {
    if (numItems == capacity) {
        expand();
    }

    int index = 0;
    while (index < numItems && c > data[index]) {
        index++;
    }
    for (int i = numItems; i > index; i--) {
        data[i] = data[i - 1];
    }
    data[index] = c;
    numItems++;
}

/*
 * name:      popFromFront
 * purpose:   removes the first element from the array list
 * arguments: none 
 * returns:   none
 * effects:   removes the first element from the array list,
 *            list is empty should throw a C++ std::runtime_error exception
 */
void CharArrayList::popFromFront() {
    if (numItems == 0) {
        throw std::runtime_error("cannot pop from empty ArrayList");
    }

    for (int i = 0; i < numItems - 1; i++) {
        data[i] = data[i + 1];
    }

    numItems--;
}

/*
 * name:      popFromBack
 * purpose:   removes the last element from the array list
 * arguments: none 
 * returns:   none
 * effects:   removes the last element from the array list,
 *            list is empty should throw a runtime_error exception
 */
void CharArrayList::popFromBack() {
    if (numItems == 0) {
        throw std::runtime_error("cannot pop from empty ArrayList");
    }

    numItems--;
}

/*
 * name:      removeAt
 * purpose:   removes element at specified index
 * arguments: int 
 * returns:   none
 * effects:   removes element at specified index from the array list,
 *            if index is out of range should throw a range_error exception
 */
void CharArrayList::removeAt(int index) {
    if (index < 0 || index >= numItems) {
        throw std::range_error("index (" + 
        std::to_string(index) + ") not in range [0.." + 
        std::to_string(numItems) + ")");
    }
    
    for (int i = index; i < numItems - 1; i++) {
        data[i] = data[i + 1];
    }

    numItems--;
}

/*
 * name:      replaceAt
 * purpose:   It replaces the element at the specified index with the new element
 * arguments: char, int 
 * returns:   none
 * effects:   replaces element at specified index with the new element,
 *            if index is out of range should throw a range_error exception
 */
void CharArrayList::replaceAt(char c, int index) {
     if (index < 0 || index >= numItems) {
        throw std::range_error("index (" + 
        std::to_string(index) + ") not in range [0.." + 
        std::to_string(numItems) + ")");
    }

    data[index] = c;
}

/*
 * name:      concatenate
 * purpose:    It adds a copy of the array list pointed
               to by the parameter value to the end of the array list the function was
               called from
 * arguments: takes a pointer to a second CharArrayList 
 * returns:   none
 * effects:   concatenates one CharArrayList with a second CharArrayList
 */
void CharArrayList::concatenate(CharArrayList *other) {
    int newCapacity = numItems + other->numItems;

    if (newCapacity > capacity) {
        expand();
    }

    for (int i = 0; i < other->numItems; i++) {
        data[numItems++] = other->data[i];
    }
}

/*
 * name:      expand
 * purpose:   increase the capacity of the CharArrayList
 * arguments: none
 * returns:   none
 * effects:   creates new, larger array on heap, copies over elements,
 *            and recycles the old array
 */
void CharArrayList::expand() {
    int newCapacity = (capacity*2) + 2;
    char *newData = new char[newCapacity];

    for (int i = 0; i < numItems; i++) {
        newData[i] = data[i];
    }

    delete [] data;
    data = newData;
    capacity = newCapacity;
}