/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "SymbolTable.h"

// Function to modify an identifier 
bool SymbolTable::modify(string id, string s, 
                         string t, int l) 
{ 
    int index = hashf(id); 
    Node* start = head[index]; 
  
    if (start == NULL) 
        return "-1"; 
  
    while (start != NULL) { 
        if (start->identifier == id) { 
            start->scope = s; 
            start->type = t; 
            start->var_value = l; 
            return true; 
        } 
        start = start->next; 
    } 
  
    return false; // id not found 
} 
  
// Function to delete an identifier 
bool SymbolTable::deleteRecord(string id) 
{ 
    int index = hashf(id); 
    Node* tmp = head[index]; 
    Node* par = head[index]; 
  
    // no identifier is present at that index 
    if (tmp == NULL) { 
        return false; 
    } 
    // only one identifier is present 
    if (tmp->identifier == id && tmp->next == NULL) { 
        tmp->next = NULL; 
        delete tmp; 
        return true; 
    } 
  
    while (tmp->identifier != id && tmp->next != NULL) { 
        par = tmp; 
        tmp = tmp->next; 
    } 
    if (tmp->identifier == id && tmp->next != NULL) { 
        par->next = tmp->next; 
        tmp->next = NULL; 
        delete tmp; 
        return true; 
    } 
  
    // delete at the end 
    else { 
        par->next = NULL; 
        tmp->next = NULL; 
        delete tmp; 
        return true; 
    } 
    return false; 
} 
  
// Function to find an identifier 
string SymbolTable::find(string id) 
{ 
    int index = hashf(id); 
    Node* start = head[index]; 
  
    if (start == NULL) 
        return "-1"; 
  
    while (start != NULL) { 
  
        if (start->identifier == id) { 
            //start->print(); 
            return start->scope; 
        } 
  
        start = start->next; 
    } 
  
    return "-1"; // not found 
} 
  
// Function to insert an identifier 
bool SymbolTable::insert(string id, string scope, 
                         string Type, int val) 
{ 
    int index = hashf(id); 
    Node* p = new Node(id, scope, Type, val); 
  
    if (head[index] == NULL) { 
        head[index] = p; 
//        cout << "\n"
//             << id << " inserted"<<endl; 
  
        return true; 
    } 
  
    else { 
        Node* start = head[index]; 
        while (start->next != NULL) 
            start = start->next; 
  
        start->next = p; 
//        cout << "\n"
//             << id << " inserted"<<endl; 
  
        return true; 
    } 
  
    return false; 
} 
  
int SymbolTable::hashf(string id) 
{ 
    int asciiSum = 0; 
  
    for (int i = 0; i < id.length(); i++) { 
        asciiSum = asciiSum + id[i]; 
    } 
  
    return (asciiSum % 100); 
} 

int* SymbolTable::getValue(string id) 
{ 
    int index = hashf(id); 
    Node* start = head[index]; 
  
    if (start == NULL) 
        return NULL; 
  
    while (start != NULL) { 
  
        if (start->identifier == id) { 
            //start->print(); 
            return &start->var_value; 
        } 
  
        start = start->next; 
    } 
  
    return NULL; // not found 
} 








