/* 
 * File:   helper.h
 * Author: Ivar Juarez
 *
 * Created on September 6, 2019, 10:53 PM
 */
#include "helper.h"
#include <iostream>
char *find_first_in_the_set(char *str, const char *set)
{
    //traverses the char array of our string
    for(int str_index = 0;str[str_index] != '\0';str_index++)
    {
        //traverses the char array of the set
        for(int set_index = 0; set[set_index] != '\0'; set_index++)
        {
            //checks if the current char of our string array matches with the current char 
            //of the set char array
            if(set[set_index] == str[str_index]){
                return &str[str_index];
            }
        }
        
    }
    // if no character matches 
    return nullptr;
}

char *find_first_not_in_the_set(char *str, const char *set)
{    
    bool not_found;
    for (int i = 0; str[i] != '\0'; i++){
        // check to see if str[i] is in set or not
        // if after the loop not_found is true
        // then str[i] is not in set
        not_found = true;
        for (int k = 0; set[k] != '\0'; k++)
            if (str[i] == set[k]) // str[i] in set
                not_found = false; // str[i] is not the one not in set
        if (not_found)
            return &str[i]; //str[i] is the first character not in set
    }
    // each character in str is in set
    return NULL;
}













