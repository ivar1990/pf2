/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab8.cpp
 * Author: ivarmjuarez
 *
 * Created on October 16, 2019, 8:46 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain
};

// Print details about the given list, one Node per line
void show(Node* head)
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

// Print details about the given list in reverse order, one Node per line
void reverseShow(Node* tail)
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

// Print details about the given list in reverse order, one Node per line
Node* find_third_node_from_back(Node* tail, int pos)
{
     Node* current = tail;
    
    if (current == NULL)
        cout << "It is an empty list!" << endl;
    
    int i = 0;
    while (current != NULL) 
    {
        if(i == pos)
        {
            return current;
        }
        current = current->prev;
        i++;
    }
    
    return NULL;
}

int main(int argc, char** argv) {
    
const int size = 15;

    // Create the first node
    Node* head = new Node();
    head->elem = 0;
    head->prev = NULL;
    head->next = NULL;
    Node* tail = head;

    // Create a doubly linked list from the nodes
    for (int i = 1; i <= size; i++)
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
    show(head);
    reverseShow(tail);

    //2. add an element to the head of the list
    Node* new_node = new Node();
        new_node->elem = 100;
        new_node->prev = NULL;
        new_node->next = head;
        
        head->prev = new_node;
        
        head = new_node;
        
        show(head);
        reverseShow(tail);
        
        //3. insert an element at the back of the list
        Node* last_node = new Node();
        last_node->elem = -99;
        last_node->prev = tail;
        last_node->next = NULL;
        
        tail->next = last_node;
        
        tail = last_node;
        
        show(head);
        reverseShow(tail);
        
        //4. Removes the first node
        Node* tmp = head; //tmp holds the "head" node of the linked list
        head = tmp->next;//  reassign the "head" node to the first node
         //tmp becomes a dandling node that was the "head" node
        head->prev = NULL;
        //deletes the dangling node
        delete tmp;
    
        //display linked list
        show(head);
        reverseShow(tail);
        
        //5.Remove last node from the back
        Node* tmp2 = tail; 
        tail = tmp2->prev;
         
        tail->next = NULL;
        
        delete tmp2;
        
        //display linked list
        show(head);
        reverseShow(tail);
        
        //6.Find the third node from the back (the tail is index 0) and have a pointer variable, called tmp, to point to it 
        //(use a loop to do it, so we may easily change the third to the kth for any k). 
        //Based on the list you should currently have, this will be the node containing 12.
        Node* tmp3 = find_third_node_from_back(tail,3);
        cout << "Third node: " << tmp3->elem << endl;
        
        //7.Delete the node pointed by tmp from the doubly linked list, where tmp may point to any node in general.
        Node* tmp4 = tmp3; 
        tmp3 = tmp4->prev;
        
        tmp3->next = tmp4->next;
        tmp4->next->prev = tmp3;
       
        delete tmp4;
        
        //display linked list
        show(head);
        reverseShow(tail);
        
        
        
        
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
    
    return 0;
}























