/* 
 * This file contains the interface for the Token class.
 * The token class takes each substring from the expression
 * and classifies them accordingly.
 * 
 * File:   Token.h
 * Author: ivar juarez
 *
 * Created on October 4, 2019, 12:58 PM
 */


#ifndef TOKEN_H
#define TOKEN_H


#include <iostream>
#include <string>


using namespace std;

enum Token_type {ID, INT, OP, EQ, OpenBrace, CloseBrace, INVALID};


class Token {
    
    public:
    //constructors
    Token();
    Token(string s);
    
    //setters
    void set(string s);
    void set_type(Token_type token_type) { type = token_type; }
    
    //getters
    Token_type get_type() const;
    string get_token() const;
    int get_priority() const;
    int value() const;
    
    //prints the token
    void display() const;
    
    
    //checks our string for valid tokens
    bool is_identifier(string s);
    
    
    
    
private:
    Token_type  type;
    
    string token;
    
    //determines the type of the token
    string delimiters = "/*-+%!@#$^&();,?><.= ";
    
    int priority;
    
};


#endif /* TOKEN_H */









