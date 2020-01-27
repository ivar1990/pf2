/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "mystrlen.h"
size_t mystrlen(const char *str)
{
    unsigned int size = 0;
    //loop string elements
    for(int index=0;str[index]!='\0';index++)
    {
        //counts the elements
        size= size + 1;
    }
    
    return size;
}





