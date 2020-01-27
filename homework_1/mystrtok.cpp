/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>
#include "mystrtok.h"
#include "helper.h"

char* mystrtok(char *str, const char *delim)
{
    static char* last_delimiter_ptr;
    
    if (str != nullptr )
    {
        last_delimiter_ptr = str;
        
    }
    
    for(int i = 0; str[i]!= '\0'; i++)
    {
        last_delimiter_ptr = find_first_in_the_set(str, delim[i]);
        std::cout << "delimiter ptr: " << str[i] << std::endl;
    }
    
    return nullptr;
}












