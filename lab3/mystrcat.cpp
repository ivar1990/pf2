/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//#include <cstdlib>

#include "mystrcat.h"

using namespace std;
char* mystrcat(char *destination, const char *source)
{
    char* ptr = nullptr;
    bool stop = false;
    //searches for the null character in the string
    do 
    {
        
        if(*destination=='\0' )
        {
            //set the pointer to the null character
            ptr = destination;
            stop = true;
            destination--;
        }
       //moves the string pointer
        destination++;
    
    } while (stop != true);
    
    //loops the characters of the string we want to copy
    for(int index=0;source[index]!='\0';index++)
    {
        //places the characters of the source string into the destination string
        *ptr = source[index];
        ptr++;
    }
    return &destination[0];
}












