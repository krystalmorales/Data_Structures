/*
 * unit_tests.cpp
 *
 * CS 15 homework 1
 * by Tyler Calabrese, January 2021
 *
 * edited by: Milod Kazerounian, January 2022
 *
 * Example unit tests framework to test the CharArrayList class.
 *
 */

#include "CharArrayList.h"
#include <cassert>
#include <iostream>
#include <string>

/********************************************************************\
*                       CHAR ARRAY LIST TESTS                        *
\********************************************************************/

/* To give an example of thorough testing, we are providing
 * the unit tests below which test the insertAt function. Notice: we have
 * tried to consider all of the different cases insertAt may be
 * called in, and we test insertAt in conjunction with other functions!
 *
 * You should emulate this approach for all functions you define.
 */


// Tests correct insertion into an empty AL.
// Afterwards, size should be 1 and element at index 0
// should be the element we inserted.
void insertAt_empty_correct() {
    
        CharArrayList test_list;
        test_list.insertAt('a', 0);
        assert(test_list.size() == 1);
        assert(test_list.elementAt(0) == 'a');

}

// Tests incorrect insertion into an empty AL.
// Attempts to call insertAt for index larger than 0.
// This should result in an std::range_error being raised.
void insertAt_empty_incorrect() {
    
    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    CharArrayList test_list;
    try {
    // insertAt for out-of-range index
    test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
    // if insertAt is correctly implemented, a range_error will be thrown,
    // and we will end up here
    range_error_thrown = true;
    error_message = e.what();
    }

    // out here, we make our assertions
    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..0]");
    
}

// Tests correct insertAt for front of 1-element list.
void insertAt_front_singleton_list() {
    
    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at front
    test_list.insertAt('b', 0);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'b');
    assert(test_list.elementAt(1) == 'a');
    
}

// Tests correct insertAt for back of 1-element list.
void insertAt_back_singleton_list() {

    // initialize 1-element list
    CharArrayList test_list('a');

    // insert at back
    test_list.insertAt('b', 1);

    assert(test_list.size() == 2);
    assert(test_list.elementAt(0) == 'a');
    assert(test_list.elementAt(1) == 'b');

}

// Tests calling insertAt for a large number of elements.
// Not only does this test insertAt, it also checks that
// array expansion works correctly.
void insertAt_many_elements() {
    
    CharArrayList test_list;

    // insert 1000 elements
    for (int i = 0; i < 1000; i++) {
        // always insert at the back of the list
        test_list.insertAt('a', i);
    }

    assert(test_list.size() == 1000);

    for (int i = 0; i < 1000; i++) {
        assert(test_list.elementAt(i) == 'a');
    }
    
}

// Tests insertion into front of a larger list
void insertAt_front_large_list() {
    
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        test_list.insertAt('y', 0);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(0) == 'y');
        assert(test_list.toString() ==
        "[CharArrayList of size 9 <<yabcdefgh>>]");
    
}

// Tests insertion into the back of a larger list
void insertAt_back_large_list() {
    
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        test_list.insertAt('x', 8);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(8) == 'x');
        assert(test_list.toString() ==
        "[CharArrayList of size 9 <<abcdefghx>>]");
    
}

// Tests insertion into the middle of a larger list
void insertAt_middle_large_list() {
    
        char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
        CharArrayList test_list(test_arr, 8);

        test_list.insertAt('z', 3);

        assert(test_list.size() == 9);
        assert(test_list.elementAt(3) == 'z');
        assert(test_list.toString() ==
        "[CharArrayList of size 9 <<abczdefgh>>]");
    
}

// Tests out-of-range insertion for a non-empty list.
void insertAt_nonempty_incorrect() {
    
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    // var to track whether range_error is thrown
    bool range_error_thrown = false;

    // var to track any error messages raised
    std::string error_message = "";

    try {
        test_list.insertAt('a', 42);
    }
    catch (const std::range_error &e) {
        range_error_thrown = true;
        error_message = e.what();
    }

    assert(range_error_thrown);
    assert(error_message == "index (42) not in range [0..8]");
    
}

//Testing default constructor, ensuring that it can be 
// instantiated without any errors or exceptions
void test_default_constructor_instantiated() {
    CharArrayList list;
    std::cerr << "Testing default constructor" << std::endl;
}

//Testing default consructor is empty
void testing_default_constructor_is_empty() {
    CharArrayList list;
    assert(list.size() == 0);

    if (list.size() == 0) {
        std::cout << "Test Passed: list is empty" << std::endl;
    } else {
        std::cerr << "Test Failed: list is not empty" << std::endl;
    }
}

// Test CharArrayList constructor with char argument 
void test_char_constructor() {
    CharArrayList list('T');
    assert(list.size() == 1);
    assert(list.elementAt(0) == 'T');
}

//Test CharArrayList constructor with [] and int argument works correctly
void test_two_arg_constructor() { 
    char arr_one[5] = { 'H', 'e', 'l', 'l', 'o' };
    CharArrayList test_list1(arr_one, 5);

    assert(test_list1.size() == 5);
    assert(test_list1.elementAt(3) == 'l');
}

//Test copy constructor copies correctly
void test_copy_constructor() {
    CharArrayList original_list('1');

    original_list.pushAtBack('2');
    original_list.pushAtBack('3');

    CharArrayList copy(original_list);

    assert(copy.size() == original_list.size());
    assert(copy.elementAt(0) == '1');
    assert(copy.elementAt(1) == '2');
    assert(copy.elementAt(2) == '3');
}

//Test copy empty list
void test_copy_empty_list() {
    CharArrayList empty;

    assert(empty.isEmpty());

    empty.pushAtBack('1');
    empty.pushAtFront('0');

    CharArrayList copy(empty);

    assert(copy.size() == empty.size());
    assert(copy.elementAt(0) == '0');
    assert(copy.elementAt(1) == '1');
}

//Test delete is working
void test_delete() {
CharArrayList *list = new CharArrayList('A');
    list->pushAtBack('B');
    list->pushAtBack('C');

    assert(list->size() == 3);
    delete list;
    list = nullptr;
}

// isEmpty test make sure we report an empty list correctly.
void test_isEmpty_correct() {
    CharArrayList list;

    if (list.isEmpty()) {
        std::cout << "isEmpty Test1 Passed: ArrayList is empty" << std::endl;
    } else {
        std::cerr << "isEmpty Test1 Failed: ArrayList is not initialized empty" << std::endl;
    }

}

//Test that isEmpty will not return an empty list
void test_isEmpty_not_empty() {
    CharArrayList list;
     list.pushAtBack('K');

    if (!list.isEmpty()) {
        std::cout << "isEmpty Test2 Passed: CharArrayList is not empty" << std::endl;
    } else {
        std::cerr << "isEmpty Test2 Failed: CharArrayList is empty after adding a character" << std::endl;
    }
}

// Test that isEmpty will return an empty list after removing a character
void test_isEmpty_becomes_empty() {
    CharArrayList list;
    list.pushAtBack('K');
    list.popFromBack();

    if (list.isEmpty()) {
        std::cout << "isEmpty Test3 Passed: CharArrayList becomes empty after adding and removing a character" << std::endl;
    } else {
        std::cerr << "isEmpty Test3 Failed: CharArrayList is not empty after adding and removing a character" << std::endl;
    }
}

// Test clear function, make sure array list is empty
void test_clear() {
    CharArrayList list;

    list.pushAtBack('K');
    list.clear();

    if (list.isEmpty()) {
        std::cout << "clear Test1 Passed: ArrayList is empty" << std::endl;
    } else {
        std::cerr << "clear Test1 Failed: ArrayList is not initialized empty" << std::endl;
    }

}

// Test size function, make sure correct size number comes back
void test_size_correct() {
    CharArrayList list;

    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    assert(list.size() == 4);
}

//Test size comes back as 0
void test_size_0() {
    CharArrayList list;

    assert(list.size() == 0);
}

// Test first function, make sure list return first character 
void test_first_correct() {
    CharArrayList list;

    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    if (list.first() == '0') {
        std::cout << "First test passed: first returned 0" << std::endl;
    } else {
        std::cerr << "First test failed: first didn't returned 0" << std::endl;
    }
}

//Test if exception is thrown
void test_first_exception() {
    CharArrayList list;
    list.clear();
    try {
        list.first();
    } catch (const std::runtime_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}

// Test last funtion, make sure list return last character 
void test_last_correct() {
    CharArrayList list;

    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    if (list.last() == '3') {
        std::cout << "Last test passed: last returned 3" << std::endl;
    } else {
        std::cerr << "Last test failed: last didn't returned 3" << std::endl;
    }
}

// Test last function, make sure exception is thrown
void test_last_exception() {
    CharArrayList list;
    list.clear();
    try {
        list.last();
    } catch (const std::runtime_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}

// Test elementAt, make sure it returns elt at index
// and returns error if index is out of range
void test_elementAt_correct() {
    CharArrayList list;
    
    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    if (list.elementAt(0) == '0') {
        std::cout << "Element at index passed: returned 0" << std::endl;
    } else {
        std::cerr << "Element at index failed " << std::endl;
    }
}

// Test elementAt, make sure exception is thrown
void test_elementAt_exception() {
    CharArrayList list;
    try {
        list.elementAt(5);
    } catch (const std::range_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}

//Checks that the given list is as we expect it to be
void test_toString() {
   CharArrayList list;
   list.pushAtBack('A');
   list.pushAtBack('l');
   list.pushAtBack('i');
   list.pushAtBack('c');
   list.pushAtBack('e');
   std::string result = list.toString();
   std::cout << "Result: " << result << std::endl;
   assert(list.toString() == "[CharArrayList of size 5 <<Alice>>]");
}

//Test toReverse, make sure string is reversed
void test_toReverse_correct() { 
    CharArrayList list;
    list.pushAtBack('A');
    list.pushAtBack('l');
    list.pushAtBack('i');
    list.pushAtBack('c');
    list.pushAtBack('e');

    std::string result = list.toReverseString();
    std::cout << "Result: " << result << std::endl;
    assert(list.toReverseString() == "[CharArrayList of size 5 <<ecilA>>]");
}

//Test toReverse empty list
void test_toReverse_empty() {
    CharArrayList list;
    
    std::string result = list.toReverseString();
    assert(list.toReverseString() == "[CharArrayList of size 0 <<>>]");
}

// Test pushAtBack, make sure element is added to back
void test_pushAtBack() {
    CharArrayList list;

    list.pushAtBack('Z');

    int expectedNumItems = 1;

    if (list.size() == expectedNumItems) {
        std::cout << "Test1 Passed: Number of items correctly updated " << std::endl;
    } else {
        std::cerr << "Test2 Failed: Number of items not correctly updated " << std::endl;
    }

    std::cout << "NumItems added: " << list.toString() << std::endl;
    std::cout << "Number of items added: " << list.size() << std::endl;
}

// Test pushAtFront make sure element is added to the front
void test_pushAtFront_beginning() {
     CharArrayList list;

    list.pushAtBack('l');
    list.pushAtBack('i');
    list.pushAtBack('c');
    list.pushAtBack('e');

    list.pushAtFront('A');


    if (list.elementAt(0) == 'A') {
        std::cout << "Test1 Passed: Number of items correctly updated " << std::endl;
    } else {
        std::cerr << "Test2 Failed: Number of items not correctly updated " << std::endl;
    }

}

// Test insertAt making sure element is added at specified index
void test_insertAt() {
    CharArrayList list;

    list.pushAtBack('A');
    list.pushAtBack('l');
    list.pushAtBack('i');
    list.pushAtBack('c');
    list.pushAtBack('e');

    list.insertAt('H', 0);
    list.insertAt('E', 1);
    list.insertAt('L',2);
    list.insertAt('L',3);
    list.insertAt('O',4);
    list.insertAt(' ', 5);


    assert(list.toString() == "[CharArrayList of size 11 <<HELLO Alice>>]");
}

// Test insertInOrder, making sure element is added in ASCII order
void test_insertInOrder_beginning() {
    CharArrayList list;
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('D');
    list.pushAtBack('E');
    list.pushAtBack('F');

    list.insertInOrder('C');

    assert(list.toString() == "[CharArrayList of size 6 <<ABCDEF>>]");
}

//Test insertInOrder, add element to end
void test_insertInOrder_end() {
    CharArrayList list;
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('D');
    list.pushAtBack('E');
    list.pushAtBack('F');

    list.insertInOrder('Z');

    assert(list.toString() == "[CharArrayList of size 6 <<ABDEFZ>>]");
}

// Test popFromFront, make sure first element is removed
void test_popFromFront_correct() {
    CharArrayList list;
    
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('D');
    list.pushAtBack('E');
    list.pushAtBack('F');

    list.popFromFront();

    assert(list.toString() == "[CharArrayList of size 4 <<BDEF>>]");

}

// Test popFromFront, make sure exception is thrown
void test_popFromFront_exception() {
    CharArrayList list;
    
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('D');
    list.pushAtBack('E');
    list.pushAtBack('F');

    list.popFromFront();

    assert(list.toString() == "[CharArrayList of size 4 <<BDEF>>]");

    list.clear();
    try {
        list.popFromFront();
    } catch (const std::runtime_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

}

// Test popFromBack, make sure last element is removed
void test_popFromBack_correct() {
    CharArrayList list;
    
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('C');
    list.pushAtBack('D');
    list.pushAtBack('E');

    list.popFromBack();
    std::cout << list.toString() << std::endl;
    assert(list.toString() == "[CharArrayList of size 4 <<ABCD>>]");

}

// Test popFromBack, make sure exception is thrown 
void test_popFromBack_exception() {
    CharArrayList list;
    list.clear();
    try {
        list.popFromBack();
    } catch (const std::runtime_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}

// Test removeAt, make sure element at index is removed
// Size should be 1decrease by 1 and element at index 3
// should be removed
void test_removeAt_correct() {
    CharArrayList list;
    
    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    list.removeAt(3);

    assert(list.toString() == "[CharArrayList of size 3 <<012>>]");
}

// Test removeAt, make sure we catch the range exception
// if index is out of range
void test_removeAt_exception() {
    CharArrayList list;
    try {
        list.removeAt(5);
    } catch (const std::range_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}

// Test replaceAt, make sure element at index is updated
void test_replaceAt_correct() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    test_list.replaceAt('A', 0);
    test_list.replaceAt('B', 1);

    assert(test_list.toString() == "[CharArrayList of size 8 <<ABcdefgh>>]");
}

// Test replaceAt, make sure exception is thrown
void test_replaceAt_exception() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharArrayList test_list(test_arr, 8);

    try {
        test_list.replaceAt('k',-1);
    } catch (const std::range_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

     try {
        test_list.replaceAt('k',10);
    } catch (const std::range_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}

// Test concatenation of two CharArrayList
void test_concatente_two() {
    char arr_one[5] = { 'H', 'e', 'l', 'l', 'o' };
    CharArrayList test_list1(arr_one, 5);

    char arr_two[5] = { 'W', 'o', 'r', 'l', 'd' };
    CharArrayList test_list2(arr_two, 5);

    test_list1.concatenate(&test_list2);

    assert(test_list1.toString() == "[CharArrayList of size 10 <<HelloWorld>>]");
}

//Test concatenation of one CharArrayList and one empty CharArrayList
void test_concatente_with_empty_list() {
    char arr_one[5] = { 'H', 'e', 'l', 'l', 'o' };
    CharArrayList test_list1(arr_one, 5);

    CharArrayList list;

    test_list1.concatenate(&list);

    assert(test_list1.toString() == "[CharArrayList of size 5 <<Hello>>]");
}

//Test concatenation of the same CharArrayList
void test_concatente_same_list() {
    char arr_one[5] = { 'H', 'e', 'l', 'l', 'o' };
    CharArrayList test_list1(arr_one, 5);
    
    char arr_two[5] = { 'H', 'e', 'l', 'l', 'o' };
    CharArrayList test_list2(arr_two, 5);

    test_list1.concatenate(&test_list2);

    assert(test_list1.toString() == "[CharArrayList of size 10 <<HelloHello>>]");
}

int main() {
    // test_default_constructor_instantiated();
    // testing_default_constructor_is_empty();
    // test_isEmpty_correct();
    // test_isEmpty_not_empty();
    //test_isEmpty_becomes_empty();
    // test_clear();
    //test_size_correct();
    //test_size_0();
    //test_first_correct();
    //test_first_exception();
    //test_last_correct();
    //test_last_exception();
    //test_elementAt_correct();
    //test_elementAt_exception();
    //test_toString();
    //test_pushAtBack();
    // test_pushAtFront_beginning();
    // test_insertAt();
    // insertAt_empty_correct();
    // insertAt_empty_incorrect();
    // insertAt_front_singleton_list();
    // insertAt_back_singleton_list();
    // insertAt_many_elements();
    // insertAt_front_large_list();
    // insertAt_middle_large_list();
    // insertAt_nonempty_incorrect();
    // test_insertInOrder_beginning();
    // test_insertInOrder_end();
    // test_popFromFront_correct();
    // test_popFromFront_exception();
    // test_popFromBack_correct();
    // test_popFromBack_exception();
    // test_removeAt_correct();
    // test_removeAt_exception();
    //test_replaceAt_correct();
    //test_replaceAt_exception();
    // test_toReverse_correct();
    // test_toReverse_empty();
    // test_concatente_two();
    // test_concatente_with_empty_list();
    // test_concatente_same_list();
    // test_char_constructor();
    // test_two_arg_constructor();
    // test_copy_constructor();
    // test_copy_empty_list();
    test_delete();
    return 0;
}