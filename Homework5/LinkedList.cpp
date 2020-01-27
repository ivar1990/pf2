/*
 * Implementation of the linked list data structure of the 
 * c++ standard library
 * 
 * filename: LinkedList.cpp
 * Author: ivar juarez
 * Created on November 2, 2019, 7:50 PM
 */


#include "LinkedList.h"

Linkedlist::Linkedlist()
{
    //creates a default head node and tail node
    head = new Node();
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

 Linkedlist::Linkedlist(unsigned int n)
{
    //creates a default head node and tail node
    head = new Node();
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    tail = head;

    // Create a doubly linked list from the nodes
    for (int i = 1; i <= n; i++)
    {
        // Create the new node
        Node* node = new Node();
        node->elem = i;
        node->prev = tail;
        node->next = NULL;
        
        // Fold it into the list
        tail->next = node;
        
        // Move the tail
        tail = node;
    }
    check();
    rcheck();
}

Linkedlist::~Linkedlist()
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

 void Linkedlist::pop_back ( )
 {
     if(!empty())
     {
         //Remove last node from the back
            Node* tmp = tail; 
            tail = tmp->prev;

            tail->next = NULL;

            delete tmp;
     }
 }

    void Linkedlist::pop_front ( )
    {
        if(!empty())
        {
            // Removes the first node
            Node* tmp = head; //tmp holds the "head" node of the linked list
            head = tmp->next;//  reassign the "head" node to the first node
             //tmp becomes a dandling node that was the "head" node
            head->prev = NULL;
            //deletes the dangling node
            delete tmp;
        }
    }
    
    void Linkedlist::push_back ( const element_type& x )
    {
        //insert an element at the back of the list
        Node* last_node = new Node();
        last_node->elem = x;
        last_node->prev = tail;
        last_node->next = NULL;
        
        tail->next = last_node;
        
        //the last node becomes the tail
        tail = last_node;
    }

    void Linkedlist::push_front ( const element_type& x )
    {
        // add an element to the head of the list
        Node* new_node = new Node();
        new_node->elem = x;
        new_node->prev = NULL;
        new_node->next = head;
        
        head->prev = new_node;
        
        //the head becomes the new node
        head = new_node;
    }

//prints out the linked list in ascending order 
void Linkedlist::check() const
{
    Node* current = head;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->next;
        i++;
    }
    
    cout << "------------------------------------------------------------------------------------------" << endl;
}

//prints the linked list in descending order
void Linkedlist::rcheck() const
{
    Node* current = tail;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        cout << "Node "          << setw(3) << i             << "   "
             << "Elem: "         << setw(3) << current->elem << "   "
             << "Address: "      << setw(8) << current       << "   "
             << "Next Address: " << setw(8) << current->next << "   "
             << "Prev Address: " << setw(8) << current->prev << "   "
             << endl;
        current = current->prev;
        i++;
    }
    
    cout << "------------------------------------------------------------------------------------------" << endl;
}

//removes all elements from the linked list
void Linkedlist::clear()
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

reference Linkedlist::front()
{
    //returns the value of the first element in the list
        Node* first_node = head;
        return first_node->elem;
        
}

const_reference Linkedlist::front() const
{
    //returns the value of the first element in the list
        Node* first_node = head;
        return first_node->elem;
}

reference Linkedlist::back()
{
    //returns the value of the last element in the list
        Node* last_node = tail;
        return last_node->elem;
        
}

const_reference Linkedlist::back() const
{
    //returns the value of the last element in the list
        Node* last_node = tail;
        return last_node->elem;
        
}

void Linkedlist::erase(unsigned int pos)
{
    Node* current = head;
    Node* match = nullptr;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        if(i == pos)//the element at pos exists
        {
            match = current;
        }
        current = current->next;
        i++;
    }
    
    if(match != nullptr)//checks if the element at pos was found
    {
        //removes the element by
        //updating the next and previous nodes 
        //lastly frees  the memory pointed by tmp
        Node* tmp = match; 
        match = tmp->prev;
        
        match->next = tmp->next;
        tmp->next->prev = match;
       
        delete tmp;
    }
    else
    {
        //if the position is greater than the number of elements
        pop_back();
    }
}

void Linkedlist::insert(unsigned int pos, const element_type& x)
{
    Node* current = head;
    Node* match = nullptr;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        if(i == pos)
        {
            match = current;
        }
        current = current->next;
        i++;
    }
    
    if(match != nullptr)
    {
       //removes the element by
        //updating the next and previous nodes 
        //lastly frees  the memory pointed by tmp
         Node* new_node = new Node();
        new_node->elem = x;
        new_node->prev = match->prev;
        new_node->next = match;
        
        Node* prev_node = match->prev;
        new_node->prev = prev_node;
        prev_node->next = new_node;
        
        match->prev = new_node;
        
        
    }
    else
    {
        //inserts the element at the end of the linked list 
        //if the position is greater than the number of elements in the linked list
        push_back(x);
    }
}


bool Linkedlist::empty() const
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


Linkedlist& Linkedlist::operator=(const Linkedlist& l)
{

  clear();//deletes all nodes in the linked list previously
  
  //copies the head node from the referenced linked list
  head = new Node();
  head->elem= l.head->elem;
  head->next = l.head->next;
  head->prev = l.head->prev;
  tail = head;
   
  //copies all the elements in the linked list
  //into the new linked list
    Node* current = l.head->next;
    while(current != nullptr)
    {
        push_back(current->elem);
        current = current->next;
    }
    
    return *this;
}

void Linkedlist::sort()
{
  
    int swapped, i; 
    Node *ptr1; 
    Node *lptr = NULL; 
   
    /* Checking for empty list */
    if (head == NULL) 
        return; 
   
    do
    { 
        swapped = 0; 
        ptr1 = head; 
   
        while (ptr1->next != lptr) 
        { 
            //if the current value is greater the next element's value
            //swap the values
            if (ptr1->elem > ptr1->next->elem) 
            {  
                swap(ptr1->elem, ptr1->next->elem); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}

































