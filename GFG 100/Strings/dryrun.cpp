#include<bits/stdc++.h>

using namespace std;
void printDuplicates(string &s)
{
    unordered_map<char,int> fmp;

    for(auto c:s)fmp[c]++;

    for(auto p:fmp)
    {
        if(p.second>1)
        cout<<p.first;
    }
}

int main()
{
	string s="habcdelloo";
	printDuplicates(s);
}