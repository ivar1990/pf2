/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab9.cpp
 * Author: ivarm
 *
 * Created on October 30, 2019, 8:34 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int factorial(int n);
int fibonacci(int n);
void sort(int* seq, int size );
void display(int* seq,int size);

int main(int argc, char** argv) {

    
    int arr[10] = {45,4,26,83,144,54,62,47,5,95};
    
    
    cout << "factorial 5 : " << factorial(5) << endl; 
    cout << "fibonacci 5 : " << fibonacci(5) << endl; 
    
    display(arr,10);
    sort(arr,10);
    
    display(arr,10);
    
    return 0;
}

int factorial(int n)
{
    if(n==1)
    {
        return 1;
    }
    //recursion
    return n*factorial(n-1);
    
}

int fibonacci(int n)
{
    if (n ==0)
    {
        return 1;
    }
    
    if(n==1)
    {
        return 1;
    }
    //recursion
    return fibonacci(n-1) + fibonacci(n-2);
    
}

void sort(int* seq, int size)
{
    
    if(size==1)
    {
        return;
    }
   
   int smallest = *seq;
   
   //use to travese the array in reverse order
    int i = size-1;
    while (i >0)
    {
        //swaps two values based on smallest
        if(smallest > *(seq+i))
        {
                smallest = *(seq+i);
            *(seq+i)= *seq;
            *seq = smallest;
        }
        i--;
    }
    
    sort(seq+1,size-1);//moves to the next element in the array
}

//prints out the array
void display(int* seq,int size)
{
    for(int i=0; i < size;i++ )
    {
        cout << seq[i] <<",";
    }
    cout << endl;
}


























































































