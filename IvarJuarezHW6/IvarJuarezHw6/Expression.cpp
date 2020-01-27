
#include <cstdlib>
#include <string>
#include "Expression.h"

using namespace std;

 Expression::Expression()
 {
     //set out default values
     original = "";
     valid = false;
     type = ILLEGAL;
     
 }
 
 Expression::Expression(const string& s)
 {
     //set our default values
     original = s;
     type = ILLEGAL;
     
     //splits the string into tokens
     set(s);
 }
    
void Expression::set(const string& s)
{

    // used to build our token
    string s_token = "";
    //loop through the characters in the string
    //cout << "input string: ";
    for (int i =0; i < s.size(); i++)
    {
        
     
        
        //checks if the character in the string is a not delimiter
        if(delimiters.find_first_of(s[i]) == string::npos)
        {
            //builds our token by adding a character to our string
          s_token += s[i];
        }
        
        //delimiters are mostly non alpha-numeric characters
        //string::npos is a variable in the string class that is used when a character does not match any character in the string
        //checks if the character in the string is a delimiter
        if(delimiters.find_first_of(s[i]) != string::npos)
        {
            
              //checks our token before creating a token object
            if(!s_token.empty())
           {
                //creates a token object
                Token m_token(s_token);
                //display the token's content
                //m_token.display();
                //adds our token to the expression class's tokenized vector
                 tokenized.push_back(m_token);
                

            }
            
           //since the character does is not a delimiter
            
            //convert character s[i] to a string
            //create a token object
            Token token(string(1,s[i]));
            //display token contents
           // token.display();
            
            //insert the token into the tokenized vector
            tokenized.push_back(token);
            
          
            //reset our token string
            s_token = "";
            
            
        }
        
       
        
        if(i == s.size() -1)
        {
            Token m_token(s_token);
                //display the token's content
                //m_token.display();
                //adds our token to the expression class's tokenized vector
                 tokenized.push_back(m_token);
        }
    }

    //cout << endl;

}
    
void Expression::display() const
{
    //Displays the contents of our expression
    
    cout << "original = " << original << endl;
    
    cout << "tokenized = ";
    //prints out each token
    for (int i =0; i < tokenized.size(); i++)
    {
        
        cout  <<  tokenized[i].get_token() << "; ";
        
    }
    cout << endl;
    
    cout << "number of token = " << tokenized.size() << endl;
    
    cout << "postfix = " << endl;
    
    cout << "valid = " << valid << endl;
    
    //prints out the type of expression
    string exp_type ="";
        switch(type)
        {
            case ASSIGNMENT:
                exp_type = "ASSIGNMENT";
                break;
            case ARITHMETIC:
                exp_type = "ARITHMETIC";
                break;
            default:
                exp_type = " ILLEGAL";
                break;
        }
    
    cout << "type = " << exp_type << endl;
    
}
    
string Expression::get_original() const
{
    return original;
}

vector<Token> Expression::get_tokenized() const
{
    return tokenized;
}

Exp_type Expression::get_type() const
    {
        return type;
    }



char* Expression::find_first_in_the_set(char *str, const char *set)
{
    //traverses the char array of our string
    for(int str_index = 0;str[str_index] != '\0';str_index++)
    {
        //traverses the char array of the set
        for(int set_index = 0; set[set_index] != '\0'; set_index++)
        {
            //checks if the current char of our string array matches with the current char 
            //of the set char array
            if(set[set_index] == str[str_index]){
                return &str[str_index];
            }
        }
        
    }
    // if no character matches 
    return nullptr;
}

char* Expression::find_first_not_in_the_set(char *str,const char *set)
{
    bool not_found;
    for (int i = 0; str[i] != '\0'; i++){
        // check to see if str[i] is in set or not
        // if after the loop not_found is true
        // then str[i] is not in set
        not_found = true;
        for (int k = 0; set[k] != '\0'; k++)
            if (str[i] == set[k]) // str[i] in set
                not_found = false; // str[i] is not the one not in set
        if (not_found)
            return &str[i]; //str[i] is the first character not in set
    }
    // each character in str is in set
    return NULL;
}

char* Expression::mystrtok(char *str, const char *delim)
{
     //the word between each delimiter and the null character
    static char* token;
    //gets the next character after the delimiter
    //holds the string that was previously entered
    static char* str_tracker_ptr;
    //tracks when the last token is reached and 
    static bool end_of_string = false;


    char* start_of_token_ptr = nullptr;
    char* end_of_token_ptr = nullptr;
                //a delimiter is not found
    // the token is now terminated by the '\0' character
    if (end_of_string == true)
    {
                     //reset variables
                    str = nullptr;
                    str_tracker_ptr = nullptr;
                    token = nullptr;
                    end_of_string =false;
                    return nullptr;
    }

    //continues from the str that was previously entered
    if (str == nullptr)
    {
                    str = str_tracker_ptr;

    }



    //finds the beginning of the word(token)
    start_of_token_ptr = find_first_not_in_the_set(str, delim);

    //There is no more characters in the string 
    if (start_of_token_ptr == nullptr)
    {
                    return nullptr;

    }

    //finds the end of the word(token)
    end_of_token_ptr = find_first_in_the_set(start_of_token_ptr, delim);
    //There are no delimiters in the string 
    if (end_of_token_ptr != nullptr)
    {
        //sets the token to the beginning of the word(token)    
        token = start_of_token_ptr;
        //"cuts" the token from the rest of the string
        *end_of_token_ptr = '\0';
        //saves the next character after the token and delimiter
        str_tracker_ptr = end_of_token_ptr + 1;


    }
    else {

        //reset variables
        str = nullptr;
        str_tracker_ptr = nullptr;
        token = nullptr;
        end_of_string = true;
        return start_of_token_ptr;
    }



    return token;
}

void check_semicolon(string input)
{
    string str2;
    size_t pos;
    
    for(int i =0; i < input.size(); i++)
    {

     pos = input.find(";");      // 
     if (pos!=std::string::npos)
     {
        str2 = input.substr (i,pos);     // get from "live" to the end
        i=pos;
        cout << str2 << '\n';
     }
    }
}

void Expression::tokenize_expressions(string input)
{
    char * cstr = new char [input.length()+1];
    strcpy (cstr, input.c_str());
    char* pch = nullptr;
    pch = mystrtok (cstr,";");
   
    while (pch != nullptr)
    {
        string expression(pch);
        tokenized_expressions.push_back(expression);
        //printf ("%s\n",pch);
        pch = mystrtok (nullptr, ";");
     
     
    }
}


void Expression::convert_infix_to_postfix()
{
     for (int i =0; i < tokenized.size(); i++)
    {
         if(tokenized[i].get_type() == ID || tokenized[i].get_type() == INT)
         {
             postfix.push_back(tokenized[i]);
         }
         else if(tokenized[i].get_type() == OpenBrace)
         {
             ops.push(tokenized[i]);
         }
         else if(tokenized[i].get_type() == CloseBrace)
         {
             while(ops.top().get_type() != OpenBrace)
             {
                 postfix.push_back(ops.top());
                 ops.pop();
             }
             ops.pop();
             
         }
         else
         {
             while(!ops.empty() && ops.top().get_priority() >= tokenized[i].get_priority())
             {
                 postfix.push_back(ops.top());
                 ops.pop();
             }
             ops.push(tokenized[i]);
         }
    }
     
     while(!ops.empty())
     {
         postfix.push_back(ops.top());
         ops.pop();
     }
}


void Expression::check_syntax()
{
    bool eqtrue = false;
    States state = expect_operand;
    int pcount = 0;
    valid = true;
    int i = 0;
    
    while (state != done && i < tokenized.size())
    {
        
        switch (state)
        {
            case expect_operand:
                
                if (tokenized[i].get_type() == OpenBrace)
                {
                    pcount++;
                }
                else if(tokenized[i].get_type() == INT || tokenized[i].get_type() == ID)
                {
                   state = expect_operator;
                }
                else
                {
                    valid = false;
                    state = done;
                }
                break;
            case expect_operator:
                if(tokenized[i].get_type() == CloseBrace)
                {
                    pcount--;
                    if(pcount < 0)
                    {
                        valid = false;
                        state = done;
                    }
                }
                else if(tokenized[i].get_type() == EQ)
                {
                    eqtrue = true;
                    state = expect_operand;
                }
                else if(tokenized[i].get_type() == OP)
                {
                    state = expect_operand;
                }
                else
                {
                    valid = false;
                    state = done;
                }
                
                break;
            default:
                break;
                        
        }
        i++;
    }
        
        if(pcount != 0)
        {
            valid = false;
        }
        
        if(state == expect_operand)
        {
            valid = false;
        }
        
        if(valid)
        {
            if(eqtrue)
            {
                if(tokenized.size() == 3 && tokenized[0].get_type() == ID && tokenized[2].get_type() == INT)//there is exactly 3 tokens and the first token is ID and third is INT 
                {
                    type = ASSIGNMENT;
                } else 
                {
                    valid = false;
                }
            }
            else
            {
                type = ARITHMETIC;
            }
        }
}

void Expression::convert_infix_to_prefix()
{
   // string infixToPrefix(string infix) 

    /* Reverse String 
     * Replace ( with ) and vice versa 
     * Get Postfix 
     * Reverse Postfix  *  */
    int l = tokenized.size(); 
  
    // Reverse infix 
    reverse(tokenized.begin(), tokenized.end()); 
  
    // Replace ( with ) and vice versa 
    for (int i = 0; i < l; i++) { 
  
        if (tokenized[i].get_type() == OpenBrace) { 
            tokenized[i].set_type(CloseBrace); 
            i++; 
        } 
        else if (tokenized[i].get_type() == CloseBrace) { 
            tokenized[i].set_type(OpenBrace); 
            i++; 
        } 
    } 
    
    if(postfix.empty())
    {
        convert_infix_to_postfix();
    }
    
     for (int i =0; i < postfix.size(); i++)
    {
        prefix.push_back(postfix[i]);
    }
  
  
    // Reverse postfix 
    reverse(prefix.begin(), prefix.end()); 
  
    //return prefix; 

}

string Expression::convert_to_full_parenthesized_expr()
{
     if(postfix.empty())
    {
        convert_infix_to_postfix();
    }
    
     stack<string> s; 
  
    for (int i=0; i < postfix.size(); i++) 
    { 
        // Push operands 
        if (postfix[i].get_type() == OP) 
        { 
            string op1 = s.top(); 
            s.pop(); 
            string op2 = s.top(); 
            s.pop(); 
            s.push("(" + op2 + postfix[i].get_token() + 
                   op1 + ")"); 
          
        } 
        // We assume that input is 
        // a valid postfix and expect 
        // an operator. 
        else
        { 
            string op(postfix[i].get_token()); 
           s.push(op); 
        } 
    } 
  
    // There must be a single element 
    // in stack now which is the required 
    // infix. 
    return s.top(); 
  

}

// Function to find precedence of  
// operators. 
int Expression::precedence(char op){ 
    if(op == '+'||op == '-') 
    return 1; 
    if(op == '*'||op == '/') 
    return 2; 
    return 0; 
} 
  
// Function to perform arithmetic operations. 
int Expression::applyOp(int a, int b, char op){ 
    switch(op){ 
        case '+': return a + b; 
        case '-': return a - b; 
        case '*': return a * b; 
        case '/': return a / b; 
    } 
} 

// Function that returns value of 
// expression after evaluation. 
int Expression::evaluate(){ 
    int i; 
    vector<Token> tokens = tokenized;
      
    // stack to store integer values. 
    stack <int> values; 
      
    // stack to store operators. 
    stack <char> ops; 
      
    for(i = 0; i < tokens.size(); i++){ 
          
        // Current token is a whitespace, 
        // skip it. 
        if(tokens[i].get_token().at(0) == ' ') 
            continue; 
          
        // Current token is an opening  
        // brace, push it to 'ops' 
        else if(tokens[i].get_token().at(0) == '('){ 
            ops.push(tokens[i].get_token().at(0)); 
        } 
          
        // Current token is a number, push  
        // it to stack for numbers. 
        else if(tokens[i].get_type()==INT){ 
            int val = tokens[i].value(); 
              
            values.push(val); 
        } 
          
        // Closing brace encountered, solve  
        // entire brace. 
        else if(tokens[i].get_token().at(0) == ')') 
        { 
            while(!ops.empty() && ops.top() != '(') 
            { 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                  
                values.push(applyOp(val1, val2, op)); 
            } 
              
            // pop opening brace. 
            if(!ops.empty()) 
               ops.pop(); 
        } 
          
        // Current token is an operator. 
        else
        { 
            // While top of 'ops' has same or greater  
            // precedence to current token, which 
            // is an operator. Apply operator on top  
            // of 'ops' to top two elements in values stack. 
            while(!ops.empty() && precedence(ops.top()) 
                                >= precedence(tokens[i].get_token().at(0))){ 
                int val2 = values.top(); 
                values.pop(); 
                  
                int val1 = values.top(); 
                values.pop(); 
                  
                char op = ops.top(); 
                ops.pop(); 
                  
                values.push(applyOp(val1, val2, op)); 
            } 
              
            // Push current token to 'ops'. 
            ops.push(tokens[i].get_token().at(0)); 
        } 
    } 
      
    // Entire expression has been parsed at this 
    // point, apply remaining ops to remaining 
    // values. 
    while(!ops.empty()){ 
        int val2 = values.top(); 
        values.pop(); 
                  
        int val1 = values.top(); 
        values.pop(); 
                  
        char op = ops.top(); 
        ops.pop(); 
                  
        values.push(applyOp(val1, val2, op)); 
    } 
      
    // Top of 'values' contains result, return it. 
    return values.top(); 
} 




void Expression::displayPostfix()
{
    cout << "postfix of "<< original << " is: ";
    for (int i =0; i < postfix.size(); i++)
    {
        cout  <<  postfix[i].get_token() << "  ";
    }
    cout << endl;
}


void Expression::displayPostfixError()
{
    if(valid == false)
    cout << "no postfix of "<< original << " which is an invalid expression. ";
   
    cout << endl;
}

void Expression::displayPrefix()
{
    cout << "prefix of "<< original << " is: ";
    for (int i =0; i < prefix.size(); i++)
    {
        cout  <<  prefix[i].get_token() << "  ";
    }
    cout << endl;
}

void Expression::displayPrefixError()
{
     if(valid == false)
    cout << "no prefix of "<< original << " which is an invalid expression. ";
    
    cout << endl;
}

void Expression::displayFullExpr()
{
    if(valid == true)
    {
        cout << "fully parenthesizing of "<< original << " is: "<< convert_to_full_parenthesized_expr() << endl;
    }
    else
    {
         cout << "no fully parenthesizing of "<< original << " which is an invalid expression. " << endl;
    }
        
}

void Expression::displayTokenized()
{
     cout << "tokenized: ";
    for (int i =0; i < tokenized.size(); i++)
    {
        cout  <<  tokenized[i].get_token() << ", ";
    }
     cout << endl;
}

void Expression::clear()
{
    postfix.clear();
    prefix.clear();
    tokenized.clear();
    tokenized_expressions.clear();
}

bool Expression::is_valid() const
{
    return valid;
}
bool Expression::containsVariables() 
{
    bool has_vars = false;
     for (int i =0; i < tokenized.size(); i++)
    {
          if(tokenized[i].get_type()==ID)
          {
              has_vars = true;
          }
    }
    return has_vars;
}

bool Expression::substituteVariablesWithValues(SymbolTable st)
{
    bool is_substituted = false;
  
    for (int i =0; i < tokenized.size(); i++)
    {
        if(tokenized[i].get_type()==ID)
        {
              if(st.find(tokenized[i].get_token())=="local")
              {
                  //finds the value of the token in symbol table
                  int* value = st.getValue(tokenized[i].get_token());
                  int val = *value;

                  tokenized[i].set(std::to_string(val));//substitute the value as the token
                  is_substituted = true;
              }
              else
              {
                  return false;
              }
        }
    }
    
   
    return is_substituted;
}











































































































