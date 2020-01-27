/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: imjuarez
 *
 * Created on September 11, 2019, 8:39 AM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

#include "mystrcat.h"
#include "mystrlen.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    

    char str1[80] = "hello! ";
    char my_str[50] = "world.";
    
    cout << "the length of 'line' is " << mystrlen(my_str) << endl;
    mystrcat(str1,my_str);
    
    cout << "The concatinated string is " << str1 << endl;
//        const char* str = "Hello!";
//    int length      = strlen(str);
//    
//    cout << "length: "<< length << endl;
//    
//    char line[] = "ls -l -a | wc -c >> myfile";
//    size_t len;
//    len = strlen(line);
//    cout << "the length of 'line' is " << len << endl;
//    
//    char* strArray[10]={"\0","\0","\0","\0","\0","\0","\0","\0","\0","\0"};
//    
//    int pieces =0;
//    char* ptr = strtok(line," ");
//    
//    
//    while(ptr != NULL)
//    {
//        strArray[pieces]=ptr;
//        ptr = strtok(NULL," ");
//        pieces++;
//    }
//    
//    for(int i=0; i < pieces; i++)
//    {
//        cout << "strArray[" << i << "]=" << strArray[i] << endl;
//    }
//    
//    size_t size = 0;
//    
//    for(int i=0; i < pieces; i++)
//    {
//        size = strlen(strArray[i]);
//    }
//    
//    
//    
//    size_t numBlanks = pieces - 1;
//    
//    cout << "The number of blanks is " << numBlanks << endl;
//    
//    char* result = new char[size + 1];
//    
//    result[0] = '\0';
//    
//    for(int i=0; i < pieces; i++)
//    {
//        strcat(result,strArray[i]);
//    }
//    
//    cout << "The concatenation of all strings in strArray is: " << result << endl;  
//    delete result;
    
    return 0;

}



    





























