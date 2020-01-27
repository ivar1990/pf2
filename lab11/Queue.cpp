/*
 * File: Queue.cpp
 * Author: Ivar Juarez
 */

#include "Queue.h"

 Queue::Queue()
 {
     //creates a default head node and tail node
    head = new Node();
    head->elem = 0;
    //head->prev = NULL;
    head->next = NULL;
    
    numElements = 0;
     
    tail = head;
 }
    Queue::~Queue()
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
    
    // Capacity
    bool Queue::empty() const
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
    
    unsigned int Queue::size() const
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
    int& Queue::front()
    {
        
            //returns the value of the first element in the list
            Node* first_node = head;
            return first_node->elem;
      
    }
    
    const int& Queue::front() const
    {
       
            //returns the value of the first element in the list
            Node* first_node = head;
            return first_node->elem;
        
     
    }
    
    
    int& Queue::back()
    {
         
            //returns the value of the last element in the list
        Node* last_node = tail;
        return last_node->elem;
       
    }
    
    const int& Queue::back() const
    {
       
            //returns the value of the last element in the list
        Node* last_node = tail;
        return last_node->elem;
        
    }
    
    // Modification
    void Queue::push(const int& x)
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
    
    void Queue::pop()
    {
        Node* tmp = head; //tmp holds the "head" node of the linked list
        head = tmp->next;//  reassign the "head" node to the first node
        //tmp becomes a dandling node that was the "head" node
        //deletes the dangling node
        delete tmp;
        numElements--;
    }

    void Queue::print()
    {
         cout << "[ ";
        for (Node* cur = head; cur != NULL; cur = cur->next)
        {
            cout << cur->elem << " ";
        }
        cout << "]" << endl;
    }




















