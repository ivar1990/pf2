/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Expression.h
 * Author: ivarm
 *
 * Created on October 4, 2019, 1:07 PM
 */

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include "Token.h"

using namespace std;

enum Exp_type { ASSIGNMENT, ARITHMETIC, ILLEGAL};
enum States { expect_operand, expect_operator, done };

#ifndef EXPRESSION_H
#define EXPRESSION_H
class Expression {
    public:

        //constructors
        Expression();
        Expression(const string& s);

        //setters
        void set(const string& s);
        //getters
        string get_original() const;
        vector<Token> get_tokenized() const;

        //prints expression
        void display() const;

        //
        void convert_infix_expression();
        void check_syntax();
        void displayPostfix();

        //generates our tokens
        static char *find_first_in_the_set(char *str, const char *set);
        static char *find_first_not_in_the_set(char *str,const char *set);
        static char* mystrtok(char *str, const char *delim);

    private:
        //holds the string
        string original;

        //characters used to separate the tokens
        string delimiters = "/*-+%!@#$^&();,?><=";
        bool valid;
        Exp_type type;

        vector<Token>  tokenized;
        vector<Token> postfix;
        stack<Token> ops;
    
};



#endif /* EXPRESSION_H */


