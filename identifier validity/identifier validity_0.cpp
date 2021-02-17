#include<iostream>
#include <string> 
#include <map> 
using namespace std;

/*
This function takes a string token and try to check all the rules for declaring identifiers.
R1. identifier should not be a keyword.
R2. first letter of the identifier should be in set of either a english letter or '_'(underscore).
R3. other characters can be in a set of english letters + underscore(_) + digits.
*/
bool isValidIdentifier(string s, map<string, bool> &keys){	//if keywords are provided 
	int n = s.length();
	
	/*
	checking for the keyword matching
	*/	
	if(keys.find(s) != keys.end() && keys[s] == true){
		return false;
	}
	
	/*
	checking for the first letter rule
	*/
	if(s[0]=='_' || (s[0]>='a'&&s[0]<='z') || (s[0]>='A'&&s[0]<='Z')){
		for(int i=1; i<n; i++){
			/*
			checking for the rest of the character of the token
			*/
			if(s[i]=='_' || (s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z') || (s[i]>='0'&&s[i]<='9')){
				continue;
			}else{
				return false;
			}
		}
		return true;
	}
	return false;
}

/*
this is overload of the above function
this function is valid when we do not have any keyword list
*/
bool isValidIdentifier(string s){
	int n = s.length();
	if(s[0]=='_' || (s[0]>='a'&&s[0]<='z') || (s[0]>='A'&&s[0]<='Z')){
		for(int i=1; i<n; i++){
			if(s[i]=='_' || (s[i]>='a'&&s[i]<='z') || (s[i]>='A'&&s[i]<='Z') || (s[i]>='0'&&s[i]<='9')){
				continue;
			}else{
				return false;
			}
		}
		return true;
	}
	return false;
}

//driver code
int main(){
	map<string, bool> keys;	
	/*
	it saves all the keywords. for some reason if we have to assume any of these string, not as a keyword 
	then we can simply set their value to false
	*/
	
	keys.insert({"auto",true});
	keys.insert({"break",true});
	keys.insert({"case",true});
	keys.insert({"char",true});
	keys.insert({"const",true});
	keys.insert({"continue",true});
	keys.insert({"default",true});
	keys.insert({"do",true});
	keys.insert({"double",true});
	keys.insert({"else",true});
	keys.insert({"enum",true});
	keys.insert({"extern",true});
	keys.insert({"float",true});
	keys.insert({"for",true});
	keys.insert({"goto",true});
	keys.insert({"if",true});
	keys.insert({"int",true});
	keys.insert({"long",true});
	keys.insert({"register",true});
	keys.insert({"return",true});
	keys.insert({"short",true});
	keys.insert({"signed",true});
	keys.insert({"sizeof",true});
	keys.insert({"static",true});
	keys.insert({"struct",true});
	keys.insert({"switch",true});
	keys.insert({"typedef",true});
	keys.insert({"union",true});
	keys.insert({"unsigned",true});
	keys.insert({"void",true});
	keys.insert({"volatile",true});
	keys.insert({"while",true});
	
	/*
	t is the test cases. it desribes how many token you want to check
	*/
	int t;
	cin>>t;		
	cin.ignore();
	while(t--)
	{
		string s;
		/*
		s is the token to be checked for identifier
		*/
		getline(cin, s);
		if(isValidIdentifier(s, keys)){
			cout<<"accepted"<<endl;
		}else{
			cout<<"not accepted"<<endl;
		}
	}
}
