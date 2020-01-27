/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: ivarm
 *
 * Created on December 4, 2019, 8:56 AM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <iostream>
using namespace std;



template <class T>
class Queue
{
public:
    // Constructors
    Queue();
    ~Queue();
    
    // Basic Node structure
    struct Node
    {
        T elem;    // Data
        Node * next; // Pointer to the next node in the chain
    };
    
    // Capacity
    bool empty() const; 
    unsigned int size() const; 
    
    // Element access
    T& front(); 
    const T& front() const; 
    T& back(); 
    const T& back() const; 
    
    // Modification
    void push(const T& x);
    void pop();

    void print();
    
private:
    Node* head;               // The front of the queue
    Node* tail;               // The end of the queue
    unsigned int numElements; // The number of elements in the queue
};

#endif /* QUEUE_H */

template <class T>
Queue<T>::Queue()
 {
     //creates a default head node and tail node
    head = new Node();
   // head->elem = 0;
    //head->prev = NULL;
    head->next = NULL;
    
    numElements = 0;
     
    tail = head;
 }

template <class T>
    Queue<T>::~Queue()
    {
        // Clean up
        Node* current = head;
        while (current != NULL)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        tail = NULL;
    }
    
template <class T>
    // Capacity
    bool Queue<T>::empty() const
    {
        //if the head is a nullptr there is no 
        //element in the linked list
        if(head==nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
template <class T>
    unsigned int Queue<T>::size() const
    {
          Node* current = head;

            if (current == NULL)
                return 0;

            int i = 0;
            while (current != NULL) 
            {
                i++;
                current = current->next;
            }
            //numElements = i;
            return i;
    }
    
    // Element access
template <class T>
    T& Queue<T>::front()
    {
        
            //returns the value of the first element in the list
            Node* first_node = head;
            return first_node->elem;
      
    }
    
template <class T>
    const T& Queue<T>::front() const
    {
       
            //returns the value of the first element in the list
            return head->elem;
        
     
    }
    
    template <class T>
    T& Queue<T>::back()
    {
         
            //returns the value of the last element in the list
        return tail->elem;
       
    }
    
    template <class T>
    const T& Queue<T>::back() const
    {
       
            //returns the value of the last element in the list
        return tail->elem;
        
    }
    
    // Modification
    template <class T>
    void Queue<T>::push(const T& x)
    {
        //checks if the head node is the only node in the list
        if(numElements ==0)
        {    
            head->elem= x;
            numElements++;//increase the number of elements
                                                           
        }
        else
        {
             //insert an element at the back of the list
            Node* last_node = new Node();
            last_node->elem = x;
            //last_node->prev = tail;
            last_node->next = NULL;

            tail->next = last_node;

            //the last node becomes the tail
            tail = last_node;
            numElements++;
        }
    }
    
    template <class T>
    void Queue<T>::pop()
    {
        Node* tmp = head; //tmp holds the "head" node of the linked list
        head = tmp->next;//  reassign the "head" node to the first node
        //tmp becomes a dandling node that was the "head" node
        //deletes the dangling node
        delete tmp;
        numElements--;
    }

    template <class T>
    void Queue<T>::print()
    {
         cout << "[ ";
        for (Node* cur = head; cur != NULL; cur = cur->next)
        {
            cout << cur->elem << " ";
        }
        cout << "]" << endl;
    }


























