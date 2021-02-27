#include<iostream>
#include <string> 

using namespace std;

/*
	This function checks if the current token is a operator or not
	this can be checked by an amazing obervation about operators.
	operators are mostly of length 1 or 2.
	lets consider others as the special case.
*/
bool isValidOperator(string s){
	int n = s.length();		//calculating length of the operator
	/*
	the special case operators.
	*/
	if(s=="sizeof()"||s=="<<="||s==">>=")return true; 
	/*
	operators with length 1.
	*/
	if(n==1){
		switch(s[0]){	//designed fall-through to give true in all cases.
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
			case '~':
			case '!':
			case '<':
			case '>':
			case '|':
			case '&':
			case '=':	return true;
			default: return false;			
		}	
	/*
	operators with lenght 2.
	*/
	}else if(n==2){
		switch(s[1]){	//checking backwars i.e. second character first and then first character. It makes our code more readable and short.
			case'+':
				if(s[0]=='+') return true;
				else return false;
			case'-':
				if(s[0]=='-') return true;
				else return false;
			case'<':
				if(s[0]=='<') return true;
				else return false;
			case'>':
				if(s[0]=='>') return true;
				else return false;
			case'&':
				if(s[0]=='&') return true;
				else return false;
			case'|':
				if(s[0]=='|') return true;
				else return false;
			case'=':
				switch(s[0]){	//designed fall-through to give true in all cases.
					case'+':
					case'-':
					case'*':
					case'/':
					case'%':
					case'^':
					case'&':
					case'|':
					case'<':
					case'>':
					case'=':
					case'!':	return true;
					default: 	return false;
				}
			default: return false;
		}	
	/*
	other tokens with other length
	*/
	}else if(n>2) return false;
}

int main(){
	//driver code
	string s;
	int t;		//inputs an intiger that describes how much token you want to check.
	cin>>t;
	while(t--){
		cin>>s;		//inouts a string (token) which is claimed to be operator.
		if(isValidOperator(s)){
			cout<<"accepted"<<endl;
		}else{
			cout<<"not accepted"<<endl;
		}
	}
}
