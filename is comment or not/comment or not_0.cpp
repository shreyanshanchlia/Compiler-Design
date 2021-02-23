//Write a program to identify whether a given line is a comment or not

#include<bits/stdc++.h>
using namespace std;

//Remove comments from string s
void RemoveComments(string _s)
{
    //split s into code and comments
    string code;
    string comment;

    //determines prev char to determine next char
    enum CommentType
    {
        None,
        slash,
        SingleLine,
        MultiLineEnd,
        MultiLine
    };
    CommentType Current = CommentType::None;
    
    //loop through the file/string.
    for (auto ch = _s.begin(); ch != _s.end(); ch++)
    {
        if(Current != CommentType::SingleLine && Current != CommentType::MultiLine && Current != CommentType::MultiLineEnd)
        {
            //if not in a comment, and encounter a '/', change Current to slash as it could be a new comment
            if(*ch == '/')
            {
                //if Current was slash, new / starts a single line comment
                if(Current == CommentType::slash)
                {
                    Current = CommentType::SingleLine;
                    code.pop_back();
                }
                else
                    code += *ch;
                if(Current == CommentType::None)
                {
                    Current = CommentType::slash;
                }
            }
            //detect if it could be start of new multi-line comment
            else if(*ch == '*')
            {
                //if it was slash, new * starts a multi line comment
                if(Current == CommentType::slash)
                {
                    Current = CommentType::MultiLine;
                    code.pop_back();
                }
                else
                    code += *ch;
            }
            else
                code += *ch;
        }
        //if already in a single line comment '\n' can break the comment
        else if (Current == CommentType::SingleLine)
        {
            if(*ch == '\n')
            {
                Current = CommentType::None;
            }
            comment += *ch;
        }
        //if in multi line end, '/' can break the comment
        else if (Current == CommentType::MultiLineEnd)
        {
            if(*ch == '/')
            {
                Current = CommentType::None;
                comment.pop_back();
            }
            else
                comment += *ch;
        }
        else //if (Current == CommentType::MultiLine)
        {
            //encountered * could be the end of multi-line comment if / follows
            if(*ch == '*')
            {
                comment += *ch;
                Current = CommentType::MultiLineEnd;
            }
            else
                comment += *ch;
        }
    }
    //print code and comments
    cout<<"__code__\n"<<code<<endl<<endl;
    cout<<"__comment__\n"<<comment;
}
//driver code and string to be handled
int main()
{
    //s can be initialised/replaced with file.
    string s = "// Declare an array \n int v[3] = {10, 100, 200};/* declared **/ \n// Declare pointer variable \n int *ptr; int x = a / b;";

    RemoveComments(s);

    return 0;
}