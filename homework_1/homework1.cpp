/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Ivar Juarez
 * This program test for a character within a given string and compares it with a character within a given set.
 *if the characters match,the previous and next characters within the givern string is outputed.
 *if the character in the set does not match a character in the given string, the first character that does not match is outputed.
 *if a character in the set does not match any character in the given string, the program will crash and output a segmentation fault. 
 
 * Created on September 6, 2019, 10:35 PM
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "helper.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
char test_string[15];
char test_set[10];
char *p; // pointer to the return character
strcpy(test_string, "Hi Everyone!");
strcpy(test_set, "e");
p = find_first_in_the_set(test_string, test_set);
cout << *p << endl;
// the above output should e and *(p-1) is v and *(p+1) is r
cout << *(p-1) << endl;
cout << *(p+1) << endl;
p = find_first_not_in_the_set(test_string, test_set);
cout << *p << endl; // the output should be H

//char test_string[15];
//char test_set[10];
//char *p; // pointer to the return character
//strcpy(test_string, "Good Afternoon");
//strcpy(test_set, "t");
//p = find_first_in_the_set(test_string, test_set);
//cout << *p << endl;
//// the above output should t and *(p-1) is t and *(p+1) is e
//cout << *(p-1) << endl;
//cout << *(p+1) << endl;
//p = find_first_not_in_the_set(test_string, test_set);
//cout << *p << endl; // the output should be H
//
//char test_string[15];
//char test_set[10];
//char *p; // pointer to the return character
//strcpy(test_string, "Hi Everyone!");
//strcpy(test_set, "x");
//p = find_first_in_the_set(test_string, test_set);
//cout << *p << endl;
//// the above output should crash the program and output a segmentation fault

    return 0;
}

