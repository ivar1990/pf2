/*
 * File: Stack.cpp
 * Author: Ivar Juarez
 */


#include "Stack.h"

Stack::Stack()
{
    topIndex = -1;
    numElements = 5;
    buffer = new int[numElements];
    
}

Stack::~Stack()
{
    //free space
    delete[] buffer;
}

bool Stack::empty() const
{
    
    return (topIndex==-1)?true:false;
}

unsigned int Stack::size() const
{
    return numElements;
}

int& Stack::top() 
{
    return buffer[topIndex];
}

const int& Stack::top() const
{
    return buffer[topIndex];
}

void Stack::pop() 
{
     // pop logic
    if (topIndex == numElements-1){
    // allocate less space
        int* tmp = new int[numElements-1];
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

void Stack::push(const int& x) 
{
    // push x logic
    if (topIndex == numElements-1){
    // allocate twice the space
        int* tmp = new int[numElements * 2];
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

void Stack::print()
{
    cout << "[ ";
    for (int i = 0; i < numElements; ++i)
    {
        cout << buffer[i] << " ";
    }
    cout << "]" << endl;
}












