/*
 * This file tests the implementation of the custom
 * linked list data structure
 */

/* 
 * File:   homework5.cpp
 * Author: ivar juarez
 *
 * Created on November 2, 2019, 7:51 PM
 */

#include <cstdlib>
#include "LinkedList.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    cout << "............................Test 1: Creates a linked list with 15 nodes..........................................." << endl;
    Linkedlist list(15);
    
    cout << "............................Test 2: Removes the node at the end of the linked list..........................................." << endl;
    list.pop_back();
    list.check();
    list.rcheck();
    
    cout << "............................Test 3: Inserts a node at the end of the linked list..........................................." << endl;
    list.push_back(16);
    list.check();
    list.rcheck();
    
    cout << "............................Test 4: Removes the node at the beginning of the linked list..........................................." << endl;
    list.pop_front();
    list.check();
    list.rcheck();
    
    cout << "............................Test 5: Inserts a node at the beginning of the linked list..........................................." << endl;
    list.push_front(-1);
    list.check();
    list.rcheck();
    
    cout << "............................Test 6: Gets the value of the first node in the linked list..........................................." << endl;
    cout << "first element value: " << list.front() << endl;
    
    cout << "............................Test 7: Gets the value of the last node in the linked list..........................................." << endl;
    cout << "last element value: " << list.back() << endl;
    
    list.check();
    list.rcheck();
    
    cout << "............................Test 8: Removes the node at position 5..........................................." << endl;
    list.erase(5);
    cout << "erased element 5." << endl;
    list.check();
    list.rcheck();
    
    cout << "............................Test 9: Inserts a node at position 9..........................................." << endl;
    list.insert(9,456);
    cout << "inserted element 9." << endl;
      list.check();
      list.rcheck();
      
      cout << "............................Test 10: Creates a new linked list ..........................................." << endl;
      cout << "Linked List 2" << endl;
      Linkedlist list2;
      cout << "............................Test 11: Assigns the old linked list to the newly created linked list..........................................." << endl;
      list2 = list;
      list2.check();
      list2.rcheck();
      
      
      cout << "............................Test 12: Sorts the linked list in ascending order..........................................." << endl;
      list.sort();
      list.check();
      list.rcheck();
      
      cout << "............................Test 13: Clears the linked list by removing all nodes..........................................." << endl;
      list.clear();
      list.check();
      list.rcheck();
      
      cout << "............................Test 14: Checks for an empty linked list..........................................." << endl;
        cout << "Is empty: " << list.empty()  << endl;
      list.check();
      list.rcheck();
      
    return 0;
}



























