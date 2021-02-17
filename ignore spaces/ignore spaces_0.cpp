//Design a lexical analyzer for given language and the lexical analyzer should ignore redundant spaces, tabs and new lines. 
//It should also ignore comments. Although the syntax specification states that identifiers can be arbitrarily long, 
//you may restrict the length to some reasonable value.

#include<bits/stdc++.h>
using namespace std;

//Removes redundant spaces, tabs and new lines. '_s' is the passed in string
void RemoveRedundant(string _s)
{
    //adds all code after removing redundant
    string code;
    
    //determines prev char to determine next char
    enum LastChar
    {
        None,
        Space,
        Token,
        String
    };

    LastChar lastChar = LastChar::None;

    //loop through the file/string.
    for (auto ch = _s.begin(); ch != _s.end(); ch++)
    {
        //if last char type was none, there should not be any more redundant tab, space or new line
        if(lastChar == LastChar::None)
        {
            if(!(*ch == ' ' || *ch == '\t' || *ch == '\n'))
            {
                code += *ch;
                lastChar = LastChar::Token;
            }
        }
        //if last char type was space, there should not be any more redundant tab, space or new line
        else if(lastChar == LastChar::Space)
        {
            if(!(*ch == ' ' || *ch == '\t' || *ch == '\n'))
            {
                code += *ch;
                if(*ch == '\"')
                {
                    lastChar = LastChar::String;
                }
                else
                {
                    lastChar = LastChar::Token;
                }
            }
        }
        //if last char type was token, there should not be any more redundant tab, space or new line
        else if(lastChar == LastChar::Token)
        {
            if(!(*ch == ' ' || *ch == '\t' || *ch == '\n'))
            {
                code += *ch;
                if(*ch == '\"')
                {
                    lastChar = LastChar::String;
                }
                else
                {
                    lastChar = LastChar::Token;
                }
            }
            else
            {
                code += ' ';
                lastChar = LastChar::Space;
            }
        }
        //if last char type was space, add everything to code.
        else if(lastChar == LastChar::String)
        {
            code += *ch;
            if(*ch == '\"')
            {
                lastChar = LastChar::None;
            }
        }
    }
    cout<<"__CODE__\n"<<code;
}
//driver code and string to be handled
int main()
{
    //s can be initialised/replaced with file.
    string s = "\n\tint v[3] = {10, 100,   200};\n\n \n\t \n int *ptr;   string s = \"hello   \tworld\"        int x = a / b;";

    RemoveRedundant(s);

    return 0;
}