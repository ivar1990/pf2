/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ivarm
 *
 * Created on December 4, 2019, 8:54 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
//#include "Mystring.h"

//#define string Mystring

using namespace std;

/*
 * 
 */
void check (const string s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}
int main() 
{
    // Create an empty stack
    Stack<double> stack;
    
    // Add some elements to the stack
    for (int i = 0.0; i < 10.0; ++i)
        stack.push(i/100.0);
    
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
    Queue<double> queue;
    
    // Add some elements to the queue
    for (int i = 0.0; i < 10.0; ++i)
        queue.push(i/100.0);
    
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


















