/*
 * This file contains the interface of the Symbol table and its corresponding data structure.
 * This class will store the variables in the assignment expression.
 * It provides methods to search, modify and delete variables.
 */

/* 
 * File:   SymbolTable.h
 * Author: ivar juarez
 *
 * Created on December 4, 2019, 11:23 PM
 */

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream> 
#include <string>
using namespace std; 
  
const int MAX = 100; 
  
class Node { 
  
    string identifier, scope, type; 
    int var_value; 
    Node* next; 
  
public: 
    Node() 
    { 
        next = NULL; 
    } 
  
    Node(string key, string value, string type, int val) 
    { 
        this->identifier = key; 
        this->scope = value; 
        this->type = type; 
        this->var_value = val; 
        next = NULL; 
    } 
  
    void print() 
    { 
        cout << "Identifier's Name:" << identifier 
             << "\nType:" << type 
             << "\nScope: " << scope 
             << "\nValue: " << var_value << endl; 
    } 
    friend class SymbolTable; 
}; 
  
class SymbolTable { 
    Node* head[MAX]; 
  
public: 
    SymbolTable() 
    { 
        for (int i = 0; i < MAX; i++) 
            head[i] = NULL; 
    } 
  
    int hashf(string id); // hash function 
    bool insert(string id, string scope, 
                string Type, int val); 
  
    string find(string id); 
  
    bool deleteRecord(string id); 
  
    bool modify(string id, string scope, 
                string Type, int val); 
    
    int* getValue(string id);
}; 

#endif /* SYMBOLTABLE_H */






