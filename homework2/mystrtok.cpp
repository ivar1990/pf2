/*
 * Filename: mystrtok.cpp
 * Author: Ivar Juarez
 * Description: Takes a token from a string by finding the token 
 * between two delimiters
 */



#include "mystrtok.h"
#include "helper.h"

char* mystrtok(char *str, const char *delim)
{
    
    //the word between each delimiter and the null character
    static char* token;
    //gets the next character after the delimiter
    //holds the string that was previously entered
    static char* str_tracker_ptr;
    //tracks when the last token is reached and 
    static bool end_of_string = false;


    char* start_of_token_ptr = nullptr;
    char* end_of_token_ptr = nullptr;
                //a delimiter is not found
    // the token is now terminated by the '\0' character
    if (end_of_string == true)
    {
                     //reset variables
                    str = nullptr;
                    str_tracker_ptr = nullptr;
                    token = nullptr;
                    end_of_string =false;
                    return nullptr;
    }

    //continues from the str that was previously entered
    if (str == nullptr)
    {
                    str = str_tracker_ptr;

    }



    //finds the beginning of the word(token)
    start_of_token_ptr = find_first_not_in_the_set(str, delim);

    //There is no more characters in the string 
    if (start_of_token_ptr == nullptr)
    {
                    return nullptr;

    }

    //finds the end of the word(token)
    end_of_token_ptr = find_first_in_the_set(start_of_token_ptr, delim);
    //There are no delimiters in the string 
    if (end_of_token_ptr != nullptr)
    {
        //sets the token to the beginning of the word(token)    
        token = start_of_token_ptr;
        //"cuts" the token from the rest of the string
        *end_of_token_ptr = '\0';
        //saves the next character after the token and delimiter
        str_tracker_ptr = end_of_token_ptr + 1;


    }
    else {

        //reset variables
                                        str = nullptr;
        str_tracker_ptr = nullptr;
        token = nullptr;
        end_of_string = true;
        return start_of_token_ptr;
    }



    return token;

    
}
































































































































