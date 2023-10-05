/*
 *  unit_tests.cpp
 *  Krystal Morales
 *  10/02/23
 *
 *  CS 15 HW 2 Cheshire ConCATenation - Time to linked up in Fur
 *
 *  The purpose of this file is to create unit tests for CharLinkedList
 *
 */

#include "CharLinkedList.h"
#include <cassert>
#include <iostream>

// Test default constructor
void test_default_constructor() {
    CharLinkedList list;
}

//Test size has been updated correctly and insert at back is correct
void test_pushAtBack() {
    CharLinkedList list;

    list.pushAtBack('a');
    list.pushAtBack('b');
    list.pushAtBack('c');

    std::string result = list.toString();
    std::cout << result << std::endl;
    
}

// Test toString properly strings characters
void test_toString() {
    CharLinkedList list;

    list.pushAtBack('A');
    list.pushAtBack('l');
    list.pushAtBack('i');
    list.pushAtBack('c');
    list.pushAtBack('e');

    std::string result = list.toString();
    std::string expected = "[CharLinkedList of size 5 <<Alice>>]";

    assert(result == expected);
}

//Test empty toString
void test_emptyToString() {
    CharLinkedList list;
    
    std::string result = list.toString();
    std::string expected = "[CharLinkedList of size 0 <<>>]";

    assert(result == expected);

}

// Test delete is deleteing without losing memory
void test_delete() {
    CharLinkedList *list = new CharLinkedList;
    
    list->pushAtBack('A');
    list->pushAtBack('l');
    list->pushAtBack('i');
    list->pushAtBack('c');
    list->pushAtBack('e');

    std::string listContents = list->toString();

    delete list;
}

// Test constructor with argument (char c), confirm it initializes 
// a 1 element list
void test_charConstructor() {
    CharLinkedList list('T');
   
    std::string listContents = list.toString();
    std::cout << listContents << std::endl;

}

//Test CharLinkedList(int [], char), make sure size is updated
void test_two_arg_charConstructor() {
    char arr_one[5] = {'H', 'e', 'l', 'l', 'o' };
    CharLinkedList list(arr_one, 5);

    std::cout << list.toString() << std::endl;
}

// Test size function, make sure correct size number comes back
void test_size_correct() {
    CharLinkedList list;

    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    assert(list.size() == 4);
}

// Test size comes back as 0
void test_size_0() {
    CharLinkedList list;

    std::string result = list.toString();
    std::string expected = "[CharLinkedList of size 0 <<>>]";

    assert(result == expected);
    assert(list.size() == 0);

}

// Test recursive function through elementAt
void test_elementAt() {
    CharLinkedList list;

    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    assert(list.elementAt(0) == '0');
    assert(list.elementAt(1) == '1');
    assert(list.elementAt(2) == '2');
    assert(list.elementAt(3) == '3');

    try {
        list.elementAt(-4);
        assert(false);
    } catch (std::range_error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try {
        list.elementAt(4);
        assert(false);
    } catch (std::range_error& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}

//Test we return first element
void test_first_element() {
    CharLinkedList list;

    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    assert(list.first() == '0');
}

// Test empty list and get first element
void test_empty_list() {
    CharLinkedList list;
    
    try {
        list.first();
    } catch (const std::runtime_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}

// catch exception for out of range
void test_insert_at_out_range() {
    CharLinkedList list;

    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    try {
    list.insertAt('1', -1);
    } catch (const std::range_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try {
    list.insertAt('5', 5);
    } catch (const std::range_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
    
}

// Test insert beginning
void test_insert_beginning() {
    CharLinkedList list;

    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    list.insertAt('1', 0);
    std::cout << list.toString() << std::endl;

}

// Test inset middle
void test_inset_middle() {
    CharLinkedList list;

    list.pushAtBack('0');
    list.pushAtBack('1');
    list.pushAtBack('2');
    list.pushAtBack('3');

    list.insertAt('1', 2);
    std::cout << list.toString() << std::endl;
}

// Test  insert at end
void test_insert_end() {
    char arr_one[4] = {'H', 'o', 'l', 'i' };
    CharLinkedList list(arr_one, 4);

    list.insertAt('s', 3);
    std::cout << list.toString() << std::endl;
}

// Test insert at beginning of empty list
void test_insert_empty_beginning() {
    CharLinkedList list;

    list.insertAt('k', 0);

    assert(list.elementAt(0) == 'k');
    assert(list.size() == 1);
}

// Test  insert at the index after the last element
void test_insert_after_last_element() {
    char arr_one[4] = {'H', 'o', 'l', 'i'};
    CharLinkedList list(arr_one, 4);

    std::cout << "Initial List: " << list.toString() << std::endl;

    list.insertAt('s', 4);

    std::cout << "Updated List: " << list.toString() << std::endl;
    
    assert(list.elementAt(4) == 's');
}

// Test isEmpty returns true if the list is empty
void test_isEmpty() {
    CharLinkedList list;

    assert(list.isEmpty() == true);
}

//Test isEmpty returns false
void test_isEmpty_false() {
    char arr_one[4] = {'H', 'o', 'l', 'i'};
    CharLinkedList list(arr_one, 4);

    assert(list.isEmpty() == false);
}

//Test clear() clears the list
void test_clear() {
    char arr_one[4] = {'H', 'o', 'l', 'i'};
    CharLinkedList list(arr_one, 4);

    list.clear();

    assert(list.isEmpty() == true);
}

//Test get last element
void test_get_last() {
    char arr_one[4] = {'H', 'o', 'l', 'i'};
    CharLinkedList list(arr_one, 4);

    assert(list.last() == 'i');
}

// Test get last exception
void test_last_exception() {
    char arr_one[4] = {'H', 'o', 'l', 'i'};
    CharLinkedList list(arr_one, 4);

    list.clear();
    assert(list.isEmpty() == true);

    try {
        list.last();
    } catch (const std::runtime_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}

// Test pushAtFront
void test_pushAtFront() {
    char arr_one[4] = {'H', 'o', 'l', 'i'};
    CharLinkedList list(arr_one, 4);

    list.pushAtFront('h');

    assert(list.first() == 'h');
}

// Test 100 element pushAtFront
void test_pushAtFront_100_elements() {
    CharLinkedList list;

    for (int i = 0; i < 100; i++) {
        list.pushAtFront('A' + i);
    }

    assert(list.size() == 100);

    std::cout << list.elementAt(0) << std::endl;
}


//Test reverse correctly reverses elements
void test_reverse() {
    CharLinkedList list;
    list.pushAtBack('A');
    list.pushAtBack('l');
    list.pushAtBack('i');
    list.pushAtBack('c');
    list.pushAtBack('e');

    std::cout << list.toString() << std::endl;

    std::cout << list.toReverseString() << std::endl;
}

//Test reverse empty
void test_reverse_empty() {
    CharLinkedList list;
    std::cout << list.toReverseString() << std::endl;
}

//Test insertInOrder middle
void test_insertInOrder_beginning() {
    CharLinkedList list;

    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('D');
    list.pushAtBack('E');
    list.pushAtBack('F');

    list.insertInOrder('C');

    assert(list.toString() ==  "[CharLinkedList of size 6 <<ABCDEF>>]");
}

//Test insertInOrder at end
void test_insertInOrder_end() {
    CharLinkedList list;

    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('D');
    list.pushAtBack('E');
    list.pushAtBack('F');

    list.insertInOrder('Z');

    assert(list.toString() ==  "[CharLinkedList of size 6 <<ABDEFZ>>]");
}

//Test insertInOrder empty list
void test_insertInOrder_empty() {
    CharLinkedList list;

    list.insertInOrder('A');

    std::cout << list.toString() << std::endl;
}

//Test popfromFront() 
void test_popfromFront() {
    CharLinkedList list;
    
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('D');
    list.pushAtBack('E');
    list.pushAtBack('F');

    list.popFromFront();

    assert(list.toString() == "[CharLinkedList of size 4 <<BDEF>>]");
    assert(list.elementAt(0) == 'B');
}

// Test pop fromFront() empty list
void test_popfromFront_empty() {
    CharLinkedList list;

    try {
        list.popFromFront();
    } catch (const std::runtime_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }
}

//Test popFromBack 
void test_popfromBack() {
    CharLinkedList list;
    
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('D');
    list.pushAtBack('E');
    list.pushAtBack('F');

    list.popFromBack();

    assert(list.toString() == "[CharLinkedList of size 4 <<ABDE>>]");
    assert(list.elementAt(3) == 'E');
}

// Test removeAt()
void test_removeAt() {
     CharLinkedList list;
    
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('D');
    list.pushAtBack('E');
    list.pushAtBack('F');

    list.removeAt(4);
    list.removeAt(3);
    list.removeAt(2);
    list.removeAt(1);
    list.removeAt(0);

    assert(list.size() == 0);
    assert(list.toString() == "[CharLinkedList of size 0 <<>>]");

}
//test removeAt() out of bounds
void test_removeAt_out_of_bounds() {
    CharLinkedList list;
    
    list.pushAtBack('A');
    list.pushAtBack('B');
    list.pushAtBack('D');
    list.pushAtBack('E');
    list.pushAtBack('F');
    
    try {
        list.removeAt(5);
    } catch (const std::range_error& e) {
    std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

}

// Test concatenation of two CharLinkedList
void test_concatente_two() {
    char arr_one[5] = { 'H', 'e', 'l', 'l', 'o' };
    CharLinkedList test_list1(arr_one, 5);

    char arr_two[5] = { 'W', 'o', 'r', 'l', 'd' };
    CharLinkedList test_list2(arr_two, 5);

    test_list1.concatenate(&test_list2);

   assert(test_list1.toString() == "[CharLinkedList of size 10 <<HelloWorld>>]");
}

//Test concatenation of one CharLinkedList and one empty CharLinkedList
void test_concatente_with_empty_list() {
    char arr_one[5] = { 'H', 'e', 'l', 'l', 'o' };
    CharLinkedList test_list1(arr_one, 5);

    CharLinkedList list;

    test_list1.concatenate(&list);

    assert(test_list1.toString() == "[CharLinkedList of size 5 <<Hello>>]");
}

//Test concatenation of the same CharLinkedList
void test_concatente_same_list() {
    char arr_one[5] = { 'H', 'e', 'l', 'l', 'o' };
    CharLinkedList test_list1(arr_one, 5);
    
    char arr_two[5] = { 'H', 'e', 'l', 'l', 'o' };
    CharLinkedList test_list2(arr_two, 5);

    test_list1.concatenate(&test_list2);

    assert(test_list1.toString() == "[CharLinkedList of size 10 <<HelloHello>>]");
}

// Test assignment operator
void test_assignment_operator() {
    char arr_one[5] = { 'H', 'e', 'l', 'l', 'o' };  
    CharLinkedList test_list1(arr_one, 5);
    
    char arr_two[5] = { 'W', 'o', 'r', 'l', 'd' };
    CharLinkedList test_list2(arr_two, 5);

    std::cout << "Before assignment:" << std::endl;
    std::cout << "test_list1: " << test_list1.toString() << std::endl;
    std::cout << "test_list2: " << test_list2.toString() << std::endl;

    test_list1 = test_list2;

    std::cout << "After assignment:" << std::endl;
    std::cout << "test_list1: " << test_list1.toString() << std::endl;
    std::cout << "test_list2: " << test_list2.toString() << std::endl;

    assert(test_list1.toString() == "[CharLinkedList of size 5 <<World>>]");
    assert(test_list2.toString() == "[CharLinkedList of size 5 <<World>>]");
}

// Test replaceAt, make sure element at index is updated
void test_replaceAt_correct() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharLinkedList test_list(test_arr, 8);

    test_list.replaceAt('A', 0);
    test_list.replaceAt('B', 1);

    assert(test_list.toString() == "[CharLinkedList of size 8 <<ABcdefgh>>]");
}

// Test replaceAt, make sure exception is thrown
void test_replaceAt_exception() {
    char test_arr[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    CharLinkedList test_list(test_arr, 8);

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

// Test concatenation of an empty CharLinkedList with a non-empty one
void test_concatenate_empty_with_nonempty() {
    CharLinkedList emptyList;

    char arr_non_empty[5] = { 'H', 'e', 'l', 'l', 'o' };
    CharLinkedList nonEmptyList(arr_non_empty, 5);

    emptyList.concatenate(&nonEmptyList);

    assert(emptyList.toString() == "[CharLinkedList of size 5 <<Hello>>]");
}

// Test concatenation of two non-empty CharLinkedList
void test_concatenate_nonempty_with_nonempty() {
    char arr_one[4] = { 'W', 'h', 'a', 't' };
    CharLinkedList list1(arr_one, 4);

    char arr_two[6] = { ' ', 'I', 's', ' ', 'U', 'p' };
    CharLinkedList list2(arr_two, 6);

    list1.concatenate(&list2);

    std::cout << list2.toString() << std::endl;
}

// Test for concatenates a non empty char list with itself  
void test_concatenation_nonEmpty_with_itself() {
    char arr_non_empty[17] = {'V', 'e', 'r', 'y', ' ', 'L', 'o', 'n', 'g', ' ', 'S', 't', 'r', 'i', 'n', 'g', ' ' };
    CharLinkedList nonEmptyList(arr_non_empty, 17);

    CharLinkedList copy(nonEmptyList); 

    nonEmptyList.concatenate(&copy);

    std::cout << nonEmptyList.toString() << std::endl;
    
    assert(nonEmptyList.toString() == "[CharLinkedList of size 34 <<Very Long String Very Long String >>]");
}

int main() {
    //test_pushAtBack();
    //test_toString();
    //test_delete();
    //test_charConstructor();
    //test_emptyToString();
    //test_two_arg_charConstructor();
    //test_size_correct();
    //test_size_0();
    //test_elementAt();
    //test_first_element();
    //test_empty_list();
    // test_insert_at_out_range();
    // test_insert_beginning();
    // test_inset_middle();
    // test_insert_end();
    // test_insert_empty_beginning();
    //test_insert_after_last_element();
    //test_isEmpty();
    //test_isEmpty_false();
    //test_clear();
    //test_get_last();
    //test_last_exception();
    //test_pushAtFront();
    //test_reverse();
    //test_reverse_empty();
    //test_insertInOrder_beginning();
    //test_insertInOrder_end();
    //test_popfromFront();
    //test_popfromFront_empty();
    //test_popfromBack();
    // test_removeAt();
    //test_removeAt_out_of_bounds();
    // test_concatente_two();
    //test_concatente_with_empty_list();
    //test_concatente_same_list();
   // test_assignment_operator();
   //test_replaceAt_correct();
    //test_replaceAt_exception();
    //test_pushAtFront_100_elements();
    //test_insertInOrder_empty();
    //test_concatenate_empty_with_nonempty();
    test_concatenation_nonEmpty_with_itself();
   // test_concatenate_nonempty_with_nonempty();
    return 0;
}
