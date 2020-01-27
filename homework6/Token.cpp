/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Token.h"
#include "Expression.h"
#include <iostream>
#include <string>
using namespace std;

    Token::Token()
    {
        //set our defaults
        type = INVALID;
        token = "";
        priority = -1;
    }

    Token::Token( string s)
    {
        //determines the type of token 
        set(s);
        
        //not in use
        priority = -1;
    }


    
    void Token::set(string s )
    { 
        //set the default type
        type = INVALID;
        token = s;
        priority = -1;
        
        //checks if the token is an identifier based on description
        if(is_identifier(s))
        {
            type = ID;
        }
        
        try {
            //try to convert the token string to an int
            //if it fails the catch statement will cause the program to continue
            //checks if the token does not start with zero
            //checks if the is no delimiter in the token string
            if(stoi(s) > 0 && s[0]!= '0' && Expression::find_first_in_the_set(&s[0], &delimiters[0])==nullptr)
            {
                type = INT;
            }
        } 
        catch(exception e)
        {
            //type = INVALID;
        }
        
        //sets the token to an operator
        if (s=="+" || s == "/" )
        {
            type= OP;
            priority = 1;
            
        }
        
        if ( s == "/" || s=="*")
        {
            type= OP;
            priority = 2;
            
        }
        
        //token is the assignment operator
        if(s=="=")
        {
            type = EQ;
        }
        
        //token is open brace
        if(s=="(")
        {
            type = OpenBrace;
            priority = 0;
        }
        
        //token is close brace
        if(s==")")
        {
            type = CloseBrace;
        }
        
        
        
    }
    
    int Token::value() const
    {
        //converts or string to int
        if(type == INT)
        {
            return stoi(token);
        }
        
        //returns -1 based on homework description
        if (type == ID)
        {
            return -1;
        }
        
        return -2;
    }
    
    void Token::display() const
    {
        //prints out the type of token
        string token_type ="";
        switch(type)
        {
            case INT:
                token_type = "INT";
                break;
            case ID:
                token_type = "ID";
                break;
            case OP:
                token_type = "OP";
                break;
            case OpenBrace:
                token_type = "OpenBrace";
                break;
            case CloseBrace:
                token_type = "CloseBrace";
                break;
            case  EQ:
                token_type = "EQ";
                break;
            default:
                token_type = "INVALID";
                break;
        }
        cout << "type = " << token_type << endl;
        cout << "token = " << get_token() << "  (value is " << value() << ")" << endl;
        cout << "priority = " << priority << endl;
    }
    
    Token_type Token::get_type() const
    {
        return type;
    }
    
    string Token::get_token() const
    {
        return  token;
    }
    
    
    int Token::get_priority() const
    {
        return priority;
    }
    
    bool Token::is_identifier(string s)
    {
        bool is_valid = true;
        
        //checks to see if any of the special characters are in the string
        if(Expression::find_first_in_the_set(&s[0],&delimiters[0])!= nullptr)
        {
            is_valid = false;
        }
        
        //checks if the token starts with zero
        if(s[0]=='0')
        {
            is_valid == false;
        }
        
        //checks if the token is the null terminator
        if(s[0]=='\0')
        {
            is_valid == false;
        }
        
        //checks if the string is not empty
        if(s.empty())
        {
            is_valid == false;
        }
        
        return is_valid ;
        
    }






















































