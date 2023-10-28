#include<bits/stdc++.h>
using namespace std;

bool good(string s){
	stack <int> sq;
	for(auto it : s){
		if(it == '(' || it == '{' || it =='[')sq.push(it);
		else{
			if(sq.empty())return false;
			char x = sq.top();
			sq.pop();
			if((it == ')' and x == '(') or  (it == ']' and x == '[') or (it == '}' and x == '{')) continue;
			else return false;
		}
	}
	return true;
}

int main(){
	string s="()[{}()]";
    	if(good(s))
    	cout<<"True"<<endl;
    	else
    	cout<<"False"<<endl;
	return 0;
}