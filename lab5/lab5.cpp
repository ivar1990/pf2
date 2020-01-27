/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lab5.cpp
 * Author: Ivar
 *
 * Created on September 25, 2019, 8:50 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

void check(const string& s, const string& name);



/*
 * 
 */
int main(int argc, char** argv) {
    
    string s0,s2;
    check(s0,"s0");
    check(s2,"s2");
    if (s0.empty())
    {
        cout << "s0 is empty" << endl;
    }else 
    {
        cout << "s0 is not empty" << endl;
    }
    
    string s1("Hello, World!");
    check(s1,"s1");
    
    s2 = s1;
    check(s1,"s1");
    check(s2,"s2");
    
    s2.push_back('!');
    check(s2,"s2");
    
    s1+= s2;
    check(s1,"s1");
    check(s2,"s2");
    
    s1.insert(13, " ");
    check(s1,"s1");
    
    s0 = s1 + " " + s2;
    check(s0,"s0");

    s0.reserve(50);
    check(s0,"s0");
    
    char c = s0[12];
    s2.append(s2);
    check(s2,"s2");
    
    s2.replace(12,2,"=");
    check(s2,"s2");
    const char* p = s2.c_str();
    cout << "p: " << *p << endl;
    
    if (p == s2)
    {
        cout << "p: " << p << endl;
        cout << "s2: " << s2 << endl;
    } else
    {
        cout << "They are not equal " << endl;
    }

    s0[12] = s2[12];
    check(s0,"s0");
    check(s2,"s2");
    
    s0.clear();
    check(s0,"s0");
    
    s2.clear();
    check(s2,"s2");
    
    cout << "p: " << *p << endl;
    
    return 0;
}


void check(const string& s, const string& name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " size is " << s.size() << "\n";
    cout << name << " length is " << s.length() << "\n";
    cout << name << " capacity is " << s.capacity() << "\n";
    cout << name << " max_size is " << s.max_size() << "\n";
}












