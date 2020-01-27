/* 
 * This file contains the interface for the Expression class.
 * The expression class takes a string from and tokenizes 
 * the string into tokens. This class checks to see if the expression
 * is valid, classifies the expression, and evaluates the expression.
 * 
 * File:   Expression.h
 * Author: ivar juarez
 *
 * Created on October 4, 2019, 12:58 PM
 */
#include <bits/stdc++.h> 
#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include "Token.h"
#include "SymbolTable.h"

using namespace std;

enum Exp_type { ASSIGNMENT, ARITHMETIC, ILLEGAL};
enum States { expect_operand, expect_operator, done };

#ifndef EXPRESSION_H
#define EXPRESSION_H
class Expression {
    public:
        vector<string> tokenized_expressions;
        vector<string> missing_semicolon_expressions;
        //constructors
        Expression();
        Expression(const string& s);

        //setters
        void set(const string& s);
        //getters
        string get_original() const;
        vector<Token> get_tokenized() const;
        
        Exp_type get_type() const;
        
        
        bool is_valid() const;
        
        void check_semicolon(string input);
       

        //prints expression
        void display() const;

        //splits each expression separated by a semicolon and the null character
        void tokenize_expressions(string input);
        
        //convert to various notations
        void convert_infix_to_postfix();
        void convert_infix_to_prefix();
        string convert_to_full_parenthesized_expr();
        
        void check_syntax();
        
        //user display messages
        void displayPostfix();
        void displayPostfixError();
        void displayPrefix();
        void displayPrefixError();
        void displayFullExpr();
        void displayTokenized();
        
        void clear();
        
        int precedence(char op);
        int applyOp(int a, int b, char op);
        int evaluate();
        
        bool containsVariables();
        bool substituteVariablesWithValues(SymbolTable st);
        

        //generates our tokens
        static char *find_first_in_the_set(char *str, const char *set);
        static char *find_first_not_in_the_set(char *str,const char *set);
        static char* mystrtok(char *str, const char *delim);

    private:
        //holds the string
        string original;

        //characters used to separate the tokens
        string delimiters = "/*-+%!@#$^&;,()?><=";
        bool valid;
        Exp_type type;

        //token notations
        vector<Token>  tokenized;
        vector<Token> postfix;
        vector<Token> prefix;
        stack<Token> ops;
        stack<string> full_expression;
    
};



#endif /* EXPRESSION_H */































