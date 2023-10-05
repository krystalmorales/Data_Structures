/*
 *  CharLinkedList.h
 *  Krystal Morales
 *  10/02/23
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to get linked up in Fur
 *
 *  The purpose of this file is to create the interface for a CharLinkedList 
 *
 */

#ifndef CHAR_LINKED_LIST_H
#define CHAR_LINKED_LIST_H

#include <string>

class CharLinkedList {
public:
    CharLinkedList();
    CharLinkedList(char c);
    CharLinkedList(char arr[], int size);
    CharLinkedList(const CharLinkedList &other);

    ~CharLinkedList();

    CharLinkedList &operator=(const CharLinkedList &other);
    bool isEmpty() const;
    void clear();
    int size() const;
    char first() const;
    char last() const;
    char elementAt(int index) const;
    std::string toString() const;
    std::string toReverseString() const;
    void pushAtBack(char c);
    void pushAtFront(char c);
    void insertAt(char c, int index);
    void insertInOrder(char c);
    void popFromFront();
    void popFromBack();
    void removeAt(int index);
    void replaceAt(char c, int index);
    void concatenate(CharLinkedList *other);

private:
    struct Node {
        char data;
        Node *next; 
        Node *prev;
        Node(char value, Node *aNext, Node *aPrev) : data(value), next(aNext), prev(aPrev) {}
        Node(char value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node *front;
    int numItems;

    char recursive(Node *curr, int targetIndex, int currentIndex) const; 
    void replaceAtRecursive(Node *current, char c, int targetIndex, int currentIndex);
};

#endif
