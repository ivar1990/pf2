/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ivar juarez
 *
 * Created on December 11, 2019, 9:09 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>


using namespace std;

/*
 * 
 */

size_t mmHash(string key, size_t tableSize); 
size_t dmHash(string key, size_t tableSize); 

string randomKey(unsigned int min, unsigned int max);

int get_ascii_val(char ch);

int main(int argc, char** argv) {
    
    int key_size = 25000;
    int hash_table_size = 103981;
    
    int num_of_collisions =0;
    int num_of_linkedlists = 0;
    int max = 0;
    

    
    bool is_found = false;
    
    string keys[key_size];
    int hash_table[hash_table_size] = { 0 };
    
    string random_key = "";
    

    
     for(int i=0; i < key_size; i++)
    {
        random_key =  randomKey(3,5);
        
        
        for(int j=0; j <= i; j++)
        {
            
            if(keys[j] == random_key  )
            {
                //cout << i << ": " << random_key << endl;
                is_found = true;
                
            }
            
        }
        
        if(!is_found)
        {
            keys[i]= random_key;
            hash_table[dmHash(keys[i], hash_table_size)] ++;
        }
    }
    
    for(int n = 0; n < hash_table_size;n++)
    {
        
         if(hash_table[n]> max)
            {
                max = hash_table[n];
            }
         
         if(hash_table[n] >1)
         {
             //cout << n << ": " << hash_table[n] << endl;
             num_of_linkedlists++;
             num_of_collisions += hash_table[n];
         }
        
        
    }
    
  

    


    cout << key_size << " keys" <<endl;
    cout << "Number of collisions: " << num_of_collisions << endl;
    cout << "Maximum length of Linked List: " << max << endl;
    cout << "Number of Linked Lists: " <<  num_of_linkedlists << endl;
    
    cout << mmHash("a9B34", 103981) << endl; 
    cout << dmHash("a9B34", 103981) << endl; //print 71,113
//    
//    cout << dmHash("a9B34uvwXYZ1234500", 103981) << endl; // prints 40643. 
//    cout << mmHash("a9B34uvwXYZ1234500", 103981) << endl; // prints 90101. 
//    cout << dmHash("zyxwvutsrqpo", 103981) << endl; // prints 79631. 
//    cout << mmHash("zyxwvutsrqpo", 103981) << endl; // prints 53532. 
    
    return 0;
}

size_t dmHash(string key, size_t tableSize)
{
     
    size_t val=0; 
    size_t power=1;
    
    int n= key.size() -1;
   
    
    for(int i=n; i >=0; i--)
    {
         //get_ascii_val(key[i])
        val += (get_ascii_val(key[i]) * power) ;
        power = power *64;
        
    }
    return val%tableSize;
}

int get_ascii_val(char ch)
{
    int val =0;
    // assume c gets its value somehow 
        if (ch >= 48 && ch <= 57) 
            // digits 0 to 9 in ASCII 
            val = ch - 48;

        // assume c gets its value somehow 
        if (ch >= 65 && ch <= 90) 
            // digits 11 to 35 in ASCII 
            val = ch - 65 + 10;

        // assume c gets its value somehow 
        if (ch >= 97 && ch <= 122) 
            // digits 36 to 62 in ASCII 
            val = ch - 97 + 36;
        
        return val;
}

size_t mmHash(string key, size_t tableSize)
{
    size_t val=0; 
    size_t power=1;
    
    int n= key.size() -1;
   
    
    for(int i=n; i >=0; i--)
    {
         //get_ascii_val(key[i])
        val += (get_ascii_val(key[i]) * power) ;
        power = power *64;
        
    }
    //use the base formula to compute, n, from key ignoring overflow 
    double d = val * 0.61803398875; 
    //get the fractional part of d and call it 'f'
    
    double f, intpart;

    f= modf (d , &intpart);
    int index = f * tableSize; //(get the whole value part) 
    f = modf(index,&intpart);
    return intpart;
    
   // return 0;
}

// Generate random alphanumeric keys in [min,max] range
// min >= 1. Current alphabet includes 0 to 9, a to z, A to Z, and _ -
string randomKey(unsigned int min, unsigned int max)
{
    const int SIZE = 64;
    const char alphabet[SIZE]={'0','1','2','3','4','5','6','7','8','9',
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
    'q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G',
    'H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X',
    'Y','Z','-','_'};

    // simple error handling
    if (min == 0)
        min = 1;
    if (max < min)
        max = min;

    // pick a length between min and max
    int lenRange = max - min + 1;    
    int len      = rand() % lenRange;
    len          = len + min;

    // len is one of min, min+1,...max
    string s;
    for (int i = 0; i < len; i++)
        s.push_back(alphabet[rand() % SIZE]);
    
    return s;
}













































































