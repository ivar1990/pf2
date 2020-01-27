/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   homework3.cpp
 * Author: ivarm
 *
 * Created on October 4, 2019, 12:47 PM
 */

#include <cstdlib>
#include <iostream>
#include "Token.h"
#include "Expression.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
  //Test Case 1
   Expression expression("(a+123)*(ab-(3+4))");
    expression.display();
    
  //Test Case 2
    Expression expression2("a12 = 1?ab + - a 0123 c (a + 12 3 )*(ab - (3 + 4 ))");
    expression2.display();
    

    return 0;
}




















































































