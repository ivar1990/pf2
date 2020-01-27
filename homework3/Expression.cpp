/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Expression.h"
#include <cstdlib>
#include <string>

using namespace std;

 Expression::Expression()
 {
     //set out default values
     original = "";
     valid = false;
     type = ILLEGAL;
     
 }
 
 Expression::Expression(const string& s)
 {
     //set our default values
     original = s;
     type = ILLEGAL;
     
     //splits the string into tokens
     set(s);
 }
    
void Expression::set(const string& s)
{

    // used to build our token
    string s_token = "";
    //loop through the characters in the string
    for (int i =0; i < s.size(); i++)
    {
        //delimiters are mostly non alpha-numeric characters
        //string::npos is a variable in the string class that is used when a character does not match any character in the string
        //checks if the character in the string is a delimiter
        if(delimiters.find_first_of(s[i]) != string::npos)
        {
            
           //since the character does is not a delimiter
            
            //convert character s[i] to a string
            //create a token object
            Token token(string(1,s[i]));
            //display token contents
            token.display();
            
            //insert the token into the tokenized vector
            tokenized.push_back(token);
            
            //checks our token before creating a token object
            if(!s_token.empty())
           {
                //creates a token object
                Token m_token(s_token);
                //display the token's content
                m_token.display();
                //adds our token to the expression class's tokenized vector
                 tokenized.push_back(m_token);
                

            }
            //reset our token string
            s_token = "";
            
            
        }
        
       //checks if the character in the string is a not delimiter
        if(delimiters.find_first_of(s[i]) == string::npos)
        {
            //builds our token by adding a character to our string
          s_token += s[i];
        }
        
    }

    

}
    
void Expression::display() const
{
    //Displays the contents of our expression
    
    cout << "original = " << original << endl;
    
    cout << "tokenized = ";
    //prints out each token
    for (int i =0; i < tokenized.size(); i++)
    {
        cout  <<  tokenized[i].get_token() << "; ";
    }
    cout << endl;
    
    cout << "number of token = " << tokenized.size() << endl;
    
    cout << "postfix = " << endl;
    
    cout << "valid = " << valid << endl;
    
    //prints out the type of expression
    string exp_type ="";
        switch(type)
        {
            case ASSIGNMENT:
                exp_type = "ASSIGNMENT";
                break;
            case ARITHMETIC:
                exp_type = "ARITHMETIC";
                break;
            default:
                exp_type = " ILLEGAL";
                break;
        }
    
    cout << "type = " << exp_type << endl;
    
}
    
string Expression::get_original() const
{
    return original;
}

vector<Token> Expression::get_tokenized() const
{
    return tokenized;
}

char* Expression::find_first_in_the_set(char *str, const char *set)
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

char* Expression::find_first_not_in_the_set(char *str,const char *set)
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

char* Expression::mystrtok(char *str, const char *delim)
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







































































































