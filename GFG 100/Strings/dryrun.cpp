#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n=4;
    vector<int> a = {0,1,2,3};
	int b[n][32];
    int r, c = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=31;j>=0;j--)
        {
            int x = a[i];
            int bit = (x >> j)&1;
            b[i][31-j] = bit; 
        }
    }

   for(int i=0;i<31;i++)
   {
       for(int j=0;j<n-1;j++)
       {
           if(b[j][i] != b[j+1][i])
             {
                 //cout<<b[j][i]<<endl<<b[j+1][i];
                 r = j;
                 c = 1;
                 break; 
             }
       }
       if(c == 1)
           break;
   }
   //cout<<endl<<r<<endl<<c;
   int ans = INT_MAX;
   for(int i=0;i<=r;i++)
   {
       for(int j=r+1;j<n;j++)
       {
           ans = min(ans, (a[i] ^ a[j]));
       }
   }
   cout<<ans;
}