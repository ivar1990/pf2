/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   homework6.cpp
 * Author: ivar juarez
 *
 * Created on November 16, 2019, 7:15 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "Token.h"
#include "Expression.h"


using namespace std;

/*
 * 
 */


int main(int argc, char** argv) {
    
    char action;//holds the user commands
    bool stop = false;//tracks the users commands
    string input = "";//holds the input from the keyboard
    string tmp_str = "";//holds additional strings added by user. 
    
    Expression expression("(a+123)*(ab-(3+4))");
    expression.display();
    
    
    cout << "=== expression evaluation program starts ===" << endl;
    //run program until user enters q when prompted for an action
    while(action !=  'q')
    {
        
        cout << "input: ";
        getline(cin,input);//gets input from keyboard and assign it to the string
        
        
        do
        {
            cout << "action: ";
            cin.get(action);//gets action commands from keyboard
            cin.ignore();//ignore keyboard input until program ask user for another command or input

            //program changes based on what command the user enters
            switch (action)
            {
                case '=': 
                    //expression.set(input);
                    //expression.convert_infix_expression();
                    //expression.displayPostfix();
                    cout << "value: " << input <<endl;
                    stop = false;///continue receiving action commands
                    break;
                case '>':
                    cout << "value: " << input <<endl;
                    stop = false;///continue receiving action commands
                    break;
                case '<': 
                    cout << "value: " << input <<endl;
                    stop = false;///continue receiving action commands
                    break;
                case 'f': 
                    cout << "value: " << input <<endl;
                    stop = false;///continue receiving action commands
                    break;
                case 'F': 
                    cout << "value: " << input <<endl;
                    stop = false;///continue receiving action commands
                    break;
                case 'c': 
                    stop = true;//stops the loop from receiving action commands
                    tmp_str += input;//combines the string enter by the user
                    cout << "value: " << tmp_str <<endl;
                    break;
                case 'C': 
                    stop = true;//stops the loop from receiving action commands
                    tmp_str += input;//combines the string enter by the user
                    cout << "value: " << tmp_str <<endl;
                    break;
                case 's': 
                    
                    stop = true;//stops the loop from receiving action commands
                    cout << "value: " << input <<endl;
                    tmp_str = "";//clears previously entered user inputs
                    break;
                case 'S': 
                    stop = true;//stops the loop from receiving action commands
                    cout << "value: " << input <<endl;
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
            
        } while(stop != true);
        
    }
    
    cout << "=== expression evaluation program ends ===" << endl;

    return 0;
}


















































