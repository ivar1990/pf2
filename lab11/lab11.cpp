/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab11.cpp
 * Author: ivarm
 *
 * Created on November 13, 2019, 1:02 PM
 */

#include <cstdlib>

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    // Create an empty stack
    Stack stack;
    
    // Add some elements to the stack
    for (int i = 0; i < 10; ++i)
        stack.push(i);
    
    // Pop each element off of the stack
    while (!stack.empty())
    {
        cout << "Stack contains: ";
        stack.print();
        cout << "Stack Size: " << stack.size() << endl;
        
        cout << "Top: " << stack.top() << endl << endl;
        stack.pop(); 
    }
    
    //--------------------------------------------------//

     //--------------------------------------------------//
    
    // Create an empty queue
    Queue queue;
    
    // Add some elements to the queue
    for (int i = 0; i < 10; ++i)
        queue.push(i);
    
    // Pop each element off of the stack
    while (!queue.empty())
    {
        cout << "Queue contains: ";
        queue.print();
        cout << "Queue Size: " << queue.size() << endl;
        
        cout << "Front: " << queue.front() << endl << endl;
       queue.pop();
    }
    
    return 0;
}












