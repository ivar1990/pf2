/*
 * This file contains the integer implementation of the linked list 
 * data structure of the standard c++ library
 */

/* 
 * File:   LinkedList.h
 * Author: ivar juarez
 *
 * Created on November 2, 2019, 7:50 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;

//aliases
typedef int element_type;
typedef element_type& reference;
typedef const element_type& const_reference;



class Linkedlist {
private: 
    // Basic Node structure
    struct Node
    {
        element_type elem;  // Data
        Node * next;        // Pointer to the next node in the chain
        Node * prev;        // Pointer to the previous node in the chain
    };
    
    
    Node* head; //start of linked list nodes
    Node* tail; // end of linked list nodes
    
public:
    
    
    Linkedlist(); //default constructor for empty list
    ~Linkedlist(); //destructor to free nodes dynamically created to support the linklist

    bool empty() const; // checks if there is any node in the linked list
    void clear();//removes all nodes from the linked list

    reference back();//returns the value of the last node in the linked list
    const_reference back() const;//returns the value of the last node in the linked list

    reference front();//returns the value of the first element in the linked list

    const_reference front() const;// returns the value of the first element in the linked list
    Linkedlist& operator=(const Linkedlist& l);//overload the assignment operator

    void pop_back ( );//removes the last node in the linked list

    void pop_front ( );//removes the first node in the linked list

    void push_back ( const element_type& x );//adds a node to the end of the linked list

    void push_front ( const element_type& x );//adds a node to the beginning of the linked list

    void sort ( );//sorts the linked list in ascending order
    
    // constructor that initializes the linked list with n nodes,
// with elem value from 0 to n-1
    explicit Linkedlist(unsigned int n);
    
// print the linked list in the forward direction,
// similar to the show function of lab6
    void check() const;
    
// print the linked list in the backward direction,
// similar to the reverse_show function of lab7
    void rcheck() const;
    
// insert a node with value specified by x after the node
// specified by pos. The first node has position 0.
// if the number of nodes in the linked list is less than
// pos, the node is inserted at the end.
    void insert(unsigned int pos, const element_type& x);
    
// remove the node specified by pos.
// if the number of nodes in the linked list is less than
// pos, the node at the end if any is removed.
void erase(unsigned int pos);

};

#endif /* LINKEDLIST_H */










