/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab12.cpp
 * Author: ivar juarez
 *
 * Created on November 20, 2019, 9:01 AM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
struct Node 
{ 
    int data; 
    Node* left; 
    Node* right; 
} ;

Node* search(Node* t, int key, Node * & parent); 

Node* insert(Node* t, int key);

void inorder (Node* t);
void postorder (Node* t);

int main(int argc, char** argv) {

    Node* tree = NULL;// an empty tree   
     tree=insert(tree, 20);
     insert(tree,30);
     insert(tree,10);
     insert(tree,40);
     insert(tree,8);
     insert(tree,4);
     insert(tree,9);
     insert(tree,18);
     insert(tree,16);
     insert(tree,38);
     insert(tree,32);
     insert(tree,39);
     inorder(tree);
     cout << endl;
     postorder(tree);
    
    return 0;
}

Node* search(Node* t, int key, Node * & parent)
{
   // The given key is
    // not found in BST
    if (t == NULL)
        return NULL;
    // The given key is found
    else if(t->data == key)
        return t;
    // The given is greater than
    // current node's key
    else if( key > t->data )
    {
        parent = t;
        search(t->right, key, parent);
    }
    // The given is smaller than
    // current node's key
    else if( key < t->data )
    {
        parent = t;
        search(t->left, key, parent);
    }
}

Node* insert(Node* t, int key)
{
    Node *parent;
    Node *found_node;
    found_node = search(t,key,parent);
    if (t == NULL)
    {
        //if the tree is empty
        found_node = new Node;
        found_node->data = key; 
        found_node->left = NULL;
        found_node->right = NULL;
        t=found_node;
        
    }
    if (found_node == NULL)
    {
        //adds a node to the left
       if (key < parent->data)
        {
            parent->left=new Node;
            parent->left->data = key; 
            parent->left->left = NULL;
            parent->left->right = NULL;

        }
       
       //adds a node to the right
        if (key > parent->data)
        {

           parent->right=new Node;
            parent->right->data = key; 
            parent->right->left = NULL;
            parent->right->right = NULL;

        }
        
    }
    //else
     //cout << "duplicate key\n";
    
    return t;

}

void inorder (Node* t){
    //reads the tree in ascending order
    if (t != NULL){
     inorder(t->left);
     cout << t->data << " ";
     inorder(t->right);
     
    }
}

void postorder (Node* t){
    if (t != NULL){
     postorder(t->left);
     postorder(t->right);
     cout << t->data << " ";
    }
}









































