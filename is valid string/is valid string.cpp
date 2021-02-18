#include<iostream>
using namespace std;
/*
This function will check if the given string is 
from the grammer 'a', 'a*b+', 'abb'.
'a' - a
'a*b+' - 0+ a's and 1+ b's
'aab' - aab 
*/
bool isValidString(string s){
    int len = s.length(),countA=0,countB=0,i=0;
	/*
		we can iterate through the string.
		in the next while loops we'll check if string contain language a^n.b^m
		we'll keep count of number of a's and b's 
	*/
    while(i < len){
    	if(s[i] == 'a')countA++;
		else break;
		i++;
	}
	while(i < len){
    	if(s[i] == 'b')countB++;
		else return false;
		i++;
	}
	/*
	we have only three productions to check 
	we're checking them one by one.
	*/
	if(countA==1 && countB==0)	return true;//case 1.
	else if(countA==2 && countB==1)	return true;//case 3.
	else if(countB==0) return false; //other cases.
	return true;	//case 2.
}

/*Driver Code
user needs to give the number of times(t) he want to run the code.
for each t he/she needs to input the string to be checked.
*/
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		if(isValidString(s)){
			cout<<"accepted"<<endl;
		}else{
			cout<<"not accepted"<<endl;
		}
	}
}
