#include<bits/stdc++.h>

using namespace std;


vector<pair<int,int>>  moves={{1,1},{-1,-1},{1,-1},{-1,1}};

int dfs(int i,int j,int ic,int jc)//i
{
    if(i<0||j<0||i>=8||j>=8)
    return 0;
	
	cout<<i<<j<<endl;
    return (1+dfs(i+ic,j+jc,ic,jc));
}
int main()
{
	int A, B;
    cin>>A>>B;
	--A,--B;
    int count=0;

    for(auto move:moves)
    {
       // cout<<dfs(A,B,move.first,move.second)<<endl;
    	cout<<"call1"<<" ";
       count+= dfs(A,B,move.first,move.second);
    }
    cout<<" "<<count<<endl;
    return count-3;
}