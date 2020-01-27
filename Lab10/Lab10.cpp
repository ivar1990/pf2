

/* 
 * File:   Lab10.cpp
 * Author: ivar juarez
 *
 * Created on November 6, 2019, 8:34 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>


using namespace std;

/*
 * 
 */
// Given an sorted array of integers a[left] to a[right] 
// and value x to be searched 
// return -1 if x is not in the list or 
// return an index i where a[i] == x 
// using binary search algorithm 
int binarySearch(int* a, int left, int right, int x);

// Given an array of integers a[left] to a[right] as the sequence 
// return the maximum subsequence sum 
// using the recursive approach 
int mss(int* a, int left, int right); 

// Given an sorted array of integers a[left] to a[right] 
// and value x to be searched 
// return -1 if x is not in the list or 
// return an index i where a[i] == x 
// using linear search algorithm 
int linearSearch(int* a, int left, int right, int x); 

void sort(int* seq, int size );

//populate array
void populate(int * &array, int size);
void populateTest(int * &array, int size);

void print(int * array, int size);

int subseqSum(int * seqArray, int i, int j);

int algo1MSS(int * seqArray, int size);

int algo2MSS(int * seqArray, int size);

int find_max(int* a, int left, int right);

int main(int argc, char** argv) {

    
    // Space will be allocated by populateTest, and popolate
    int * array; 
    int * fixed_array;
    int size, result;
    clock_t start, end; // For timing of the code
    
    // This part would be done with a loop and would get the size 
    // of the array interactively in the real world
    size = 100000;
    
    //random array
    populate(array, size);
    
    populateTest(fixed_array,size);
    
    //print(array,size);
    
    cout << ".................Sorting Array.................." << endl;
    
    //sort(array,size);
    
    //print(array,size);
    
    cout << ".................Search not in Array.................." << endl;
    start  = clock();
    cout << "binary search index: " << binarySearch(fixed_array,0,size,-9734) << endl;
     end    = clock();
     cout << "It takes " << end - start << " clock ticks for binary search to obtain the result." << endl;
   
     start  = clock();
     cout << "linear search index: " << linearSearch(fixed_array,0,size,-9734) << endl;
    end    = clock();
    cout << "It takes " << end - start << " clock ticks for linear search to obtain the result." << endl;
    
    
    cout << ".................Search  in Array.................." << endl;
    start  = clock();
    cout << "binary search index: " << binarySearch(fixed_array,0,size,9734) << endl;
     end    = clock();
     cout << "It takes " << end - start << " clock ticks for binary search to obtain the result." << endl;
   
     start  = clock();
     cout << "linear search index: " << linearSearch(fixed_array,0,size,9734) << endl;
    end    = clock();
    cout << "It takes " << end - start << " clock ticks for linear search to obtain the result." << endl;
    
    
    // Execute and time algorithm 1
    start  = clock();
    result = mss(array,0, size);
    end    = clock();
    cout << "The result is " << result << endl;
    cout << "It takes " << end - start << " clock ticks for algorithm 1 to obtain the result." << endl;

   
    return 0;
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

// Initializes the array with arbitrary values.
void populate(int * &array, int size)
{
    srand(0);
    array = new int[size];
    
    for(int i = 0; i < size ; i++)
    {
        //Generate values between -10 * size and 10 * size
        array[i] = rand() % (size * 20 + 1) - size * 10;
    }
}

void populateTest(int * &array,int size)
{
    array = new int[size];
    for(int i = 0; i < size ; i++)
    {
        
        array[i] = i;
    }
}

// Prints the contents of the given array
void print(int * array, int size)
{
    for (int i = 0; i < size; i++)
        cout <<"Array[" << i << "] = " <<  array[i] << endl;
}

int subseqSum(int * seqArray, int i, int j)
{
    int sum = 0;
    for (;i <= j; i++)
    {
       //adds each element in the sub-sequence
        sum += seqArray[i];
    }
    
    return sum;
}   

int subseqSum(int prefixToaj, int aj)
{ 
    return prefixToaj + aj;
    
}

int algo1MSS(int * seqArray, int size)
{
    int sum = 0;
    int max = 0;
    for(int i = 0; i < size; i++)
    {
       
        for(int j = 1; j < size ; j++)
        {
            
            sum = subseqSum(seqArray,i,j);
            if (sum > max)
            {
                max = sum;
            }
        }
    }
    return max;
    
}

int algo2MSS(int * seqArray, int size)
{
  
    
    int sum = 0;
    int max = 0;
    
    for(int main_index = 0; main_index < size; main_index++)
    {
        //resets sum after each set of sub-sequences
        sum =0;
        
        //tracks the end index of each sub sequence
        for(int seq_end_index = main_index; seq_end_index < size; seq_end_index++)
        {
            //takes the sum of previous sub-sequence and adds it to
            // the end index of the current sub-sequence
            for(int seq_start_index = seq_end_index; seq_start_index < seq_end_index+1; seq_start_index++)
            {   
                sum = subseqSum(sum,seqArray[seq_start_index]);
            }
            
           //compares current sum with previous sum
            if (sum > max)
                {
                   max = sum;
                }
 
        }
    }
    return max;
}

// Given an sorted array of integers a[left] to a[right] 
// and value x to be searched 
// return -1 if x is not in the list or 
// return an index i where a[i] == x 
// using binary search algorithm 
int binarySearch(int* a, int left, int right, int x)
{
    //whenever search reaches the end of array
    if(left>right || right < left)
        return -1;
    //divides array into halves
    int middle = (left + right)/2;
    
    if(a[middle]==x)//the value is found
        return middle;
    else
        if(a[middle]<x)//searches second half
            return binarySearch(a,middle+1,right,x);
        else
            return binarySearch(a,left,middle-1,x);//searches first half
}



int linearSearch(int* a, int left, int right, int x)
{
    //search has reached the end of the array
    if(left>right)
        return -1;
    
    if(a[left]==x)//the value is found 
        return left;
    else
        return linearSearch(a,left+1,right,x);//from beginning to end
    
}

int mss(int* a, int left, int right)
{
    int max_sum =0;
    for(int i=0; i < right;i++)
    {
        
            
            int tmp = find_max(a,i,right-1);
            if (tmp > max_sum)
                max_sum = tmp;
    }
    
    return max_sum;
}

int find_max(int* a, int left, int right)
{
    int rm = 0;
            int lm = 0;

            for(int i = left; i <= right; i++)
            {
                lm = lm + a[i];
                if(lm > rm)
                {
                    rm=lm;

                }
            }
            return rm;
}



































































