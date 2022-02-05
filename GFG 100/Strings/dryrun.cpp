#include<bits/stdc++.h>

using namespace std;
void reverseRows(vector<vector<int>> &mat)
    {
        for(int i=0;i<mat.size();i++)
        {
            reverse(mat[i].begin(),mat[i].end());
        }
    }
    
void reverseCols(vector<vector<int>> &mat)
    {
        for(int i=0;i<mat[0].size();i++)
        {
            int j=0;
            int k=mat.size()-1;
            
            while(j<k)
            {
            //  int temp = mat[j][i];
            //  mat[j][i] = mat[k][i];
            //  mat[k][i]=temp;
            
                swap(mat[j++][i],mat[k--][i]);
            }
        }
    }

int main()
{

    vector<vector<int>> mat = 
    {
      
    {1,  2,  3},
    {5,  6,  7},
    {9,  10, 11},

    };   
        reverseRows(mat);
        reverseCols(mat);

        for(auto r:mat)
        {
            for(auto c:r)
            {
                cout<<c<<" ";
            }
            cout<<endl;
        }
}