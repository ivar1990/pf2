

/* 
 * File:   homework4.cpp
 * Author: Ivar Juarez
 *
 * Created on October 22, 2019, 8:22 AM
 */


#include <cstdlib>
#include <iostream>
#include <string>
#include "Mystring.h"

#define string Mystring

using namespace std;

/*
 * 
 */
void check (const string s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}

int main(int argc, char** argv) {
    
    cout << "This is Homework 4" << endl;
    string s1 = "Hello, World!";
    string s1name("s1");
    
    check(s1, s1name);
    check(s1, s1name);
    
    cout << "---Test Case 1: assignment operator---\n\n" << endl;
    {
        string s2;
        s2=s1;
        string s2name("s2");
        check(s2, s2name);
    }
    
    check(s1,s1name);
    
    cout << "---Test Case 2: += operator---\n\n" << endl;
    {
        string s3 = "testing ";
        string s32 ="new string";
        check(s3, "s3");
        check(s32, s32);
        s3+=s1;
        s3+=s32;
        string s3name("s3");
        check(s3, s3name);
    }
    
    cout << "---Test Case 3: + operator---\n\n" << endl;
    {
        string s3 = "testing ";
        string s32 ="new string";
        string s4 = s3 + s32;
        
        check(s3, "s3");
        check(s32, s32);
        check(s4, "s4");
    }
    
    cout << "---Test Case 4: find first of function---\n\n" << endl;
    {
        string s5 = "testing hello world!";
        cout << s5.find_first_of("ow", 2,3) << endl;
    }
    
    cout << "---Test Case 5: find last not of function---\n\n" << endl;
    {
        string s6 = "testing hello world!";
        cout << s6.find_last_not_of("testing hello world!",19) << endl;
    }
    
    cout << "---Test Case 6: boolean == operator---\n\n" << endl;
    {
        string s7 = "testing hello world!";
        string s8 = "testing hello world!";
        check(s7,"s7");
        check(s8,"s8");
        if (s7==s8)
        {
            cout << "matched" << endl;
        }
        else
        {
            cout << "not matched." << endl;
        }
        
        if (s7=="testing hello world!")
        {
            cout << "matched" << endl;
        }
        else
        {
            cout << "not matched." << endl;
        }
        
    }
    
    cout << "---Test Case 7: boolean != operator---\n\n" << endl;
    {
        string s9 = "testing hello world!";
        string s10 = "a different test!";
        check(s9,"s9");
        check(s10,"s10");
        if (s9!=s10)
        {
            cout << "not matched" << endl;
        }
        else
        {
            cout << "matched." << endl;
        }
        
        if (s9!="a different test!")
        {
            cout << "not matched" << endl;
        }
        else
        {
            cout << "matched." << endl;
        }
        
    }
    
    cout << "---Test Case 8: insert function---\n\n" << endl;
    {
        string s11 = "hello world!";
        string s12 = "the ";
        
        check(s11,"s11");
        s11.insert(6,"the ");
 
        cout << "s11: " << s11 << endl;
        check(s11,"s11");
        
    }
    
    cout << "---Test Case 9: replace function(string object version)---\n\n" << endl;
    {
        string s13 = "hello world!";
        string s14 = "the";
        check(s13,"s13");
        s13.replace(6,2,s14);
 
        cout << "s13: " << s13 << endl;
        check(s13,"s13");
        
    }
    
    cout << "---Test Case 10: replace function(c-string version)---\n\n" << endl;
    {
        string s15 = "hello world!";
        check(s15,"s15");
        s15.replace(6,2,"the");
 
        cout << "s15: " << s15 << endl;
        check(s15,"s15");
        
    }
    
    cout << "---Test Case 11: clear function---\n\n" << endl;
    {
        string s16 = "hello world!";
        check(s16,"s16");
        s16.clear();
 
        cout << "s16: " << s16 << endl;
        check(s16,"s16");
        
    }
    
    cout << "---Test Case 12: empty function---\n\n" << endl;
    {
        string s17 = "hello world!";
        check(s17,"s17");
        if(s17.empty())
        {
            cout << "s17 is empty " << endl;
        }
        else
        {
            cout << "s17 is not empty " << endl;
        }
        
        s17.clear();
        
        if(s17.empty())
        {
            cout << "s17 is empty " << endl;
        }
        else
        {
            cout << "s17 is not empty " << endl;
        }
 
        check(s17,"s17");
        
        
    }
    
    cout << "---Test Case 13: operator[]---\n\n" << endl;
    {
        
        string str ("Test string");
        for (int i=0; i<str.length(); i++)
        {
            cout << str[i] << endl;
        }
 
        
        
        
    }
    
    cout << "---Test Case 14: reserve function---\n\n" << endl;
    {
        
        string str27 ("Teststring");
        check(str27,"str27");
        str27.reserve(5);
        check(str27,"str27");
 
        
        
        
    }
    
    
    
    cout << "Homework 4 ends" << endl;

    return 0;
}




























































































































