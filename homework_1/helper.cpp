/* 
 * File:   helper.h
 * Author: Ivar Juarez
 *
 * Created on September 6, 2019, 10:53 PM
 */
#include "helper.h"

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
    //traverses the char array of our string
    for(int set_index = 0;set[set_index] != '\0';set_index++)
    {
        //traverses the char array of the set
        for(int str_index = 0; str[str_index] != '\0'; str_index++)
        {
            //checks if the current char of our string array does not match with the current char 
            //of the set char array
            if(set[set_index] != str[str_index]){
                
                return &str[str_index];
            }
        }
        
    }
    //if 
    return nullptr;
}

