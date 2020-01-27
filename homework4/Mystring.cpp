/*
 * File:   Mystring.cpp
 * Author: Ivar Juarez
 *
 * Mystring class that mimics the C++ string class in the standard library
 * Below is the implementations of the class Mystring
 * 2019
 */
#include "Mystring.h"

// default constructor
Mystring::Mystring() 
{
    ptr_buffer  = new char[1];
    *ptr_buffer = '\0';
    buf_size    = 1;
    len         = 0;
}

// constructor from c-style string or "abc"
Mystring::Mystring(const char * s) 
{
    len        = strlen(s);
    buf_size   = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);

}


// copy constructor
Mystring::Mystring(const Mystring& orig) 
{
    len = strlen(orig.ptr_buffer);
    ptr_buffer = new char[len + 1];
    buf_size = len +1;
    
    strcpy(ptr_buffer, orig.ptr_buffer);
    

}


// some simple methods implemented for you
//properties
 Mystring::size_type Mystring::size() const 
 {
     return len;
 }
 
 Mystring::size_type Mystring::length() const
 {
     return len;
 }
 
 Mystring::size_type Mystring::capacity() const
 {
       return buf_size;
 }
 
 Mystring::size_type Mystring::max_size() const
 {
       return (int)pow(2,30) -4 ;
 }
 
 void Mystring::reserve(size_type n)
 {
     char* concat_str = new char[buf_size];
          
        strcpy(concat_str, ptr_buffer);
        
        delete [] ptr_buffer;
        
        len = n;
        buf_size = len +1;
        ptr_buffer = new char[buf_size];
        
        for(int i =0; i<n; i++)
        {
            ptr_buffer[i] = concat_str[i];
        }
        
        delete[] concat_str;
 }
 
 //Searches the string for the first character that matches any of the characters specified in its arguments.
//When pos is specified, 
 //the search only includes characters at or after position pos, ignoring any possible occurrences before pos.
  Mystring::size_type Mystring::find_first_of (const char* s, size_type pos, size_type n) const
  {
      if(pos > strlen(s))
      {
           return 0;
      }
      
      for(int  i = pos; i <= len;i++)
      {
          for(int j=0; j<n && s[j]!='\0' ; j++)
          {
                if(s[j]==ptr_buffer[i])
                 {
                    return i;
                }
          }
      }
      
      return npos;
  }

    // c-string (2)
  /*
   * Find non-matching character in string from the end
Searches the string for the last character that does not match any of the characters specified in its arguments.

When pos is specified, the search only includes characters at or before position pos, ignoring any possible occurrences after pos.
   */
    Mystring::size_type Mystring::find_last_not_of (const char* s, size_type pos) const
    {
        bool is_in_set = false;
       unsigned int index_of_unmatched_char = npos;
        for(int i=0; i < pos && i <= len; i++)
        {
            for(int j=0; j <= len; j++)
            {
                if(s[j]==ptr_buffer[i])
                {
                    is_in_set = true;
                }
            }
            
            if(is_in_set == false)
            {
                index_of_unmatched_char = i;
            }
            
            is_in_set = false;
        }
        return index_of_unmatched_char;
    }
    
    /***
     Find non-matching character in string from the end
Searches the string for the last character that does not match any of the characters specified in its arguments.

When pos is specified, the search only includes characters at or before position pos, ignoring any possible occurrences after pos.
     */
     Mystring::size_type Mystring::find_last_not_of (const Mystring& s, size_type pos) const
    {
        bool is_in_set = false;
       unsigned int index_of_unmatched_char = npos;
        for(int i=0; i < pos && i< len; i++)
        {
            for(int j=0; j < len; j++)
            {
                if(s.ptr_buffer[j]==ptr_buffer[i])
                {
                    is_in_set = true;
                }
            }
            
            if(is_in_set == false)
            {
                index_of_unmatched_char = i;
            }
            
            is_in_set = false;
        }
        return index_of_unmatched_char;
    }
     
     //allows the class to access it data using array notation
     char Mystring::operator[](size_type pos) const
     {
          if (pos >= buf_size) 
            { 
                cout << "Array index out of bound, exiting"; 
                exit(0); 
            } 
            return ptr_buffer[pos]; 
     }
     
     ////allows the class to access it data using array notation
     char& Mystring::operator[](size_type pos) 
     {
          if (pos >= buf_size) 
            { 
                cout << "Array index out of bound, exiting"; 
                exit(0); 
            } 
            return ptr_buffer[pos]; 
     }
    
     //assign a string to another string
    Mystring& Mystring::operator=(const Mystring& orig)
{
   delete [] ptr_buffer;
   len = strlen(orig.ptr_buffer);
    ptr_buffer = new char[len + 1];
    buf_size = len +1;
    
    strcpy(ptr_buffer, orig.ptr_buffer);
    return *this;
}

     //assign a string to another string
Mystring& Mystring::operator=(const char *p_char)
{
    delete [] ptr_buffer;
   len = strlen(p_char);
    ptr_buffer = new char[len + 1];
    buf_size = len +1;
    
    strcpy(ptr_buffer, p_char);
    return *this;
}
    
//concatenate string together
    Mystring& Mystring::operator+=(const Mystring& str)
    {
        char* concat_str = new char[buf_size];
        strcpy(concat_str, ptr_buffer);
        
        delete [] ptr_buffer;
        
        len += strlen(str.ptr_buffer);
        buf_size = len +1;
        ptr_buffer = new char[buf_size];
        
        
        strcpy(ptr_buffer,concat_str);
        strcat(ptr_buffer, str.ptr_buffer);
        
        delete[] concat_str;
        
        return *this;
    }
    
    //concatenate string together
    Mystring& Mystring::operator+=(const char * str)
    {
        char* concat_str = new char[buf_size];
        strcpy(concat_str, ptr_buffer);
        
        delete [] ptr_buffer;
        
        len += strlen(str);
        buf_size = len +1;
        ptr_buffer = new char[buf_size];
        
        
        strcpy(ptr_buffer,concat_str);
        strcat(ptr_buffer, str);
        
        delete[] concat_str;
        
        return *this;
    }
    
    //concatenate string together
    Mystring operator+(const Mystring& lhs, const Mystring& rhs)
    {
        //uses the += operator that was implemented
        Mystring concat_str = lhs;
        concat_str += rhs;
        

        return concat_str;
    }
    
    //checks to see if one string contains the characters of another string
    bool operator==(const Mystring&lhs, const Mystring& rhs)
    {
        //if all matching characters are found 
        // the npos variable will only be return if there a character that is not in the string array of the second string
        if(lhs.find_last_not_of(rhs,rhs.length())==lhs.npos)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    
    //c-string version
    bool operator==(const char* s, const Mystring& rhs)
    {
        if(rhs.find_last_not_of(s,strlen(s))==rhs.npos)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    
    //combination of c-string and c++-string
     bool operator==(const Mystring& rhs, const char* s)
    {
        if(rhs.find_last_not_of(s,strlen(s))==rhs.npos)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    
     //checks if two strings do not match
    bool operator!=(const Mystring& lhs, const Mystring& rhs)
    {
        if(!(lhs==rhs))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    //checks if a c-string and ac++ string contains both characters
    bool operator!=(const char* s, const Mystring& rhs)
    {
        if(!(s==rhs))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
     bool operator!=(const Mystring& lhs, const char* s)
    {
        if(!(s==lhs))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
   
    //adds to a single character to the string 
    void Mystring::push_back(char c)
    {
        char* concat_str = new char[buf_size+1];
        strcpy(concat_str, ptr_buffer);
        
        delete [] ptr_buffer;
        
        buf_size = len +1;
        ptr_buffer = new char[buf_size];
              
        strcpy(ptr_buffer,concat_str);
        ptr_buffer[len]= c;
        
        
        delete[] concat_str;
        
        
    }
    
    //adds a string to another string
    Mystring& Mystring::append(const Mystring& str)
    {
        return *this += str;
    }
    
    //adds a c-string to the string arra
    Mystring& Mystring::append(const char * str)
    {
        return *this += str;
    }
 
    //inserts a string at the specified
 Mystring& Mystring::insert(size_type pos, const Mystring& str)
 {
     if(pos < len)
     {
         int current_index =0;
         
         //holds the content of the original string
          char* concat_str = new char[buf_size];
          
        strcpy(concat_str, ptr_buffer);
        
        //clears the contents in the buffer
        delete [] ptr_buffer;
        //resizes the buffer
        len += strlen(str.ptr_buffer);
        buf_size = len +1;
        ptr_buffer = new char[buf_size];
        
        //copies the first portion of the original string
        for(int i =0; i<pos; i++, current_index++)
        {
            ptr_buffer[i] = concat_str[i];
        }
              
        //copies the contents of str
        for(int j=0;str.ptr_buffer[j]!='\0';j++,current_index++)
        {
            ptr_buffer[current_index]=str.ptr_buffer[j];
        }
        
        //copies the last portion of the string
        for(int k=pos; concat_str[k]!='\0';k++,current_index++)
        {
             ptr_buffer[current_index] = concat_str[k];
        }
        
        
        delete[] concat_str;
     }
     else
     {
         cout << "out of range" << endl;
     }
     return *this;
 }
 
 //adds a c-string to the characters
 Mystring& Mystring::insert(size_type pos, const char * str)
 {
     if(pos < len)
     {
         int current_index =0;
          char* concat_str = new char[buf_size];
          
        strcpy(concat_str, ptr_buffer);
        
        delete [] ptr_buffer;
        
        len += strlen(str);
        buf_size = len +1;
        ptr_buffer = new char[buf_size];
        
        for(int i =0; i<pos; i++, current_index++)
        {
            ptr_buffer[i] = concat_str[i];
        }
              
        for(int j=0;str[j]!='\0';j++,current_index++)
        {
            ptr_buffer[current_index]=str[j];
        }
        
        for(int k=pos; concat_str[k]!='\0';k++,current_index++)
        {
             ptr_buffer[current_index] = concat_str[k];
        }
        
        
        delete[] concat_str;
     }
     else
     {
         cout << "out of range" << endl;
     }
     return *this;
 }
 
 //removes a string at the specified position and inserts the second string at the specified postition
 Mystring& Mystring::replace(size_type start, size_type span, const Mystring& str)
 {
     if(start < len)
     {
         int current_index =0;
          char* concat_str = new char[buf_size];
          
         //hold the contents of our buffer for later use
        strcpy(concat_str, ptr_buffer);
        
        //clears the characters in our string
        delete [] ptr_buffer;
        
        //resize the buffer to hold the new contents of the string
        len += strlen(str.ptr_buffer);
        buf_size = len +1;
        ptr_buffer = new char[buf_size];
        
        //puts the first portion of the original string
        for(int i =0; i<start; i++, current_index++)
        {
            ptr_buffer[i] = concat_str[i];
        }
              
        //adds the contents of the replacement string
        for(int j=0;str.ptr_buffer[j]!='\0';j++,current_index++)
        {
            ptr_buffer[current_index]=str.ptr_buffer[j];
        }
        
        //places the last portion of the original string
        for(int k=start + span; concat_str[k]!='\0';k++,current_index++)
        {
             ptr_buffer[current_index] = concat_str[k];
        }
        
        //removes the content of the temp string
        delete[] concat_str;
     }
     else
     {
         cout << "out of range" << endl;
     }
     return *this;
 }
 
//Replaces the portion of the string that begins at character pos and spans length of  characters 
//c-string version
 Mystring& Mystring::replace(size_type start, size_type span, const char * str)
 {
     if(start < len)
     {
         int current_index =0;
          char* concat_str = new char[buf_size];
          
        strcpy(concat_str, ptr_buffer);
        
        delete [] ptr_buffer;
        
        len += strlen(str);
        buf_size = len +1;
        ptr_buffer = new char[buf_size];
        
        for(int i =0; i<start; i++, current_index++)
        {
            ptr_buffer[i] = concat_str[i];
        }
              
        for(int j=0;str[j]!='\0';j++,current_index++)
        {
            ptr_buffer[current_index]=str[j];
        }
        
        for(int k=start + span; concat_str[k]!='\0';k++,current_index++)
        {
             ptr_buffer[current_index] = concat_str[k];
        }
        
        
        delete[] concat_str;
     }
     else
     {
         cout << "out of range" << endl;
     }
     
     return *this;
 }

 //removes the content in the buffer
 void Mystring::clear()
 {
     delete[] ptr_buffer;
     
     //updates the class values
     len = 0;
     buf_size = len +1;
     ptr_buffer = new char[buf_size];
     ptr_buffer[0]='\0';
 }
 
 //checks if the string is empty
 bool Mystring::empty() const
 {
     if(len >0)
     {
         return false;
     }
     else
     {
         return true;
     }
 }

// Provided for the lab so we may cout mystring
ostream& operator<<(ostream& out, const Mystring& str) 
{
    out << str.c_str();
    return out;
}

// implemented for the lab to support the implementation of <<
const char * Mystring::c_str() const 
{
    return ptr_buffer;
}


// Destructor
Mystring::~Mystring() 
{
    delete [] ptr_buffer;
}
























































































