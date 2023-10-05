/*
 *  CharLinkedList.cpp
 *  Krystal Morales
 *  10/2/23
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  The purspose of this file is to implement the CharLinkedList 
 *  interface
 *
 */

#include "CharLinkedList.h"
#include <sstream>
#include <string>

/*
* name: CharLinkedList default constructor
* purpose: initialize an empty CharLinkedList
* arguments: none
* return: none 
* effects: size to 0
*/
CharLinkedList::CharLinkedList() {
    front = nullptr;
    numItems = 0;
}

/*
* name: CharLinkedList(char c)
* purpose: creates a one element linked list consisting of that character
* arguments: a single character 
* return: none
* effects: Initializes a single character list consisting of that character
*/
CharLinkedList::CharLinkedList(char c) {
    front = new Node(c);
    numItems = 1;
}

/*
* name: CharLinkedList(char arr[], int size)
* purpose:  create an array containing the characters in the array
* arguments: takes an array of characters and the integer
*           length of that array of characters as parameters
* return: none
* effects: Initializes an array list containing the characters in the array
*/
CharLinkedList::CharLinkedList(char arr[], int size) {
    front = nullptr;
    numItems = 0;

    for (int i =0; i < size; i++) {
        pushAtBack(arr[i]);
    }
}

/*
 * name:      CharLinkedList(const CharLinkedList &other)
 * purpose:   A copy constructor for the class that makes 
 *            a deep copy of a given instance
 * arguments: a reference to another CharLinkedList 
 *            instance to copy from
 * returns:   
 * effects:   Creates a deep copy of the given instance   
 */
CharLinkedList::CharLinkedList(const CharLinkedList &other) {
    front = nullptr;
    numItems = 0;

    Node *otherCurr = other.front;
    while (otherCurr != nullptr) {
        pushAtBack(otherCurr->data);
        otherCurr = otherCurr->next;
    }
}

/*
 * name:      CharLinkedList destructor
 * purpose:   free memory associated with the CharLinkedList
 * arguments: none
 * returns:   none
 * effects:   frees memory allocated by CharLinkedlist instances
 */
CharLinkedList::~CharLinkedList() {
    Node *curr = front;
    while (curr != nullptr) {
        Node *nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    front = nullptr;
}

/*
 * name:      CharLinkedList &operator
 * purpose:   recycles the storage associated with the instance on the 
 *            left of the assignment and makes a deep copy of the 
 *            instance on the right hand side into the instance on the 
 *            left hand side.
 * arguments: const CharLinkedList &other
 * returns:   CharLinkedList
 * effects:   makes a deep copy of the instance on the right hand side into the 
 *            instance on the left hand side.
 */
CharLinkedList& CharLinkedList::operator=(const CharLinkedList &other) {
    if (this == &other) {
        return *this;
    }
    
    clear();

    Node *otherCurr = other.front;
    while (otherCurr != nullptr) {
        pushAtBack(otherCurr->data);
        otherCurr = otherCurr->next;
    }

    return *this;
}

/*
 * name:      pushAtBack
 * purpose:   push the provided character to the back of the list
 * arguments: char to add to the back of the list
 * returns:   none
 * effects:   increases size by 1, adds element to list
 */
void CharLinkedList::pushAtBack(char c) {
    Node *newNode = new Node(c);

    if(front == nullptr) {
        front = newNode;
    } else {
        Node *n = front;
        while(n->next != nullptr) {
            n = n->next;
        }
        n->next = newNode;
        newNode->prev = n;
    }
    numItems++;
}

/*
 * name:      toString
 * purpose:   turns the linkedlist into a string, and returns it
 * arguments: none
 * returns:   a string representation of the list
 * effects:   none
 */
std::string CharLinkedList::toString() const {
    std::stringstream ss;
    ss << "[CharLinkedList of size " << numItems << " <<";

    Node *curr = front;
    while (curr != nullptr) {
        ss << curr->data;
        curr = curr->next;
    }
    ss << ">>]";
    return ss.str();
}

/*
 * name:      size
 * purpose:   determine the number of items in the CharlinkedList
 * arguments: none
 * returns:   number of elements currently stored in the CharLinkedList
 * effects:   none
 */
int CharLinkedList::size() const {
    return this-> numItems;
}

/*
 * name:      elementAt
 * purpose:   return element at index provided
 * arguments: takes an integer index 
 * returns:   returns the element (char) in the list 
 *            list at that index
 * effects:   none
 */
char CharLinkedList::elementAt(int index) const {
    if (index < 0 || index >= numItems) {
        throw std::range_error("index (" + std::to_string(index) + ") not in range [0.." 
        + std::to_string(numItems) + ")");
    }

    return recursive(front, index, 0);
}

/*
 * name:      recursive
 * purpose:   recursively search for and retrieve the character at index
 * arguments: takes the target and current index, and pointer to curr node
 * returns:   returns character at specified index
 * effects:   none
 */
char CharLinkedList::recursive(Node *curr, int targetIndex, int currentIndex) const {
    if (currentIndex == targetIndex) {
        return curr->data;
    }
    if (curr->next == nullptr) {
        throw std::range_error("index (" + std::to_string(targetIndex) + ") not in range [0.." 
        + std::to_string(numItems) + ")");
    }
    return recursive(curr->next, targetIndex, currentIndex +1);
}

/*
 * name:      first
 * purpose:   returns the first character in the list
 * arguments: none
 * returns:   returns the first character in the list
 * effects:   none
 */
char CharLinkedList::first() const {
    if (front == nullptr) {
        throw std::runtime_error("cannot get first" 
        " of empty LinkedList");
    }
    return front->data;
}

/*
 * name:      insertAt
 * purpose:   inserts the new element at the specified index
 * arguments: char c, int index
 * returns:   none
 * effects:   none
 */
void CharLinkedList::insertAt(char c, int index) {
    if(index < 0 || index > numItems) {
        throw std::range_error("index (" + std::to_string(index) + ") not in range [0.." 
        + std::to_string(numItems) + "]");
    }

   Node *aNewNode = new Node(c);

    if(index == 0) {
        aNewNode->next = front;
        aNewNode->prev = nullptr;
        if (front != nullptr) {
            front->prev = aNewNode;
        }
        front = aNewNode;
    } else if (index == numItems) {
        Node *curr = front;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = aNewNode;
        aNewNode->prev = curr;
        aNewNode->next = nullptr;
    } else {
        Node *curr = front;
        for(int i = 0; i < index; i++) {
            curr = curr->next;
        }
        aNewNode ->next = curr;
        aNewNode->prev = curr->prev;
        if (curr->prev != nullptr) {
            curr->prev->next = aNewNode;
        }
        curr->prev = aNewNode;
    }
    numItems++;
}

/*
 * name:      isEmpty
 * purpose:   determines if the CharLinkedList is empty or not
 * arguments: none
 * returns:   true if CharLinkedList contains no elements, false otherwise
 * effects:   none
 */
bool CharLinkedList::isEmpty() const {
    return front == nullptr;
}

/*
 * name:      clear
 * purpose:   make the instance into an empty list
 * arguments: none
 * returns:   none
 * effects:   empties the list
 */
void CharLinkedList::clear() {
    while (front != nullptr) {
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    numItems = 0;
}

/*
 * name:      last
 * purpose:   return last char in list
 * arguments: none
 * returns:   returns the last element (char) in the list
 *             If list is empty it throws std::runtime_error 
 *             exception with the message
 * effects:   none
 */
char CharLinkedList::last() const {
    if (front == nullptr) {
        throw std::runtime_error("cannot get last" 
        " of empty LinkedList");
    }

    Node *curr = front;
    while(curr->next != nullptr) {
        curr = curr->next;
    }
    return curr->data;
}

/*
 * name:      pushAtFront
 * purpose:   inserts the given new element in front of the 
 *             existing elements of the list
 * arguments: char c
 * returns:   none
 * effects:   inserts the given element to the front of the list
 */
void CharLinkedList::pushAtFront(char c) {
    Node *aNewNode = new Node(c);

    if (front == nullptr) {
        front = aNewNode;
    } else {
        aNewNode->next = front;
        aNewNode->prev = nullptr;
        front->prev = aNewNode;
        front = aNewNode;
    }
    numItems++;

}


/*
 * name:      toReverseString()
 * purpose:   returns characters into a string in reverse
 * arguments: none
 * returns:   returns a string which contains the characters of the list in reverse
 * effects:   reverses a string
 */
std::string CharLinkedList::toReverseString() const {
    std::stringstream ss;

    ss << "[CharLinkedList of size " << numItems << " <<";

    if(numItems > 0) {
        Node *curr = front;

        while(curr->next != nullptr) {
            curr = curr->next;
        }

        while (curr != nullptr) {
            ss << curr->data;
            curr = curr->prev;
        }
    }
    ss << ">>]";
    return ss.str();
}

/*
 * name:      insertInOrder
 * purpose:   inserts elt into the list in ASCII order
 * arguments: char 
 * returns:   none
 * effects:   inserts elt into the array list in ASCII order
 */
void CharLinkedList::insertInOrder(char c) {
    Node *newNode = new Node(c);

    if (front == nullptr) {
        front = newNode;
    } else if (c <= front->data) {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    } else {
        Node *curr = front;

        while (curr->next != nullptr && c > curr->next->data) {
            curr = curr->next;
        }
        if (curr->next != nullptr) {
            newNode->next = curr->next;
            curr->next->prev = newNode;
        }
        newNode->prev = curr;
        curr->next = newNode;
    }
    numItems++;
}

/*
 * name:      popFromFront
 * purpose:   removes the first element from the list
 * arguments: none 
 * returns:   none
 * effects:   removes the first element from the list,
 *            list is empty should throw a C++ std::runtime_error exception
 */
void CharLinkedList::popFromFront() {
    if (front == nullptr) {
        throw std::runtime_error("cannot pop from empty LinkedList");
    }

    Node *curr = front;
    front = curr->next;
    //front->next == null, front->next= front;
    if(front != nullptr) {
        front->prev = nullptr;
    }

    delete curr;
    numItems--;
}

/*
 * name:      popFromBack
 * purpose:   removes the last element from the list
 * arguments: none 
 * returns:   none
 * effects:   removes the last element from the list,
 *            list is empty should throw a runtime_error exception
 */
void CharLinkedList::popFromBack() {
     if (front == nullptr) {
        throw std::runtime_error("cannot pop from empty LinkedList");
    }

    if (front->next == nullptr) {
        delete front;
        front = nullptr;
    } else {
        Node *curr = front;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        curr->prev->next = nullptr;
        delete curr;
    }
    numItems--;
}

/*
 * name:      removeAt
 * purpose:   removes element at specified index
 * arguments: int 
 * returns:   none
 * effects:   removes element at specified index from the list,
 *            if index is out of range should throw a range_error exception
 */
void CharLinkedList::removeAt(int index) {
    if (index < 0 || index >= numItems) { 
        throw std::range_error("index (" + 
        std::to_string(index) + ") not in range [0.." + 
        std::to_string(numItems) + ")");
    }

    if (index == 0) {
        Node *temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        }
        delete temp;
    } else {
        Node *curr = front;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }
        delete curr;
    }

    numItems--;
    }

/*
 * name:      concatenate
 * purpose:    It adds a copy of the list pointed
               to by the parameter value to the end of the list the function was
               called from
 * arguments: takes a pointer to a second CharLinkedList 
 * returns:   none
 * effects:   concatenates one CharLinkedList with a second CharLinkedList
 */
void CharLinkedList::concatenate(CharLinkedList *other) {
   if (other == nullptr || other->isEmpty()) { 
        return;
    }

    CharLinkedList otherCopy(*other);

    if (isEmpty()) {
       front = otherCopy.front; 
       numItems = otherCopy.numItems;
    } else {
        Node *curr = front;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = otherCopy.front;
        if (otherCopy.front != nullptr) {
            otherCopy.front->prev = curr;
        }

        numItems += otherCopy.numItems;
    }
    otherCopy.front = nullptr;
}

/*
 * name:      replaceAt
 * purpose:   It replaces the element at the specified index with the new element
 * arguments: char, int 
 * returns:   none
 * effects:   replaces element at specified index with the new element,
 *            if index is out of range should throw a range_error exception
 */
void CharLinkedList::replaceAt(char c, int index) {
    if (index < 0 || index >= numItems) {
        throw std::range_error("index (" + std::to_string(index) + ") not in range [0.." 
        + std::to_string(numItems) + ")");
    }

    return replaceAtRecursive(front, c, index, 0);
}


/*
 * name:      replaceAtRecursive
 * purpose:   recursively search for and replace the character at index
 * arguments: takes the target and current index, and pointer to curr node, and char to replace
 * returns:   none
 * effects:   replaces character at index
 */
void CharLinkedList::replaceAtRecursive(Node *current, char c, int targetIndex, int currentIndex) {
    if (currentIndex == targetIndex) {
        current->data = c;
        return; 
    }

    if (current->next != nullptr) {
        replaceAtRecursive(current->next, c, targetIndex, currentIndex + 1);
    }
}