/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: ivarm
 *
 * Created on December 4, 2019, 8:54 AM
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
    // Constructors
    Stack();
    ~Stack();
    
    // Capacity
    bool empty() const; 
    unsigned int size() const; 
    
    // Element access
    T& top(); 
    const T& top() const; 
    
    // Modification
    void push(const T& x); 
    void pop();
    
    void print();
    
private:
    T* buffer;              // The dynamically-allocated array that holds the stack
    unsigned int numElements; // The number of elements currently on the stack
     int topIndex;    // The index of the top of the stack (0 initially)
};

#endif /* STACK_H */
template <class T>
Stack<T>::Stack()
{
    topIndex = -1;
    numElements = 10;
    buffer = new T[numElements];
    
}

template <class T>
Stack<T>::~Stack()
{
    //free space
    delete[] buffer;
}

template <class T>
bool Stack<T>::empty() const
{
    
    return (topIndex==-1)?true:false;
}

template <class T>
unsigned int Stack<T>::size() const
{
    return numElements;
}

template <class T>
T& Stack<T>::top() 
{
    return buffer[topIndex];
}

template <class T>
const T& Stack<T>::top() const
{
    return buffer[topIndex];
}

template <class T>
void Stack<T>::pop() 
{
     // pop logic
    if (topIndex == numElements-1){
    // allocate less space
        T* tmp = new T[numElements-1];
     // copy over
        for(int i=0; i<numElements;i++)
        {
            tmp[i] = buffer[i];
        }        
     // free space
        delete[] buffer;
        buffer = tmp;
        numElements--;// reduce size
    }
     topIndex--;
}

template <class T>
void Stack<T>::push(const T& x) 
{
    // push x logic
    if (topIndex == numElements-1){
    // allocate twice the space
        T* tmp = new T[numElements * 2];
     // copy over
        for(int i=0; i<numElements;i++)
        {
            tmp[i] = buffer[i];
        }        
     // free space
        delete[] buffer;
        buffer = tmp;
        numElements *= 2;
    }
    topIndex++;
    buffer[topIndex]=x;
}

template <class T>
void Stack<T>::print()
{
    cout << "[ ";
    for (int i = 0; i < numElements; ++i)
    {
        cout << buffer[i] << " ";
    }
    cout << "]" << endl;
}












