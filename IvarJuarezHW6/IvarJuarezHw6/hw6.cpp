/*
 * This file contains the main program that the user will interact with.
 * It takes an input from the user that specifies a mathematical expression.
 * this program classifies and evaluates the expression.
 * 
 * After the program has read in a sequence of expressions, the user may specify
 *the following actions: =, >, <, f, q, c, s.
 *
 * The meaning of each action is as follows.
 *• = : evaluate each expression in the sequence of expressions.
 *• > : convert each expression in the sequence of expressions to the equivalent
 *prefix expression.
 *• < : convert each expression in the sequence of expressions to the equivalent
 *postfix expression.
 *• f : convert each expression in the sequence of expressions to the equivalent
 *fully parenthesized expression.
 *• q : quit the program.
 *• c : continue inputting a sequence of expressions (the current sequence
 *appends to the the previous sequence)
 *• s : start over for a new sequence of expressions.
 *Unless the actions are q, or c, or s, the program remains in the state of
 *taking user action.
 */

/* 
 * File:   hw6.h
 * Author: ivar juarez
 *
 * 
 */
#include <cstdlib>
#include <iostream>
#include <string>

#include "Token.h"
#include "Expression.h"
#include "SymbolTable.h"


using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    
    char action;//holds the user commands
    bool stop = false;//tracks the users commands
    string input = "";//holds the input from the keyboard
    string tmp_str = "";//holds additional strings added by user. 
    
   Expression expression;
   vector<Expression> wait_list_expressions;
   SymbolTable symbol_table;

    
    cout << "=== expression evaluation program starts ===" << endl;
    //run program until user enters q when prompted for an action
    while(action !=  'q')
    {
        
        cout << "input: ";
        getline(cin,input);//gets input from keyboard and assign it to the string
        
         input+=tmp_str;
         

       // cout<< input << endl;
        do
        {
            cout << "action: ";
            cin.get(action);//gets action commands from keyboard
            cin.ignore();//ignore keyboard input until program ask user for another command or input
            
           
            if(expression.get_tokenized().empty())
                    {
                        expression.set(input);
                    }
            expression.tokenize_expressions(input);
            
            //expression.check_semicolon(input);
            
            //program changes based on what command the user enters
            switch (action)
            {
                case '=': 
                    
                    for(int i=0; i<expression.tokenized_expressions.size();i++)
                    {
                        Expression exp(expression.tokenized_expressions[i]);
                        exp.check_syntax();
                        if(exp.is_valid())
                        {
                            if(exp.get_type() == ARITHMETIC )
                            {
                                if(exp.containsVariables())
                                {
                                    //places the arithmetic expression in the last element
                                    //this is done so that the expression is always evaluated last
                                    wait_list_expressions.push_back(exp);
                                   
                                }
                                else
                                {
                                    int result = exp.evaluate();
                                    cout << exp.get_original() << " = " << result << endl;
                                }
                            }
                            
                            if(exp.get_type() == ASSIGNMENT)
                            {
                                if(symbol_table.find(exp.get_tokenized().at(0).get_token())=="local")
                                {
                                    symbol_table.modify(exp.get_tokenized().at(0).get_token(), "local", "variable", exp.get_tokenized().at(2).value());
                                }
                                else
                                {
                                    symbol_table.insert(exp.get_tokenized().at(0).get_token(), "local", "variable", exp.get_tokenized().at(2).value());
                                }
                                cout << "cannot evaluate " << exp.get_original() << " which is not an arithmetic expression, but assignment." <<endl;
                            }
                            
                           
                        } else
                        {
                            cout << "cannot evaluate " << exp.get_original() << " which is an invalid expression." <<endl;
                        }
                        exp.clear();
                        
                         if(i == expression.tokenized_expressions.size()-1)
                           {
                             for(int j=0; j<wait_list_expressions.size();j++)
                                {
                                         if(wait_list_expressions[j].substituteVariablesWithValues(symbol_table))
                                        {
                                            int result = wait_list_expressions[j].evaluate();
                                            cout  << wait_list_expressions[j].get_original() << " = " << result << endl;
                                        }
                                        else
                                        {
                                            cout  <<wait_list_expressions[j].get_original() << " no result, some variables have undefined value.  "  << endl;
                                        }
                             }
                         }
                       
                    }
                    wait_list_expressions.clear();
                    stop = false;///continue receiving action commands
                    break;
                case '>':
                               
                    for(int i=0; i<expression.tokenized_expressions.size();i++)
                    {
                        Expression exp(expression.tokenized_expressions[i]);
                        exp.check_syntax();
                        if(exp.is_valid())
                        {
                            if(exp.get_type() == ASSIGNMENT)
                            {
                                cout << "no prefix of " << exp.get_original() << " which is not an aritmetic expression, but assignment." << endl;
                            }
                            
                            if(exp.get_type() == ARITHMETIC )
                            {
                                exp.convert_infix_to_prefix();
                                exp.displayPrefix();
                            }
                        } else
                        {
                            exp.displayPrefixError();
                           
                        }
                        exp.clear();
                    }
                    
                    
                    stop = false;///continue receiving action commands
                    break;
                case '<': 
                   
                     
                    for(int i=0; i<expression.tokenized_expressions.size();i++)
                    {
                        Expression exp(expression.tokenized_expressions[i]);
                        exp.check_syntax();
                        if(exp.is_valid())
                        {
                             if(exp.get_type() == ASSIGNMENT)
                            {
                                cout << "no postfix of "<< exp.get_original() << " which is not an aritmetic expression, but assignment." << endl;
                            }
                            
                            if(exp.get_type() == ARITHMETIC )
                            {
                                exp.convert_infix_to_postfix();
                                exp.displayPostfix();
                            }
                            
                        } else
                        {
                            exp.displayPostfixError();
                            
                        }
                        exp.clear();
                    }
                    
                    stop = false;///continue receiving action commands
                    break;
                case 'f': 
                   
                     
                    for(int i=0; i<expression.tokenized_expressions.size();i++)
                    {
                        Expression exp(expression.tokenized_expressions[i]);
                        exp.check_syntax();
                        if(exp.is_valid())
                        {
                            if(exp.get_type() == ASSIGNMENT)
                            {
                                cout << "no fully parenthesizing of "<< exp.get_original() << " which is not an aritmetic expression, but assignment." << endl;
                            }
                            
                            if(exp.get_type() == ARITHMETIC )
                            {
                                exp.convert_infix_to_postfix();
                                exp.displayFullExpr();
                            }
                            
                        } else
                        {
                            exp.displayFullExpr();
                            
                        }
                        exp.clear();
                    }
                     
                    
                    
                    stop = false;///continue receiving action commands
                    break;
                case 'F': 
                    
                     for(int i=0; i<expression.tokenized_expressions.size();i++)
                    {
                        Expression exp(expression.tokenized_expressions[i]);
                        exp.check_syntax();
                        if(exp.is_valid())
                        {
                            if(exp.get_type() == ASSIGNMENT)
                            {
                                cout << "no fully parenthesizing of "<< exp.get_original() << " which is not an aritmetic expression, but assignment." << endl;
                            }
                            
                            if(exp.get_type() == ARITHMETIC )
                            {
                                exp.convert_infix_to_postfix();
                                exp.displayFullExpr();
                            }
                            
                        } else
                        {
                            exp.displayFullExpr();
                            
                        }
                        exp.clear();
                    }
                    
                    stop = false;///continue receiving action commands
                    break;
                case 'c': 
                    stop = true;//stops the loop from receiving action commands
                    tmp_str = input;//combines the string enter by the user
                    //cout << tmp_str << endl;
                    
                    expression.clear();
                    break;
                case 'C': 
                    stop = true;//stops the loop from receiving action commands
                    tmp_str = input;//combines the string enter by the user
                   // cout << tmp_str << endl;
                  
                   expression.clear();
                    break;
                case 's': 
                    expression.clear();
                    stop = true;//stops the loop from receiving action commands
                    tmp_str = "";//clears previously entered user inputs
                    break;
                case 'S': 
                    expression.clear();
                    stop = true;//stops the loop from receiving action commands
                    tmp_str = "";//clears previously entered user inputs
                    break;
                case 'q': 
                    stop = true;//stops loop
                    break;
               case 'Q': 
                    stop = true;//stops loop
                    break;
                default:
                    
                    cout << "Wrong input for the action! Please type one of =, <, >, f(F), q(Q), c(C), s(S)" << endl;
            }
            expression.clear();
            
        } while(stop != true);
        
    }
    
    cout << "=== expression evaluation program ends ===" << endl;

    return 0;
}














































































































