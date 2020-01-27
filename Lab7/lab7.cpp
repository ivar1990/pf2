/* 
 * File:   main.cpp
 * Author: wingning
 *
 * Basic linked list
 */

#include <cstdlib>
#include <iostream>

using namespace std;

// Data element type, for now it is int, but we could change it to anything else
// by just changing this line
typedef int element_type;

// Basic Node structure
struct Node
{
    element_type elem;  // Data
    Node * next;        // Pointer to the next node in the chain
    Node * prev;        // Pointer to the previous node in the chain, not used for lab 7
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
        cout << "Node " << i << "\tElem: " << '\t' << current->elem << "\tAddress: " << current << "\tNext Address: " << current->next << endl;
        current = current->next;
        i++;
    }
    
    cout << "----------------------------------------------------------------------" << endl;
}

//gets the first matching value in the linked list
Node* find_first_of(Node* head, int position)
{
    //loop through the linked list
    Node* current = head;
    current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        //checks if the value we are looking for matches
        if(current->elem==position)
        {
            //returns first instance of the matching value
            return current;
        }
        
        current = next;
    }
    return nullptr;
}

int main() 
{
    const int size = 15;

    Node* head    = new Node();
    Node* current = head;

    // Create a linked list from the nodes
    for (int i = 0; i < size; i++)
    {
        current->elem = i;
        current->next = new Node();
        current       = current->next;
    }
    
    // Set the properties of the last Node (including setting 'next' to NULL)
    current->elem = size;
    current->next = NULL;
    show(head);

    // TODO: Your Code Here
    /*******************************************************************************************************/
    /*
     * 1. Removes the first element
     */
    
    Node* tmp = head; //tmp holds the "head" node of the linked list
    head = tmp->next;//  reassign the "head" node to the first node
    //tmp becomes a dandling node that was the "head" node
    //deletes the dangling node
    delete tmp;
    
    //display linked list
    show(head);
    /*******************************************************************************************************/
    
    /*******************************************************************************************************/
    /*
     * 2. Removes the last element
     */
    
    //keeps track of the previous node
    //contains the first node
    Node* prev_node = head;
    
    //holds the current node
    //contains the 2nd node
    Node* cnode = head->next;
    
    //holds the dangling node
    Node* tmp_node;
    
    //loop through the nodes
    while (cnode != NULL)
    {
        //assigns the current node until we find a match for the last element
        tmp_node = cnode;
        
        //holds the node after the current node
        Node* next_node = cnode->next;

        //the last element of a linked list will always have a pointer to the next node as NULL
        //It is the "NULL terminating character" of a linked list
        if(next_node==NULL)
        {
        //the current node has reached the end of the linked list
        //the tmp node holds the current node
        //the prev node contains the previous node
        prev_node->next = next_node; //this statement "cuts" the current node from the linked list
        delete tmp_node;//since tmp node holds a pointer to the dangling current node, it can now be deleted
        
        }
        
        //sets the current node to the previous node
        //sets the current node to the next node
        //traverses the linked list by moving the current node pointer
        prev_node= cnode;
        cnode = next_node;
    }
    show(head);
    /********************************************************************************************************************/
    
    /********************************************************************************************************************/
    /*
     * 3. Adds ten elements in descending order
     */
    //holds the head of the linked list
    Node* inode = head;
    
    //copies the 1st element in the linked list
    //holds the old list
    Node* original_first_element= new Node(); 
    original_first_element->prev= head->prev;
    original_first_element->elem = head->elem;
    original_first_element->next=head->next;

    // Create an entire new linked list 
    // variable i holds the amount of nodes to be created
    // variable j holds the value that the nodes will contain
    for (int i = 0, j=9; i < 10,j>0; i++,j--)
    {
        //assign node values 
        inode->elem = j;
        //creates the new node
        inode->next = new Node();
        //set it to the 
        inode       = inode->next;
    }
    //attaches the old list to the new list of nodes
    inode->next=original_first_element;
    show(head);
    /***************************************************************************************************************************/
    
    /***************************************************************************************************************************/
    /*
     * 4. Insert nodes after the first matching value in a linked list
     * Merges 3 list together
     * current list : 9,8,7,6,5,4,3,2,1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14
     * list 1 contains : 9,8,7
     * list 2 contains : 0,1,2,3,4,5,6,7,8,9
     * list 3 contains : 6,5,4,3,2,1,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14
     */
    
    //finds the first node that contains the value 7
    //cuts list 1 from the current list
    //contains list 1: 9-7
    Node* found_node = find_first_of(head,7);
    
    //holds the list of nodes after the node with the value 7
    //contains list 3: 6-14
    Node* element_after_found_node= new Node(); 
    element_after_found_node->prev= found_node->next->prev;
    element_after_found_node->elem = found_node->next->elem;
    element_after_found_node->next=found_node->next->next;
    
     //the "head" node of the linked list that will be inserted
    //contains list 2: 0-9 
    Node* new_node= new Node(); 
    
    //insert head of list 2 into list 1
    //cuts list 3 from list 1
    found_node->next = new_node;
    
    

    // Creates list 2: 0-9
    for (int i = 0; i<10; i++)
    {
        new_node->elem = i;
        new_node->next = new Node();
        
        new_node       = new_node->next;
    }
    //attaches list 3
    new_node->elem = element_after_found_node->elem;
    new_node->prev = element_after_found_node->prev;
    new_node->next = element_after_found_node->next;
   
    delete element_after_found_node;
    show(head);
    /*************************************************************************************************************************************/
    
    // Clean up
    current = head;
    while (current != NULL)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}




























