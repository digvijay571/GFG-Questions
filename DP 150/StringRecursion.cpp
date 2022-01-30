#include<bits/stdc++.h>

using namespace std;
//Q1 Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/submissions/
void generateParentheses(int open,int close,string &s,int n)
{
	//Base case
	if(open==n && close==n){
		cout<<s<<endl;
	}

	if(open<n)
	{
		s.push_back('(');
		generateParentheses(open+1,close,s,n);
		s.pop_back();
	}
	if(open>close)
	{
		s.push_back(')');
		generateParentheses(open,close+1,s,n);
		s.pop_back();
	}
}

int main()
{
	string s="";
	generateParentheses(0,0,s,3);
}