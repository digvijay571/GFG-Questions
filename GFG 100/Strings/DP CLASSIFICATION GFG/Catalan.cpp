 

//Number of Unique BST
https://leetcode.com/problems/unique-binary-search-trees/

class Solution {
public:
 
    int catalan(int n,vector<int>& dp)
    {
        if(n<=1) return 1;//n==0 aur n==1 are genral base cases:miskate happed if wrote n==1 return 1
        
        if(dp[n] !=-1) return dp[n];
        //n nodes of unique values from 1 to n. i as a root
        //choices for root i.e.  1 to n
        int count = 0;
        for(int i=0;i<n;i++)//loop for choices to select the root node 
        {   //problem can be broken into subprolem if we have selected a root:
            //if we know the count of unique BST's for left subTree 
            //if we know the count of unique BST's for right subTree 
            //count for unique BST's with current root=left_count*right_count
            
            int leftSubTree_count = catalan(i,dp);//( number of unique BST's which has i nodes )( i-0 ,nodes which are on leftsubtree of current root)
            int rightSubTree_count = catalan(n-i-1,dp);//(n-1-i,nodes which are on rightleft of current root )
            count +=leftSubTree_count*rightSubTree_count;//root fix, ek left ke liye right ko rightSubTree_count ways me arrange kar sakte
                                                        //so total = leftSubTree_count multiply rightSubTree_count
        }
        
          return dp[n]=count; 
    }
    int numTrees(int n) 
    {
      vector<int> dp(n+1,-1);
      return  catalan(n,dp);
        
    }
};

// https://practice.geeksforgeeks.org/problems/handshakes1303/1

class Solution{
public:

    int handshakes(int N,vector<int>& dp)
    {
        if(N%2 != 0) return 0;//odd persons return zero
        if(N==0) return 1;
        
        if(dp[N] != -1 ) return dp[N];
        int count=0;
        for(int i=0;i<N;i+=2)//choices to hand shake ..we fixed a person and it has 0 to n-1 person choices to hand shake
        {
            int oneside_count = handshakes(i,dp);
            int rightside_count = handshakes(N-i-2,dp);
            
            count+=oneside_count*rightside_count;//multiply 
        }
        
        return dp[N] = count;
    }
    int count(int N){
        // code here
        vector<int> dp(N+1,-1);
        return handshakes(N,dp);
    }
};