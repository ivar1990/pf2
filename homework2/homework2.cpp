/*
 * Filename: homework2.cpp
 * Author: Ivar Juarez
 */

/* 
 * File:   main.cpp
 * Author: Ivar
 *
 * Created on September 20, 2019, 3:31 PM
 */

#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include "helper.h"
#include "mystrtok.h"


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int count = 0;
    /*******************Test 1*/
    //tests 1 delimiter 
    char test_string[]= "ls -l -a | wc -c >> myfile";
    char test_set[] = " ";
    
    printf ("Splitting string \"%s\" into tokens:\n",test_string);
    char* pch = nullptr;
    pch = mystrtok (test_string,test_set);
   
    while (pch != nullptr)
    {
        
     printf ("%s\n",pch);
     pch = mystrtok (nullptr, " ");
     count++;
     
    }
    
    cout << "token: " << count << endl;
    
   
    
//    /*******************Test 2*/
    count = 0;
    //test 4 delimiters in the test set
    char test_string2[]= "ls -l -a | wc -c >> myfile";
    char test_set2[] = " -ae";
    
    printf ("Splitting string \"%s\" into tokens:\n",test_string2);
    char* pch2 = nullptr;
    pch2 = mystrtok (test_string2,test_set2);
   
    while (pch2 != nullptr)
    {
     printf ("%s\n",pch2);
     pch2 = mystrtok (nullptr,test_set2);
     count++;
    }
    cout << "token: " << count << endl;
    
    /*******************Test 3*/
    count =0;
    //test 4 delimiters 
    char test_string3[]= "ls -l -a | wc -c >> myfile";
    char test_set3[] = " -al";
    
    printf ("Splitting string \"%s\" into tokens:\n",test_string3);
    char* pch3 = nullptr;
    pch3 = mystrtok (test_string3,test_set3);
   
    while (pch3 != nullptr)
    {
     printf ("%s\n",pch3);
     pch3 = mystrtok (nullptr,  " -al");
     count++;
    }

    cout << "token: " << count << endl;
    
    /*******************Test 3*/
    count =0;
    //test entire string delimiter 
    char test_string4[]= "ls -l -a | wc -c >> myfile";
    char test_set4[] = "ls -l -a | wc -c >> myfile";
    
    printf ("Splitting string \"%s\" into tokens:\n",test_string4);
    char* pch4 = nullptr;
    pch4 = mystrtok (test_string4,test_set4);
    
    while (pch4 != nullptr)
    {
     printf ("%s\n",pch4);
     pch4 = mystrtok (nullptr, "ls -l -a | wc -c >> myfile");
     count++;
    }

    cout << "token: " << count << endl;

    return 0;
}













































































